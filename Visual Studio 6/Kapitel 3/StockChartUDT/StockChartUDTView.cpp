// StockChartUDTView.cpp : Implementierung der Klasse CStockChartUDTView
//

#include "stdafx.h"
#include "StockChartUDT.h"

#include "StockChartUDTDoc.h"
#include "StockChartUDTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTView

IMPLEMENT_DYNCREATE(CStockChartUDTView, CView)

BEGIN_MESSAGE_MAP(CStockChartUDTView, CView)
	//{{AFX_MSG_MAP(CStockChartUDTView)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard-Druckbefehle
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTView Konstruktion/Destruktion

CStockChartUDTView::CStockChartUDTView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CStockChartUDTView::~CStockChartUDTView()
{
}

BOOL CStockChartUDTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTView Zeichnen

void CStockChartUDTView::OnDraw(CDC* pDC)
{
	CStockChartUDTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   CPen plotPen (PS_SOLID, 30, pDoc->m_nColor);
   CPen axisPen (PS_SOLID, 1, RGB(0,0,0));
   CPen gridPen (PS_DOT, 1, RGB(192,192,192));
   CPen avgPen (PS_SOLID, 30, RGB (0,255,255));
   CPen *pOldPen;
	CFont font, *pOldFont;
   double minValue, value;
   double scaleUpFacor;

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
      scaleUpFacor = 10000.0 / (pDoc->m_stockData.max-pDoc->m_stockData.min);
      minValue = pDoc->m_stockData.min;
      // Wert holen und ein Element weiter gehen
      value = pDoc->m_stockData.theData.GetNext (pos);

      pDC->MoveTo (0, (int)((value-minValue) * scaleUpFacor));

      for (int i=1; i<nCnt; i++) {
         // Wert holen und ein Element weiter gehen
         value = pDoc->m_stockData.theData.GetNext (pos);
         pDC->LineTo (i*10000/(nCnt-1), (int)((value-minValue) * scaleUpFacor));
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
         pDC->MoveTo (pDoc->m_nAverageCnt/2*10000/(nCnt-1), (int)((value-minValue) * scaleUpFacor));
         for (int i=1; i<nAvgCnt; i++) {
            value = pDoc->m_averageData.GetNext (pos);
            pDC->LineTo ((i+(pDoc->m_nAverageCnt/2))*10000/(nCnt-1), (int)((value-minValue) * scaleUpFacor));
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
		TCHAR buffer[16];
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
// CStockChartUDTView Drucken

BOOL CStockChartUDTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CStockChartUDTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// ZU ERLEDIGEN: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CStockChartUDTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTView Diagnose

#ifdef _DEBUG
void CStockChartUDTView::AssertValid() const
{
	CView::AssertValid();
}

void CStockChartUDTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStockChartUDTDoc* CStockChartUDTView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockChartUDTDoc)));
	return (CStockChartUDTDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTView Nachrichten-Handler

void CStockChartUDTView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
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

void CStockChartUDTView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
   CRect clientRect = pInfo->m_rectDraw;
   
   pDC->SetMapMode (MM_ISOTROPIC);
   pDC->SetWindowExt (10600,-10600);
	pDC->SetWindowOrg (-300,10300);
   pDC->SetViewportExt (clientRect.right-clientRect.left, clientRect.bottom-clientRect.top);
   pDC->SetViewportOrg (0,0);

	CView::OnPrint(pDC, pInfo);
}

////////////////////////////////////////////////////////////////////////
// UDT-Funktionen

void CStockChartUDTView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	CStockChartUDTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

   // Keine leeren Dokumente kopieren:
   if (pDoc->m_name.GetLength() > 0)
      pCmdUI->Enable (true);	
   else
      pCmdUI->Enable (false);
}

void CStockChartUDTView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
   COleDataObject dataObject;

   // Nur einfügen, wenn Text in der Zwischenablage ist:
   dataObject.AttachClipboard ();
   if (dataObject.IsDataAvailable (CF_TEXT)) 
      pCmdUI->Enable (true);	
   else
      pCmdUI->Enable (false);
}


void CStockChartUDTView::OnEditCopy() 
{
   COleDataSource *pData = PutData();
   pData->SetClipboard ();	
}


