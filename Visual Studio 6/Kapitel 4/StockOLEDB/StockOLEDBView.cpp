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
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
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
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

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
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
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
			// Deaktivieren der Datensatzbefehle Nächster und Vorheriger,
			// da der Versuch, den aktuellen Datensatz ohne geöffnetes RecordSet
			// zu ändern, verursacht einen Absturz.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}

   // Werte in die Ansicht übernehmen
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
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CStockOLEDBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
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

CStockOLEDBDoc* CStockOLEDBView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockOLEDBDoc)));
	return (CStockOLEDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBView Datenbankunterstützung
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
   // Daten zurückschreiben
   strcpy (m_pSet->m_Aktienname, m_strShareName);
   strcpy (m_pSet->m_Tickersymbol, m_strTicker);
   m_pSet->m_WKN = m_nShareID;
	
   // Move durchführen
	BOOL bMoveResult = COleDBRecordView::OnMove(nIDMoveCommand);

   if (bMoveResult) {
      // neue Daten holen
      m_strShareName = m_pSet->m_Aktienname;
      m_strTicker    = m_pSet->m_Tickersymbol;
      m_nShareID     = m_pSet->m_WKN;
      m_nShareNo     = m_pSet->m_Aktiennummer;
      // Daten in die Ansicht übernehmen
      UpdateData (false);
   }
   
   return bMoveResult;
}
