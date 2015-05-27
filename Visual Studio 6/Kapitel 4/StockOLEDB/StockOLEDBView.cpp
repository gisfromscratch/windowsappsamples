// StockOLEDBView.cpp : Implementierung der Klasse CStockOLEDBView
//

#include "stdafx.h"
#include "StockOLEDB.h"

#include "StockOLEDBSet.h"
#include "StockOLEDBDoc.h"
#include "StockOLEDBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView

IMPLEMENT_DYNCREATE(CStockOLEDBView, COleDBRecordView)

BEGIN_MESSAGE_MAP(CStockOLEDBView, COleDBRecordView)
	//{{AFX_MSG_MAP(CStockOLEDBView)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, COleDBRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Konstruktion/Destruktion

CStockOLEDBView::CStockOLEDBView()
	: COleDBRecordView(CStockOLEDBView::IDD)
{
	//{{AFX_DATA_INIT(CStockOLEDBView)
	m_pSet = NULL;
	m_strShareName = _T("");
	m_nShareNo = 0;
	m_strTicker = _T("");
	m_nShareID = 0;
	//}}AFX_DATA_INIT
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einf�gen,

}

CStockOLEDBView::~CStockOLEDBView()
{
}

void CStockOLEDBView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockOLEDBView)
	DDX_Text(pDX, IDC_EDIT_SHARENAME, m_strShareName);
	DDX_Text(pDX, IDC_EDIT_SHARENO, m_nShareNo);
	DDX_Text(pDX, IDC_EDIT_TICKER, m_strTicker);
	DDX_Text(pDX, IDC_EDIT_WKN, m_nShareID);
	DDV_MinMaxLong(pDX, m_nShareID, 0, 999999);
	//}}AFX_DATA_MAP
}

BOOL CStockOLEDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: �ndern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return COleDBRecordView::PreCreateWindow(cs);
}

void CStockOLEDBView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_stockOLEDBSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Deaktivieren der Datensatzbefehle N�chster und Vorheriger,
			// da der Versuch, den aktuellen Datensatz ohne ge�ffnetes RecordSet
			// zu �ndern, verursacht einen Absturz.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}

   // Werte in die Ansicht �bernehmen
   m_strShareName = m_pSet->m_Aktienname;
   m_nShareNo     = m_pSet->m_Aktiennummer;
   m_nShareID     = m_pSet->m_WKN;
   m_strTicker    = m_pSet->m_Tickersymbol;

	COleDBRecordView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Drucken

BOOL CStockOLEDBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CStockOLEDBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zus�tzliche Initialisierung vor dem Drucken hier einf�gen
}

void CStockOLEDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einf�gen
}

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Diagnose

#ifdef _DEBUG
void CStockOLEDBView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void CStockOLEDBView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

CStockOLEDBDoc* CStockOLEDBView::GetDocument() // Die endg�ltige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockOLEDBDoc)));
	return (CStockOLEDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Datenbankunterst�tzung
CRowset* CStockOLEDBView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Nachrichten-Handler

BOOL CStockOLEDBView::OnMove(UINT nIDMoveCommand) 
{
	// Daten aus der Ansicht holen
   UpdateData ();
   // Daten zur�ckschreiben
   strcpy (m_pSet->m_Aktienname, m_strShareName);
   strcpy (m_pSet->m_Tickersymbol, m_strTicker);
   m_pSet->m_WKN = m_nShareID;
	
   // Move durchf�hren
	BOOL bMoveResult = COleDBRecordView::OnMove(nIDMoveCommand);

   if (bMoveResult) {
      // neue Daten holen
      m_strShareName = m_pSet->m_Aktienname;
      m_strTicker    = m_pSet->m_Tickersymbol;
      m_nShareID     = m_pSet->m_WKN;
      m_nShareNo     = m_pSet->m_Aktiennummer;
      // Daten in die Ansicht �bernehmen
      UpdateData (false);
   }
   
   return bMoveResult;
}
