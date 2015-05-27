// StockChartXDoc.cpp : Implementierung der Klasse CStockChartXDoc
//

#include "stdafx.h"
#include "StockChartX.h"

#include "StockChartXDoc.h"
#include "SrvrItem.h"

#include "StockProperty.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc

IMPLEMENT_DYNCREATE(CStockChartXDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CStockChartXDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CStockChartXDoc)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	ON_COMMAND(ID_STOCK_PROPERTY, OnStockProperty)
	ON_COMMAND(ID_CHART_PROPERTY, OnChartProperty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Konstruktion/Destruktion

CStockChartXDoc::CStockChartXDoc()
{
	// Verwenden Sie OLE-Compound-Dateien
	EnableCompoundFile();

	m_nID          = 0;
   m_bGrid        = false;
   m_bAverage     = false;
   m_nAverageCnt  = 15;
   m_ticker       = "";
   m_name         = "";
   m_nColor       = RGB(255,0,0);

   m_pChartProperty = NULL;

}

CStockChartXDoc::~CStockChartXDoc()
{
   // Wenn Dialog noch offen, dann schlie�en und l�schen
   if (m_pChartProperty) {
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;
   }
}

BOOL CStockChartXDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Server-Implementierung

COleServerItem* CStockChartXDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem wird automatisch aufgerufen, um COleServerItem zu erhalten,
	//  das mit dem Dokument verkn�pft ist. Die Funktion wird nur bei Bedarf aufgerufen.

	CStockChartXSrvrItem* pItem = new CStockChartXSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Implementierung des ActiveX-Dokument-Servers

CDocObjectServer *CStockChartXDoc::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}



/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Serialisierung

void CStockChartXDoc::Serialize(CArchive& ar)
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

   m_stockData.Serialize (ar); // Serialisierung der Datenliste!
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

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Diagnose

#ifdef _DEBUG
void CStockChartXDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CStockChartXDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);

   dc << "==== CStockChartDoc ====";
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
   dc << "\nDurchschnitt �ber " << m_nAverageCnt << " Werte.";

   dc << "\n";
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockChartXDoc Befehle

//-------------------------------------------------------------------------
//  CStockChartDoc::OnPropertyChange

void CStockChartXDoc::OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow)
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

      // OLE Server mu� Container von der �nderung unterrichten:
      UpdateAllItems (NULL);
   } 

   if (bCloseWindow) {
      // Dialog schlie�en und l�schen
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;

      // Neu�ffnung erlauben
      m_pChartProperty = NULL;
   }
}



void CStockChartXDoc::CalcAverages () 
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

void CStockChartXDoc::OnFileImport() 
{
   // Dateidialog zum Importieren:
   CFileDialog fileDialog(true, NULL, NULL, NULL, "Textdateien (*.txt)|*.txt|Alle Dateien (*.*)|*.*||");

   // wenn der Benutzer Dialog mit OK verlassen hat:
   if (IDOK == fileDialog.DoModal ()) { 
      // zun�chst alte Daten l�schen
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
         // als ver�ndert kennzeichnen
			SetModifiedFlag ();

         UpdateAllItems (NULL);
      }
      catch (CFileException *e) {
         e->ReportError ();
         e->Delete (); 
         return;
      }
   } 			
}

void CStockChartXDoc::DeleteContents() 
{
   // Inhalt der Liste l�schen:
   m_stockData.theData.RemoveAll ();

   // Funktion der Basisklasse darf nicht aufgerufen werden,
   // da sonst das ServerItem gel�scht wird !!!
   // COleServerDoc::DeleteContents();
}

BOOL CStockChartXDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!COleServerDoc::OnOpenDocument(lpszPathName))
		return FALSE;
	
   CalcAverages (); // Durchschnittslinie berechnen
	
	return TRUE;
}


void CStockChartXDoc::OnStockProperty() 
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

      // OLE Server mu� Container von der �nderung unterrichten:
      UpdateAllItems (NULL);
   } 			
}

void CStockChartXDoc::OnChartProperty() 
{
   // nur Erzeugen wenn es noch keine Instanz gibt:
   if (NULL == m_pChartProperty) {
      // Dialogobjekt erzeugen
      m_pChartProperty = new CChartProperty (this);

      // nun die Daten �bertragen
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