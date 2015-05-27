// StockChartWithDllDoc.cpp : Implementierung der Klasse CStockChartWithDllDoc
//

#include "stdafx.h"
#include "StockChartWithDll.h"

#include "StockChartWithDllDoc.h"
#include "StockProperty.h"  // für modalen Dialog

#ifdef _DEBUG
#define new DEBUG_NEW 
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartWithDllDoc

IMPLEMENT_DYNCREATE(CStockChartWithDllDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockChartWithDllDoc, CDocument)
	//{{AFX_MSG_MAP(CStockChartWithDllDoc)
	ON_COMMAND(ID_CHART_PROPERTY, OnChartProperty)
	ON_COMMAND(ID_STOCK_PROPERTY, OnStockProperty)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartWithDllDoc Konstruktion/Destruktion

CStockChartWithDllDoc::CStockChartWithDllDoc()
{
	m_nID          = 0;
   m_bGrid        = false;
   m_bAverage     = false;
   m_nAverageCnt  = 15;
   m_ticker       = "";
   m_name         = "";
   m_nColor       = RGB(255,0,0);

   m_pChartProperty = NULL;
}

CStockChartWithDllDoc::~CStockChartWithDllDoc()
{
   // Wenn Dialog noch offen, dann schließen und löschen
   if (m_pChartProperty) {
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;
   }
}

BOOL CStockChartWithDllDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockChartWithDllDoc Serialisierung

void CStockChartWithDllDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_nID;
      ar << m_name;
      ar << m_ticker;
      ar << m_bGrid;
      ar << m_bAverage;
      ar << m_nAverageCnt;
      ar << m_nColor;
	}
	else
	{
      ar >> m_nID;
      ar >> m_name;
      ar >> m_ticker;
      ar >> m_bGrid;
      ar >> m_bAverage;
      ar >> m_nAverageCnt;
      ar >> m_nColor;
	}

   m_stockData.Serialize (ar); // das müssen wir selbst machen!
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartWithDllDoc Diagnose

#ifdef _DEBUG
void CStockChartWithDllDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockChartWithDllDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);

   dc << "==== CStockChartWithDllDoc ====";
   dc << "\nName:   " << m_name;
   dc << "\nWKN:    " << m_nID;
   dc << "\nTicker: " << m_ticker;
   dc << "\nGitternetz "; 
   if (m_bGrid)
      dc << "ist an.";
   else
      dc << "ist aus.";
   dc << "\nDurchschnittslinie ";
   if (m_bAverage)
      dc << "ist an.";
   else
      dc << "ist aus.";
   dc << "\nDurchschnitt über " << m_nAverageCnt << " Werte.";

   dc << "\n";
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockChartWithDllDoc Befehle

void CStockChartWithDllDoc::OnChartProperty() 
{ 
   // nur Erzeugen wenn es noch keine Instanz gibt:
   if (NULL == m_pChartProperty) {
      // Dialogobjekt erzeugen
      m_pChartProperty = new CChartProperty (this);

      // nun die Daten übertragen
      m_pChartProperty->m_bGrid    = m_bGrid;
      m_pChartProperty->m_bAverage = m_bAverage;
      if (GetRValue (m_nColor) > 0)
         m_pChartProperty->m_nColor = 0;
      else if (GetGValue (m_nColor) > 0)
         m_pChartProperty->m_nColor = 1;
      else
         m_pChartProperty->m_nColor = 2;

      m_pChartProperty->m_nAverageCnt = m_nAverageCnt;

      // Dialog erzeugen und anzeigen
      m_pChartProperty->Create ();
   } 
   	
}

//-------------------------------------------------------------------------
//  CStockChartWithDllDoc::OnPropertyChange

void CStockChartWithDllDoc::OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow)
{
   if (bUpdateData) {
      m_bGrid       = m_pChartProperty->m_bGrid;
      m_bAverage    = m_pChartProperty->m_bAverage;
      m_nAverageCnt = m_pChartProperty->m_nAverageCnt;
      switch (m_pChartProperty->m_nColor) {
         default:
         case 0:
            m_nColor = RGB(255,0,0);
            break;

         case 1:
            m_nColor = RGB(0,255,0);
            break;

         case 2:
            m_nColor = RGB(0,0,255);
            break;
      } // switch

      CalcAverages ();

      UpdateAllViews (NULL);	
		SetModifiedFlag ();
   } 

   if (bCloseWindow) {
      // Dialog schließen und löschen
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;

      // Neuöffnung erlauben
      m_pChartProperty = NULL;
   }
}

//----------------------------------------------------------------------------
// CStockData::Serialize

void CStockData::Serialize (CArchive& ar) 
{
   if (ar.IsStoring ()) {
      ar << min;
      ar << max;
   }
   else {
      ar >> min;
      ar >> max;
   }

   theData.Serialize (ar);
}

void CStockChartWithDllDoc::OnStockProperty() 
{
	CStockProperty stockPropertyDialog;

   stockPropertyDialog.m_name = m_name;
   stockPropertyDialog.m_ticker = m_ticker;
   stockPropertyDialog.m_nID = m_nID;

   if (IDOK == stockPropertyDialog.DoModal ()) {
      m_name   = stockPropertyDialog.m_name;
      m_ticker = stockPropertyDialog.m_ticker;
      m_nID    = stockPropertyDialog.m_nID;

      UpdateAllViews (NULL);
		SetModifiedFlag ();
   } 	
}

void CStockChartWithDllDoc::OnFileImport() 
{
   // Dateidialog zum Importieren:
   CFileDialog fileDialog(true, NULL, NULL, NULL, "Textdateien (*.txt)|*.txt|Alle Dateien (*.*)|*.*||");

   // wenn der Benutzer Dialog mit OK verlassen hat:
   if (IDOK == fileDialog.DoModal ()) { 
      // zunächst alte Daten löschen
      DeleteContents ();

      try {
         CStdioFile file (fileDialog.GetPathName (), CFile::typeText);
         CString line;
         double value, minVal, maxVal;

         file.ReadString (line);
         minVal = atof (line);
         maxVal = minVal;

         while (file.ReadString (line)) {
            value = atof (line);
            minVal = min (minVal, value);
            maxVal = max (maxVal, value);
            m_stockData.theData.AddTail (value);
         }

         m_stockData.min = minVal;
         m_stockData.max = maxVal;
      
         // Durchschnittslinie berechnen
         CalcAverages ();

         // Alle Ansichten aktualisieren
         UpdateAllViews (NULL);
         // als verändert kennzeichnen
			SetModifiedFlag ();
      }
      catch (CFileException *e) {
         e->ReportError ();
         e->Delete (); 
         return;
      }
   } 	
}

void CStockChartWithDllDoc::DeleteContents() 
{
	// Inhalt der Liste löschen:
   m_stockData.theData.RemoveAll ();

	CDocument::DeleteContents();
}


void CStockChartWithDllDoc::CalcAverages () 
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



BOOL CStockChartWithDllDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
   CalcAverages (); // Durchschnittslinie berechnen
   	
	return TRUE;
}
