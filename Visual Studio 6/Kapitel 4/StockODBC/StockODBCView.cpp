// StockODBCView.cpp : Implementierung der Klasse CStockODBCView
//

#include "stdafx.h"
#include "StockODBC.h"

#include "StockODBCSet.h"
#include "StockODBCDoc.h"
#include "StockODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockODBCView

IMPLEMENT_DYNCREATE(CStockODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CStockODBCView, CRecordView)
	//{{AFX_MSG_MAP(CStockODBCView)
	ON_COMMAND(ID_RECORD_NEW, OnRecordNew)
	ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockODBCView Konstruktion/Destruktion

CStockODBCView::CStockODBCView()
	: CRecordView(CStockODBCView::IDD)
{
	//{{AFX_DATA_INIT(CStockODBCView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	m_bNewRecord = false;
}

CStockODBCView::~CStockODBCView()
{
}

void CStockODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockODBCView)
	DDX_FieldText(pDX, IDC_EDIT_STOCKNAME, m_pSet->m_Aktienname, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_TICKER, m_pSet->m_Tickersymbol, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_WKN, m_pSet->m_WKN, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_STOCKNO, m_pSet->m_Aktiennummer, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CStockODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CRecordView::PreCreateWindow(cs);
}

void CStockODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_stockODBCSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CStockODBCView Diagnose

#ifdef _DEBUG
void CStockODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CStockODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CStockODBCDoc* CStockODBCView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockODBCDoc)));
	return (CStockODBCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockODBCView Datenbankunterstützung
CRecordset* CStockODBCView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CStockODBCView Nachrichten-Handler

void CStockODBCView::OnRecordNew() 
{
   // Satzgruppe besorgen:
	CStockODBCSet* pSet = (CStockODBCSet*)OnGetRecordset();
   
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
   pSet->m_WKN          = 0;

   // Neuen Datensatz vormerken:
   m_bNewRecord = true;

   // Daten in die Ansicht schreiben:
   UpdateData (false);
}

void CStockODBCView::OnRecordDelete() 
{
   // Datensatz besorgen
	CRecordset* pSet = OnGetRecordset();


   if (pSet->CanUpdate() && // kann ändern
       !pSet->IsBOF ())     // Ist nicht leer
      pSet->Delete();
   else
      return;

   if (pSet->CanRestart())
      pSet->Requery();  // neu einlesen

   UpdateData (false);
}

BOOL CStockODBCView::OnMove(UINT nIDMoveCommand) 
{
   if (m_bNewRecord)
   {
      // Satzgruppe besorgen:
	   CStockODBCSet* pSet = (CStockODBCSet*)OnGetRecordset();
      
      CString strShareName, strTicker;
      int nWKN;
      
      // Daten aus der Ansicht holen
      UpdateData();
      
      // Werte sichern
      strShareName = pSet->m_Aktienname;
      strTicker    = pSet->m_Tickersymbol;
      nWKN         = pSet->m_WKN;
      
      // Datensatz erzeugen:
      pSet->AddNew();
      
      // Daten zuweisen:
      pSet->m_Aktienname   = strShareName;
      pSet->m_Tickersymbol = strTicker;
      pSet->m_WKN          = nWKN;   

      // Und zurückschreiben:
      pSet->Update();

      if (pSet->CanRestart())
      {
         pSet->Requery();

         // Auf (vermutlich) neuen Datensatz positionieren:
         pSet->MoveLast();
      }

      m_bNewRecord = false;

      // Mit Ansicht abgleichen:
      UpdateData (false);
	}

	return CRecordView::OnMove(nIDMoveCommand);
}
