// MandelbrotDoc.cpp : Implementierung der Klasse CMandelbrotDoc
//

#include "stdafx.h"
#include "Mandelbrot.h"

#include "MandelbrotDoc.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Wird benötigt, um Calculate aufzurufen
struct MandelbrotCall {
   CMandelbrotDoc *pDoc;
   HWND hWnd;
};


/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc

IMPLEMENT_DYNCREATE(CMandelbrotDoc, CDocument)

BEGIN_MESSAGE_MAP(CMandelbrotDoc, CDocument)
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc Konstruktion/Destruktion

CMandelbrotDoc::CMandelbrotDoc()
{
   CDC memDC;
   memDC.CreateCompatibleDC (NULL);
   CBitmap *pOldBitmap;

   m_pBitmap = new CBitmap ();
   m_pBitmap->CreateBitmap (kViewSize, kViewSize, 1, memDC.GetDeviceCaps (BITSPIXEL), NULL);
   m_pBitmapCopy = new CBitmap ();
   m_pBitmapCopy->CreateBitmap (kViewSize, kViewSize, 1, memDC.GetDeviceCaps (BITSPIXEL), NULL);

   // Initialisieren der Bitmap zur Berechnung der Mandelbrotmenge
   pOldBitmap = memDC.SelectObject (m_pBitmap);
   // Schwarz
   memDC.PatBlt (0,0,kViewSize,kViewSize,BLACKNESS);
   // Aufräumen
   memDC.SelectObject (pOldBitmap);
}

CMandelbrotDoc::~CMandelbrotDoc()
{
   if (m_pBitmap)
      delete m_pBitmap;
   if (m_pBitmapCopy)
      delete m_pBitmapCopy;
}

BOOL CMandelbrotDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc Serialisierung

void CMandelbrotDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// ZU ERLEDIGEN: Hier Code zum Speichern einfügen
	}
	else
	{
		// ZU ERLEDIGEN: Hier Code zum Laden einfügen
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc Diagnose

#ifdef _DEBUG
void CMandelbrotDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMandelbrotDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotDoc Befehle


// statische Memberfunktion
UINT CMandelbrotDoc::Calculate (LPVOID pParam)
{
   MandelbrotCall *call = (MandelbrotCall*)pParam;
   
   ASSERT (AfxIsValidAddress (call->pDoc, sizeof(CObject)));
   return call->pDoc->Calculate (call->hWnd);
}


UINT CMandelbrotDoc::Calculate(HWND hWnd)
{
   // Bereich des "klassischen" Apfelmännchens
   static const double rMin=-2.25, rMax=0.75;
   static const double iMin=-1.5, iMax=1.5;

   double cRe, cIm;
   double zRe, zIm;
   double sqrZRe, sqrZIm;

   double tempRe;
   double reStep = fabs ((rMax-rMin) / kViewSize);
   double imStep = fabs ((iMax-iMin) / kViewSize);
   
   int i,j, nCnt;
   int nColor;
   COLORREF rgbColor;

   CDC memDC;
   memDC.CreateCompatibleDC (NULL);
   CBitmap *oldBitmap;


   cRe = rMin;
   cIm = iMin;
   for (i=0; i<kViewSize; i++) {
      for (j=0; j<kViewSize; j++) {
         Sleep (0); // siehe Text
               
         if (m_bWantExit) {
            // Wartender Hauptthread kann weitermachen:
            m_killEvent.SetEvent ();
            return 1;  // Vorzeitiger Abbruch
         }

      // == Ab hier kritischer Bereich == 
         CSingleLock lock (&m_cs, TRUE);
         oldBitmap = memDC.SelectObject (m_pBitmap);
         
         zRe = 0.0; zIm = 0.0;
         sqrZRe = 0.0; sqrZIm = 0.0;
         nCnt = 0;
         while ((sqrZRe + sqrZIm) < 4.0 && nCnt < 100) {
            tempRe = sqrZRe - sqrZIm;
            zIm = 2.0 * zRe * zIm;
            zRe = tempRe;

            zRe = zRe + cRe;
            zIm = zIm + cIm;

            sqrZRe = zRe*zRe;
            sqrZIm = zIm*zIm;

            nCnt++;
         } 
         
         // Farbwert bestimmen
         nColor = 2*(100-nCnt);
         // Umsetzung als Grauwert
         rgbColor = RGB (nColor,nColor,nColor);

         {  // Eigener Stackblock für den Pen
            CPen pen(PS_SOLID, 1, rgbColor);
            CPen *oldPen;

            oldPen = memDC.SelectObject (&pen);
            memDC.MoveTo (i,j);
            memDC.LineTo (i,j+1);

            // Aufräumen
            memDC.SelectObject (oldPen);
         }

         cIm += imStep;

         // Aufräumen
         memDC.SelectObject (oldBitmap);
         
      } // == Lock wirkt bis hier ==
      cIm = iMin;
      cRe += reStep;

      // Nachricht an den View: Update
      ::PostMessage (hWnd, WM_LINEDONE, i, 0);
   }

   // Event setzen, sonst terminert das Programm nie!
   m_killEvent.SetEvent ();

   return 0;
}

CBitmap * CMandelbrotDoc::GetBitmap()
{
   // Zum Kopieren Zugriff auf Bitmap schützen
   CSingleLock lock (&m_cs, TRUE);
   CBitmap *oldSrc, *oldDst;
   CDC memSrcDC, memDstDC;

   memSrcDC.CreateCompatibleDC (NULL);
   memDstDC.CreateCompatibleDC (NULL);

   oldSrc = memSrcDC.SelectObject (m_pBitmap);
   oldDst = memDstDC.SelectObject (m_pBitmapCopy);

   memDstDC.BitBlt (0,0,kViewSize,kViewSize, &memSrcDC, 0, 0, SRCCOPY);

   memSrcDC.SelectObject (oldSrc);
   memDstDC.SelectObject (oldDst);
      
   return m_pBitmapCopy;
}


void CMandelbrotDoc::StartCalculation(HWND hView)
{
   static MandelbrotCall call; // !!! Fallstrick

   call.pDoc = this;
   call.hWnd = hView;

// Variable für vorzeitigen Abbruch initialisieren
   m_bWantExit  = false;

   m_pThread = AfxBeginThread (Calculate, &call, THREAD_PRIORITY_LOWEST);

// Thread soll sich nicht selbst löschen, das Handle wird noch für
// den Exit-Status gebraucht
   m_pThread->m_bAutoDelete = false;
}


void CMandelbrotDoc::OnCloseDocument() 
{
   DWORD dwExitCode;

   // Benn Berechnung noch läuft, abbrechen:
   m_bWantExit = true;

   // Auf Terminierung warten   
   CSingleLock (&m_killEvent, true);

   // Nun darauf warten, daß der Thread beendet wird   
   do {     
      // Bitte zum Thread wechseln
      Sleep (1);      

      ::GetExitCodeThread (m_pThread->m_hThread, &dwExitCode);
   } while (dwExitCode == STILL_ACTIVE);

   // AutoDelete wurde ja abgeschaltet
   delete m_pThread;

	CDocument::OnCloseDocument();
}
