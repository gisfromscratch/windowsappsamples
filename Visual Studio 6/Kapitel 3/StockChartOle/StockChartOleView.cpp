// StockChartOleView.cpp : Implementierung der Klasse CStockChartOleView
//

#include "stdafx.h"
#include "StockChartOle.h"

#include "StockChartOleDoc.h"
#include "StockChartOleView.h"

#include "DrawFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView

IMPLEMENT_DYNCREATE(CStockChartOleView, CView)

BEGIN_MESSAGE_MAP(CStockChartOleView, CView)
	//{{AFX_MSG_MAP(CStockChartOleView)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView Konstruktion/Destruktion

CStockChartOleView::CStockChartOleView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CStockChartOleView::~CStockChartOleView()
{
}

BOOL CStockChartOleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView Zeichnen

void CStockChartOleView::OnDraw(CDC* pDC)
{
	CStockChartOleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   // Drawfunktion wurde ausgelagert
   ::Draw (pDC, pDoc, 10000);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView Drucken

BOOL CStockChartOleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CStockChartOleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CStockChartOleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
}

/////////////////////////////////////////////////////////////////////////////
// OLE-Server-Unterstützung

// Der folgende Befehls-Handler stellt die Standardtastatur als
//  Benutzerschnittstelle zum Abbruch der direkten Bearbeitungssitzung zur Verfügung. Hier
//  verursacht der Container (nicht der Server) die Deaktivierung.
void CStockChartOleView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView Diagnose

#ifdef _DEBUG
void CStockChartOleView::AssertValid() const
{
	CView::AssertValid();
}

void CStockChartOleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStockChartOleDoc* CStockChartOleView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockChartOleDoc)));
	return (CStockChartOleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleView Nachrichten-Handler

void CStockChartOleView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect;

// der Abbildungsbereich für den Drucker kann hier leider noch nicht
// eingestellt werden, da die Information über die Seitengröße in
// pInfo noch nicht gültig ist. Der Abbildungsmodus wird daher in
// onPrint eingestellt.


   if (!pDC->IsPrinting ()) {
      GetClientRect (clientRect);

      pDC->SetMapMode (MM_ISOTROPIC);
      pDC->SetWindowExt (10000,10000);
		pDC->SetWindowOrg (0,0);
      pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
      pDC->SetViewportOrg (0,0);
   }

	CView::OnPrepareDC(pDC, pInfo);
}

void CStockChartOleView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect = pInfo->m_rectDraw;
   
   pDC->SetMapMode (MM_ISOTROPIC);
   pDC->SetWindowExt (10000,10000);
	pDC->SetWindowOrg (0,0);
   pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
   pDC->SetViewportOrg (0,0);
	
	CView::OnPrint(pDC, pInfo);
}
