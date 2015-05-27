// StockChartXView.cpp : Implementierung der Klasse CStockChartXView
//

#include "stdafx.h"
#include "StockChartX.h"

#include "StockChartXDoc.h"
#include "StockChartXView.h"

#include "DrawFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartXView

IMPLEMENT_DYNCREATE(CStockChartXView, CView)

BEGIN_MESSAGE_MAP(CStockChartXView, CView)
	//{{AFX_MSG_MAP(CStockChartXView)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, OnCancelEditSrvr)
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartXView Konstruktion/Destruktion

CStockChartXView::CStockChartXView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CStockChartXView::~CStockChartXView()
{
}

BOOL CStockChartXView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartXView Zeichnen

void CStockChartXView::OnDraw(CDC* pDC)
{
	CStockChartXDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   // Drawfunktion wurde ausgelagert
   ::Draw (pDC, pDoc, 10000);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartXView Drucken

BOOL CStockChartXView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CStockChartXView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CStockChartXView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
}

/////////////////////////////////////////////////////////////////////////////
// OLE-Server-Unterstützung

// Der folgende Befehls-Handler stellt die Standardtastatur als
//  Benutzerschnittstelle zum Abbruch der direkten Bearbeitungssitzung zur Verfügung. Hier
//  verursacht der Container (nicht der Server) die Deaktivierung.
void CStockChartXView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartXView Diagnose

#ifdef _DEBUG
void CStockChartXView::AssertValid() const
{
	CView::AssertValid();
}

void CStockChartXView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStockChartXDoc* CStockChartXView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockChartXDoc)));
	return (CStockChartXDoc*)m_pDocument;
}
#endif //_DEBUG


void CStockChartXView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
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

void CStockChartXView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect = pInfo->m_rectDraw;
   
   pDC->SetMapMode (MM_ISOTROPIC);
   pDC->SetWindowExt (10000,10000);
	pDC->SetWindowOrg (0,0);
   pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
   pDC->SetViewportOrg (0,0);
	
	CView::OnPrint(pDC, pInfo);
}
