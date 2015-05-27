#include "stdafx.h"

#include "DrawFunc.h"
#include "StockChartOleDoc.h"

// Ausgelagerte Draw-Funktion
void Draw(CDC* pDC, CStockChartOleDoc* pDoc, long nSize)
{
   CPen plotPen (PS_SOLID, 1, pDoc->m_nColor);
   CPen axisPen (PS_SOLID, 1, RGB(0,0,0));
   CPen gridPen (PS_SOLID, 1, RGB(192,192,192)); // solid!!!
   CPen avgPen (PS_SOLID, 1, RGB (0,255,255));
   CPen *pOldPen;
	CFont font, *pOldFont;
   double minValue, value;
   double scaleUpFactor;

   // delta gibt den Abstand zu den Seiten an,
   // ext die Ausdehnung
   int delta = nSize * 3 / 100;
   int ext   = nSize - 2 * delta;

   // Alten Stift sichern, neuen in den Gerätekontext selektieren:
   pOldPen = pDC->SelectObject (&axisPen);

   // Achsen zeichnen:
   pDC->MoveTo (delta, delta + ext);
   pDC->LineTo (delta, delta);
   pDC->MoveTo (delta, delta + ext);
   pDC->LineTo (delta + ext, delta + ext);

   // Falls gewünscht, Gitternetz zeichnen:
	if (pDoc->m_bGrid) {
      int nPart = ext / 10;

		pDC->SelectObject (&gridPen);
		for (int i=1; i<=10; i++) {
			pDC->MoveTo (i*nPart+delta, delta);
			pDC->LineTo (i*nPart+delta, ext+delta);

			pDC->MoveTo (delta, (i-1)*nPart+delta);
			pDC->LineTo (ext+delta, (i-1)*nPart+delta);
		} // for
   } 

   // Stift zum Zeichnen der Kurve setzen:
	pDC->SelectObject (&plotPen);

   // Anzahl der Listeneinträge ermitteln:
   int nCnt = pDoc->m_stockData.theData.GetCount ();

   if (nCnt > 0) {
      POSITION pos;  // hält Position in der Liste

      // Auf Anfang der Liste positionieren:
      pos = pDoc->m_stockData.theData.GetHeadPosition ();
      scaleUpFactor = ext / (pDoc->m_stockData.max-pDoc->m_stockData.min);
      minValue = pDoc->m_stockData.min;
      // Wert holen und ein Element weiter gehen:
      value = pDoc->m_stockData.theData.GetNext (pos);

      pDC->MoveTo (delta, delta + ext - (int)((value-minValue) * scaleUpFactor));

      for (int i=1; i<nCnt; i++) {
         // Wert holen und ein Element weiter gehen
         value = pDoc->m_stockData.theData.GetNext (pos);
         pDC->LineTo (delta + i*ext/(nCnt-1), delta + ext - (int)((value-minValue) * scaleUpFactor));
      } 
   } 

   // Falls gewünscht, Durchschnittslinie zeichnen:
   if (pDoc->m_bAverage) {
      pDC->SelectObject (&avgPen);

      int nAvgCnt = pDoc->m_averageData.GetCount ();

      if (nAvgCnt > 0) {
         POSITION pos;  // hält Position in der Liste
         
         // Auf Anfang der Liste positionieren:
         pos = pDoc->m_averageData.GetHeadPosition ();
         value = pDoc->m_averageData.GetNext (pos); 
         pDC->MoveTo (delta + pDoc->m_nAverageCnt/2*ext/(nCnt-1), delta + ext - (int)((value-minValue) * scaleUpFactor));
         for (int i=1; i<nAvgCnt; i++) {
            value = pDoc->m_averageData.GetNext (pos);
            pDC->LineTo (delta + (i+(pDoc->m_nAverageCnt/2))*ext/(nCnt-1), delta + ext - (int)((value-minValue) * scaleUpFactor));
         }
      }
   }

   // Schriftart erzeugen und setzen:
	font.CreateFont (ext/20, 0,0,0, FW_NORMAL, 0,0,0, ANSI_CHARSET, 
		              OUT_DEVICE_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						  DEFAULT_PITCH | FF_SWISS, NULL);
   pOldFont = pDC->SelectObject (&font);
   
	// Beschriftung
   pDC->TextOut (3*delta/2, 2*delta, pDoc->m_name);
	if (pDoc->m_nID != 0) {
		TCHAR buffer[16];
      // _itot benutzt automatisch Unicode- oder ANSI-Zeichen:
		pDC->TextOut (3*delta/2, 7*delta/2, _itot (pDoc->m_nID, buffer, 10)); 
	} 
	pDC->TextOut (3*delta/2, 5*delta, pDoc->m_ticker);

   // Alten Stift zurücksetzen:
   pDC->SelectObject (pOldPen);
	// Alte Schriftart zurücksetzen:
	pDC->SelectObject (pOldFont);
}

