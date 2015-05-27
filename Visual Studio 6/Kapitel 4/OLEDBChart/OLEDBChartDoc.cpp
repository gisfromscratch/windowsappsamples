// OLEDBChartDoc.cpp : Implementierung der Klasse COLEDBChartDoc
//

#include "stdafx.h"
#include "OLEDBChart.h"

#include "OLEDBChartDoc.h"
#include "StockChooser.h"

#include "Quotes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBChartDoc

IMPLEMENT_DYNCREATE(COLEDBChartDoc, CDocument)

BEGIN_MESSAGE_MAP(COLEDBChartDoc, CDocument)
	//{{AFX_MSG_MAP(COLEDBChartDoc)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBChartDoc Konstruktion/Destruktion

COLEDBChartDoc::COLEDBChartDoc()
{
   m_bGrid        = true;
   m_bAverage     = true;
   m_nAverageCnt  = 15;
   m_nColor       = RGB(0,0,255); // blau
}

COLEDBChartDoc::~COLEDBChartDoc()
{
}

BOOL COLEDBChartDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;


   // Aktienauswahldialog
   CStockChooser stockChooser;
   // Satzgruppe
   CQuotes quotes;

   // Dialog aufrufen
   if (IDOK == stockChooser.DoModal ()) {
      if (S_OK != quotes.Open (stockChooser.m_strShareName)) {
         AfxMessageBox (_T("Konnte Datenbank nicht öffnen"));
         return false;
      }

      // Titel des Dokuments/MDI-Frames
      SetTitle (stockChooser.m_strShareName);

      double value, minVal = 0.0, maxVal = 0.0;

      CString strQuote;
      COleCurrency currency;
      // zur Konvertierung wird eine US-Language ID gebraucht
      unsigned long lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);

      // ersten Wert
      if (S_OK == quotes.MoveFirst ()) {
         // Konvertierung von COleCurrency, US-Format
         currency = quotes.m_Kurs;
         strQuote = currency.Format (0, lcid);

         value  = atof (strQuote);
         minVal = value;
         maxVal = value;
         
         m_stockData.theData.AddTail (value);

         // Eigenschaften der Aktie setzen
         m_name   = quotes.m_Aktienname;
         m_nID    = quotes.m_WKN;
         m_ticker = quotes.m_Tickersymbol;
      }
      else {
         return false; // keine Werte
      }

      // alle weiteren Werte
      while (S_OK == quotes.MoveNext ()) {
         // Konvertierung von COleCurrency, US-Format
         currency = quotes.m_Kurs;
         strQuote = currency.Format (0, lcid);

         value = atof (strQuote);
         minVal = min (minVal, value);
         maxVal = max (maxVal, value);
         m_stockData.theData.AddTail (value);
      }

      // min und max setzen
      m_stockData.min = minVal;
      m_stockData.max = maxVal;

      // Durchschnittslinie
      CalcAverages ();

      return true;
   }
   else 
      // auf Abbrechen geklickt!
   	return false;
}




/////////////////////////////////////////////////////////////////////////////
// COLEDBChartDoc Diagnose

#ifdef _DEBUG
void COLEDBChartDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COLEDBChartDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBChartDoc Befehle


void COLEDBChartDoc::CalcAverages () 
{
   int nCnt = m_stockData.theData.GetCount ();
   POSITION outerPos, innerPos; 
   double value;

   m_averageData.RemoveAll ();

   // auf den Anfang der Datenliste setzen
   outerPos = m_stockData.theData.GetHeadPosition ();

   for (int i=0; i<nCnt-m_nAverageCnt; i++) {
      value = m_stockData.theData.GetNext (outerPos);
      innerPos = outerPos;
      for (int j=1; j<m_nAverageCnt; j++) {
         value += m_stockData.theData.GetNext (innerPos);
      }
      value /= m_nAverageCnt;
      m_averageData.AddTail (value);
   } 
}