void CStockChartUDTView::OnEditPaste() 
{
   COleDataObject dataObject;
   CString text;

   dataObject.AttachClipboard ();
   if (ExtractData (&dataObject, text)) {
      ConvertAndStoreData (text);
   }
}

////////////////////////////////////////////////////////////////////////
// PutData
// Verpackt Daten in eine Datenquelle und gibt diese zurück.

COleDataSource* CStockChartUDTView::PutData()
{
	CStockChartUDTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
   HGLOBAL hText;

   COleDataSource* pDataSource = new COleDataSource();

   hText = ::GlobalAlloc (GMEM_SHARE, 256);
   LPTSTR pText = (LPTSTR)::GlobalLock (hText);
   ASSERT (pText);

   sprintf (pText,
            "%s\r\n%li\r\n%s\r\n", 
            pDoc->m_name,
            pDoc->m_nID,
            (LPCTSTR)pDoc->m_ticker);
   ::GlobalUnlock (hText);

   pDataSource->CacheGlobalData (CF_TEXT, hText);

   return pDataSource;
}

////////////////////////////////////////////////////////////////////
// ExtractData
// Extrahiert Daten aus einer Datenquelle.

bool CStockChartUDTView::ExtractData(COleDataObject * pDataObject, CString & text)
{
   if (pDataObject->IsDataAvailable (CF_TEXT)) {
      HGLOBAL hText;

      hText = pDataObject->GetGlobalData (CF_TEXT);
      if (hText) {
         text = (LPSTR)::GlobalLock (hText);
         GlobalUnlock (hText);
         GlobalFree (hText); 
         return true;
      }
   }

   return false;  
}

void CStockChartUDTView::ConvertAndStoreData(CString text)
{
   CStockChartUDTDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   int nPos;
   long nID;
   CString strTicker, strName;

   nPos = text.Find ('\n');
   if (nPos > -1) {
      strName = text.Left (nPos - 1);
      text = text.Right (text.GetLength() - nPos - 1);
      nPos = text.Find ('\n');
      if (nPos > -1) {
         nID = atol (text.Left (nPos - 1));
         text = text.Right (text.GetLength() - nPos - 1);
         nPos = text.Find ('\n');
         if (nPos > -1) {
            strTicker = text.Left (nPos - 1);
         }
      }
   }
   else {
      strName = text;
   }

   pDoc->SetStockData (nID, strName, strTicker);
}


DROPEFFECT CStockChartUDTView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
   CStockChartUDTDoc *pDoc = GetDocument ();
   ASSERT_VALID (pDoc);

   if (pDataObject->IsDataAvailable (CF_TEXT) && !pDoc->m_bDrag) 
      return DROPEFFECT_COPY;
   else
      return DROPEFFECT_NONE;
}


DROPEFFECT CStockChartUDTView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
   CStockChartUDTDoc *pDoc = GetDocument ();
   ASSERT_VALID (pDoc);

   if (pDataObject->IsDataAvailable (CF_TEXT) && !pDoc->m_bDrag) 
      return DROPEFFECT_COPY;
   else
      return DROPEFFECT_NONE;
}


BOOL CStockChartUDTView::OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point) 
{
   CString text;

   CStockChartUDTDoc *pDoc = GetDocument ();
   ASSERT_VALID (pDoc);
   
   if (pDoc->m_bDrag) {
      return false; // Kein Drop auf uns selbst!
   }

   if (ExtractData (pDataObject, text)) {
      ConvertAndStoreData (text);
      return true;
   }
	
	return false;
}


void CStockChartUDTView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
		
   m_dropTarget.Register (this);		
}

void CStockChartUDTView::OnLButtonDown(UINT nFlags, CPoint point) 
{
   COleDataSource *pDataSource = PutData();
   CStockChartUDTDoc *pDoc = GetDocument ();
   ASSERT_VALID (pDoc);
   
   pDoc->m_bDrag = true;
   pDataSource->DoDragDrop (DROPEFFECT_COPY);
   pDoc->m_bDrag = false;

   delete pDataSource;
	
	CView::OnLButtonDown(nFlags, point);
}
