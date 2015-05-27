// ODBCChartDoc.cpp : Implementierung der Klasse CODBCChartDoc
//

#include "stdafx.h"
#include "ODBCChart.h"

#include "ODBCChartDoc.h"
#include "StockChooser.h"
#include "Quotes.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCChartDoc

IMPLEMENT_DYNCREATE(CODBCChartDoc, CDocument)

BEGIN_MESSAGE_MAP(CODBCChartDoc, CDocument)
	//{{AFX_MSG_MAP(CODBCChartDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCChartDoc Konstruktion/Destruktion

CODBCChartDoc::CODBCChartDoc()
{
   m_bGrid        = true;
   m_bAverage     = true;
   m_nAverageCnt  = 15;
   m_nColor       = RGB(0,0,255); // blau
}

CODBCChartDoc::~CODBCChartDoc()
{
}


BOOL CODBCChartDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

   // Aktienauswahldialog
   CStockChooser stockChooser;
   // Satzgruppe
   CQuotes quotes;

   // Dialog aufrufen
   if (IDOK == stockChooser.DoModal ()) {
      try {
         // Anfrage formulieren:
         // SELECT *
         // FROM  Aktie, Kurs
         // WHERE Aktie.Aktiennummer = Kurs.Aktiennummer AND
         //       Aktienname = <stockChooser.m_strShareName>
         // ORDER BY Datum
         quotes.m_strFilter  = _T("[Aktie].[Aktiennummer] = [Kurs].[Aktiennummer] AND");
         quotes.m_strFilter += _T("[Aktienname] = '");
         quotes.m_strFilter += stockChooser.m_strShareName;
         quotes.m_strFilter += _T("'");
         quotes.m_strSort    = _T("[Datum]");

         // Satzgruppe öffnen
         quotes.Open ();

         // Satzgruppe leer?
         if (quotes.IsBOF ()) {
            AfxMessageBox (_T("keine Datensätze vorhanden!"));
            return false;
         }

         double value, minVal = 0.0, maxVal = 0.0;
         
         // auf Anfang positionieren
         quotes.MoveFirst ();

         minVal = atof (quotes.m_Kurs);
         maxVal = minVal;

         // Name, Ticker, WKN
         m_ticker = quotes.m_Tickersymbol;
         m_name   = quotes.m_Aktienname;
         m_nID    = quotes.m_WKN;

         // Titel des Dokuments/MDI-Frames
         SetTitle (m_name);

         // Daten kopieren
         while (!quotes.IsEOF ()) {
            value = atof (quotes.m_Kurs);
            minVal = min (minVal, value);
            maxVal = max (maxVal, value);
            m_stockData.theData.AddTail (value);

            quotes.MoveNext ();
         }

         // min und max setzen
         m_stockData.min = minVal;
         m_stockData.max = maxVal;

         // Satzgruppe schließen
         quotes.Close ();

         // Durchschnittslinie
         CalcAverages ();

         return true;

      }
      catch (CDBException *e) {
         e->ReportError ();
         e->Delete ();

         return false;
      }
   }
   else 
      // auf Abbrechen geklickt!
   	return false;
}




/////////////////////////////////////////////////////////////////////////////
// CODBCChartDoc Diagnose

#ifdef _DEBUG
void CODBCChartDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBCChartDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCChartDoc Befehle

void CODBCChartDoc::CalcAverages () 
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


