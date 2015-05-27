// StockBrowserView.cpp : Implementierung der Klasse CStockBrowserView
//

#include "stdafx.h"
#include "StockBrowser.h"

#include "StockBrowserDoc.h"
#include "StockBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView

IMPLEMENT_DYNCREATE(CStockBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CStockBrowserView, CHtmlView)
	ON_COMMAND(ID_EDIT_RELOAD, OnEditReload)
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView Konstruktion/Destruktion

CStockBrowserView::CStockBrowserView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CStockBrowserView::~CStockBrowserView()
{
}

BOOL CStockBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView Zeichnen

void CStockBrowserView::OnDraw(CDC* pDC)
{
	CStockBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// ZU ERLEDIGEN: Hier Code zum Zeichnen der ursprünglichen Daten hinzufügen
}

void CStockBrowserView::OnInitialUpdate()
{
	CStockBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CHtmlView::OnInitialUpdate();

   // URL des Dokuments anzeigen
   Navigate2 (pDoc->GetURL ());
}

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView Drucken


/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView Diagnose

#ifdef _DEBUG
void CStockBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CStockBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CStockBrowserDoc* CStockBrowserView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockBrowserDoc)));
	return (CStockBrowserDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserView message handlers


void CStockBrowserView::NavigateURL ()
{
	CStockBrowserDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   Navigate2 (pDoc->GetURL ());
}


void CStockBrowserView::OnEditReload() 
{
	Refresh ();
}

