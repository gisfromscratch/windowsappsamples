// StockChartUDTDoc.cpp : Implementierung der Klasse CStockChartUDTDoc
//

#include "stdafx.h"
#include "StockChartUDT.h"

#include "StockChartUDTDoc.h"
#include "StockProperty.h"  // für modalen Dialog

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTDoc

IMPLEMENT_DYNCREATE(CStockChartUDTDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockChartUDTDoc, CDocument)
	//{{AFX_MSG_MAP(CStockChartUDTDoc)
	ON_COMMAND(ID_CHART_PROPERTY, OnChartProperty)
	ON_COMMAND(ID_STOCK_PROPERTY, OnStockProperty)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTDoc Konstruktion/Destruktion

CStockChartUDTDoc::CStockChartUDTDoc()
{
	m_nID          = 0;
   m_bGrid        = false;
   m_bAverage     = false;
   m_nAverageCnt  = 15;
   m_ticker       = "";
   m_name         = "";
   m_nColor       = RGB(255,0,0);

   m_pChartProperty = NULL;
   m_bDrag        = false;
}

CStockChartUDTDoc::~CStockChartUDTDoc()
{
   // Wenn Dialog noch offen, dann schließen und löschen
   if (m_pChartProperty) {
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;
   }
}

BOOL CStockChartUDTDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTDoc Serialisierung

void CStockChartUDTDoc::Serialize(CArchive& ar)
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
// CStockChartUDTDoc Diagnose

#ifdef _DEBUG
void CStockChartUDTDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockChartUDTDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);

   dc << "==== CStockChartUDTDoc ====";
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
// CStockChartUDTDoc Befehle

void CStockChartUDTDoc::OnChartProperty() 
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
//  CStockChartUDTDoc::OnPropertyChange

void CStockChartUDTDoc::OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow)
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

void CStockChartUDTDoc::OnStockProperty() 
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

void CStockChartUDTDoc::OnFileImport() 
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

void CStockChartUDTDoc::DeleteContents() 
{
	// Inhalt der Liste löschen:
   m_stockData.theData.RemoveAll ();

	CDocument::DeleteContents();
}


void CStockChartUDTDoc::CalcAverages () 
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



BOOL CStockChartUDTDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
   CalcAverages (); // Durchschnittslinie berechnen
   	
	return TRUE;
}

void CStockChartUDTDoc::SetStockData (const int id, const CString& name, const CString& ticker)
{
   if (id >= 0 && id < 1000000)
      m_nID = id;
   if (ticker.GetLength() <= 10) {
      m_ticker = ticker;
      m_ticker.MakeUpper ();
   }
   m_name = name;

   UpdateAllViews (NULL);
   SetModifiedFlag ();
}
