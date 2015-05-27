// MandelbrotView.cpp : Implementierung der Klasse CMandelbrotView
//

#include "stdafx.h"
#include "Mandelbrot.h"

#include "MandelbrotDoc.h"
#include "MandelbrotView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView

IMPLEMENT_DYNCREATE(CMandelbrotView, CScrollView)

BEGIN_MESSAGE_MAP(CMandelbrotView, CScrollView)
	ON_WM_ERASEBKGND()
    ON_MESSAGE (WM_LINEDONE, OnLineDone)
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView Konstruktion/Destruktion

CMandelbrotView::CMandelbrotView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CMandelbrotView::~CMandelbrotView()
{
}

BOOL CMandelbrotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView Zeichnen

void CMandelbrotView::OnDraw(CDC* pDC)
{
	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   CDC memDC;
   CBitmap *oldBitmap;
   
   // Speicher DC erzeugen
   memDC.CreateCompatibleDC (NULL);
   
   // Bitmap dort hineinselektieren
   oldBitmap = memDC.SelectObject (pDoc->GetBitmap ());
   
   // Auf den Schirm!
   pDC->BitBlt (0,0,kViewSize,kViewSize, &memDC, 0, 0, SRCCOPY);
   
   // Aufräumen
   memDC.SelectObject (oldBitmap);
}

void CMandelbrotView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;

	 // Größe der Ansicht festlegen
   sizeTotal.cx = sizeTotal.cy = kViewSize;
	SetScrollSizes(MM_TEXT, sizeTotal);

	CMandelbrotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   pDoc->StartCalculation (m_hWnd);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView Diagnose

#ifdef _DEBUG
void CMandelbrotView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMandelbrotView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMandelbrotDoc* CMandelbrotView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMandelbrotDoc)));
	return (CMandelbrotDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotView Nachrichten-Handler

LRESULT CMandelbrotView::OnLineDone(WPARAM wParam, LPARAM lParam)
{
   CRect r(0,0,kViewSize,kViewSize);
   CMainFrame *pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
         
   pFrame->ShowLine (wParam);

   RedrawWindow (r);

   return 0;
}


BOOL CMandelbrotView::OnEraseBkgnd(CDC* pDC) 
{

   CRect r;
   
   GetClientRect (r);

   pDC->PatBlt (kViewSize,0,r.right-kViewSize,r.bottom, BLACKNESS);
   pDC->PatBlt (0,kViewSize,kViewSize,r.bottom-kViewSize, BLACKNESS);

// Aufruf der Funktion der Basisklasse gelöscht!
   return true;
}
