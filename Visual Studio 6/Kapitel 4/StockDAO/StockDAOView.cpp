// StockDAOView.cpp : Implementierung der Klasse CStockDAOView
//

#include "stdafx.h"
#include "StockDAO.h"

#include "StockDAOSet.h"
#include "StockDAODoc.h"
#include "StockDAOView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockDAOView

IMPLEMENT_DYNCREATE(CStockDAOView, CDaoRecordView)

BEGIN_MESSAGE_MAP(CStockDAOView, CDaoRecordView)
	//{{AFX_MSG_MAP(CStockDAOView)
	ON_COMMAND(ID_RECORD_NEW, OnRecordNew)
	ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CDaoRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CDaoRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CDaoRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockDAOView Konstruktion/Destruktion

CStockDAOView::CStockDAOView()
	: CDaoRecordView(CStockDAOView::IDD)
{
	//{{AFX_DATA_INIT(CStockDAOView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
   m_bNewRecord = false;
}

CStockDAOView::~CStockDAOView()
{
}

void CStockDAOView::DoDataExchange(CDataExchange* pDX)
{
	CDaoRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockDAOView)
	DDX_FieldText(pDX, IDC_EDIT_STOCKNAME, m_pSet->m_Aktienname, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_STOCKNO, m_pSet->m_Aktiennummer, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_TICKER, m_pSet->m_Tickersymbol, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_WKN, m_pSet->m_WKN, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CStockDAOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CDaoRecordView::PreCreateWindow(cs);
}

void CStockDAOView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_stockDAOSet;
	CDaoRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CStockDAOView Drucken

BOOL CStockDAOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CStockDAOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CStockDAOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
}

/////////////////////////////////////////////////////////////////////////////
// CStockDAOView Diagnose

#ifdef _DEBUG
void CStockDAOView::AssertValid() const
{
	CDaoRecordView::AssertValid();
}

void CStockDAOView::Dump(CDumpContext& dc) const
{
	CDaoRecordView::Dump(dc);
}

CStockDAODoc* CStockDAOView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockDAODoc)));
	return (CStockDAODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockDAOView Datenbankunterstützung
CDaoRecordset* CStockDAOView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CStockDAOView Nachrichten-Handler

void CStockDAOView::OnRecordNew() 
{
   // Satzgruppe besorgen:
	CStockDAOSet* pSet = (CStockDAOSet*)OnGetRecordset();

   // Wenn Änderungen am aktuellen Datensatz gemacht 
   // wurden, diesen erst sichern:
   if ( pSet->CanUpdate() &&  // Kann ändern
       !pSet->IsBOF()     &&  // Ist nicht leer
       !pSet->IsDeleted())    // Datensatz nicht gelöscht
   { 
      // Ändern:
      pSet->Edit();
      // Daten aus der Ansicht holen:
      UpdateData();
      // Und zurückschreiben:
      pSet->Update();
   }

   // Leerer Datensatz:
   pSet->m_Aktienname   = _T("");
   pSet->m_Aktiennummer = -1;
   pSet->m_Tickersymbol = _T("");
   pSet->m_WKN = 0;

   // Neuen Datensatz vormerken:
   m_bNewRecord = true;

   // Daten in die Ansicht schreiben:
   UpdateData (false);
}


void CStockDAOView::OnRecordDelete() 
{
   // Datensatz besorgen:
	CDaoRecordset* pSet = OnGetRecordset();

   if (pSet->CanUpdate() && // kann ändern
       !pSet->IsBOF ())     // Ist nicht leer
      // Datensatz löschen:
      pSet->Delete ();
   else
      return;

   if (pSet->CanRestart())
      // Neu einlesen:
      pSet->Requery ();

   // aktuellen Satz in Ansicht übernehmen
   UpdateData (false);
}


BOOL CStockDAOView::OnMove(UINT nIDMoveCommand) 
{
   // Datensatz besorgen
	CStockDAOSet* pSet = (CStockDAOSet*)OnGetRecordset();

	if (m_bNewRecord)
   {
		CString strShareName, strTicker;
      int nWKN;

      // Daten aus der Ansicht holen
      UpdateData();

      // Werte sichern
      strShareName = pSet->m_Aktienname;
      strTicker    = pSet->m_Tickersymbol;
      nWKN         = pSet->m_WKN;

      // Datensatz erzeugen:
      pSet->AddNew ();

      // Daten zuweisen:
      pSet->m_Aktienname   = strShareName;
      pSet->m_Tickersymbol = strTicker;
      pSet->m_WKN          = nWKN;

      // und zurückschreiben  
		pSet->Update();

      if (pSet->CanRestart())
      {
         pSet->Requery ();

         // auf (vermutlich) neuen Datensatz positionieren:
         pSet->MoveLast ();
      }

      m_bNewRecord = false;

      // Mit Ansicht abgleichen:
      UpdateData (false);
   }

   return CDaoRecordView::OnMove(nIDMoveCommand);
}

