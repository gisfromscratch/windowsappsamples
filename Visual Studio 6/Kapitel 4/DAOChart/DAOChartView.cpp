// DAOChartView.cpp : Implementierung der Klasse CDAOChartView
//

#include "stdafx.h"
#include "DAOChart.h"

#include "DAOChartDoc.h"
#include "DAOChartView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView

IMPLEMENT_DYNCREATE(CDAOChartView, CView)

BEGIN_MESSAGE_MAP(CDAOChartView, CView)
	//{{AFX_MSG_MAP(CDAOChartView)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView Konstruktion/Destruktion

CDAOChartView::CDAOChartView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CDAOChartView::~CDAOChartView()
{
}

BOOL CDAOChartView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView Zeichnen

void CDAOChartView::OnDraw(CDC* pDC)
{
	CDAOChartDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   CPen plotPen (PS_SOLID, 30, pDoc->m_nColor);
   CPen axisPen (PS_SOLID, 1, RGB(0,0,0));
   CPen gridPen (PS_DOT, 1, RGB(192,192,192));
   CPen avgPen (PS_SOLID, 30, RGB (0,255,255));
   CPen *pOldPen;
	CFont font, *pOldFont;
   double minValue, value;
   double scaleUpFactor;

   // alten Stif sichern, neuen in den Gerätekontext selektieren
   pOldPen = pDC->SelectObject (&axisPen);

   // Achsen zeichnen
   pDC->MoveTo (0,0);
   pDC->LineTo (0,10000);
   pDC->MoveTo (0,0);
   pDC->LineTo (10000,0);

   // falls gewünscht, Gitternetz zeichnen
	if (pDoc->m_bGrid) {
		pDC->SelectObject (&gridPen);
		for (int i=1; i<=10; i++) {
			pDC->MoveTo (i*1000, 0);
			pDC->LineTo (i*1000, 10000);

			pDC->MoveTo (0, i*1000);
			pDC->LineTo (10000, i*1000);
		} // for
   } 

   // Stift zum Zeichnen der Kurve setzen
	pDC->SelectObject (&plotPen);

   // Anzahl der Listeneinträge ermitteln
   int nCnt = pDoc->m_stockData.theData.GetCount ();

   if (nCnt > 0) {
      POSITION pos;  // hält Position in der Liste

      // Auf Anfang der Liste positionieren
      pos = pDoc->m_stockData.theData.GetHeadPosition ();
      scaleUpFactor = 10000.0 / (pDoc->m_stockData.max-pDoc->m_stockData.min);
      minValue = pDoc->m_stockData.min;
      // Wert holen und ein Element weiter gehen
      value = pDoc->m_stockData.theData.GetNext (pos);

      pDC->MoveTo (0, (int)((value-minValue) * scaleUpFactor));

      for (int i=1; i<nCnt; i++) {
         // Wert holen und ein Element weiter gehen
         value = pDoc->m_stockData.theData.GetNext (pos);
         pDC->LineTo (i*10000/(nCnt-1), (int)((value-minValue) * scaleUpFactor));
      } 
   } 

   // falls gewünscht, Durchschnittslinie zeichnen
   if (pDoc->m_bAverage) {
      pDC->SelectObject (&avgPen);

      int nAvgCnt = pDoc->m_averageData.GetCount ();

      if (nAvgCnt > 0) {
         POSITION pos;  // hält Position in der Liste
         
         // Auf Anfang der Liste positionieren
         pos = pDoc->m_averageData.GetHeadPosition ();
         value = pDoc->m_averageData.GetNext (pos); 
         pDC->MoveTo (pDoc->m_nAverageCnt/2*10000/(nCnt-1), (int)((value-minValue) * scaleUpFactor));
         for (int i=1; i<nAvgCnt; i++) {
            value = pDoc->m_averageData.GetNext (pos);
            pDC->LineTo ((i+(pDoc->m_nAverageCnt/2))*10000/(nCnt-1), (int)((value-minValue) * scaleUpFactor));
         }
      }
   }

   // Schriftart erzeugen und setzen
	font.CreateFont (500, 0,0,0, FW_NORMAL, 0,0,0, ANSI_CHARSET, 
		              OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						  DEFAULT_PITCH | FF_SWISS, NULL);
   pOldFont = pDC->SelectObject (&font);
   
	// Beschriftung
   pDC->TextOut (200, 9800, pDoc->m_name);
	if (pDoc->m_nID != 0) {
		char buffer[16];
      // _itot benutzt automatisch Unicode oder ANSI-Zeichen
		pDC->TextOut (200, 9300, _itot (pDoc->m_nID, buffer, 10)); 
	} 
	pDC->TextOut (200, 8800, pDoc->m_ticker);

   // alten Stift zurücksetzen
   pDC->SelectObject (pOldPen);
	// alte Schriftart zurücksetzen
	pDC->SelectObject (pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView Drucken

BOOL CDAOChartView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CDAOChartView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CDAOChartView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Hier Bereinigungsarbeiten nach dem Drucken einfügen
}

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView Diagnose

#ifdef _DEBUG
void CDAOChartView::AssertValid() const
{
	CView::AssertValid();
}

void CDAOChartView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDAOChartDoc* CDAOChartView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDAOChartDoc)));
	return (CDAOChartDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDAOChartView Nachrichten-Handler

void CDAOChartView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect;

// der Abbildungsbereich für den Drucker kann hier leider noch nicht
// eingestellt werden, da die Information über die Seitengröße in
// pInfo noch nicht gültig ist. Der Abbildungsmodus wird daher in
// onPrint eingestellt.

   if (!pDC->IsPrinting ()) {
      GetClientRect (clientRect);

      pDC->SetMapMode (MM_ISOTROPIC);
      pDC->SetWindowExt (10600,-10600);
		pDC->SetWindowOrg (-300,10300);
      pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
      pDC->SetViewportOrg (0,0);
   }
	
	CView::OnPrepareDC(pDC, pInfo);
}

void CDAOChartView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect = pInfo->m_rectDraw;
   
   pDC->SetMapMode (MM_ISOTROPIC);
   pDC->SetWindowExt (10600,-10600);
	pDC->SetWindowOrg (-300,10300);
   pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
   pDC->SetViewportOrg (0,0);
	
	CView::OnPrint(pDC, pInfo);
}
