// StockChartAutoDoc.cpp : Implementierung der Klasse CStockChartAutoDoc
//

#include "stdafx.h"
#include "StockChartAuto.h"
#include "StockChartAutoDoc.h"
#include "StockProperty.h"  // für modalen Dialog
#include "StatusBarInterface.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoDoc

IMPLEMENT_DYNCREATE(CStockChartAutoDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockChartAutoDoc, CDocument)
	//{{AFX_MSG_MAP(CStockChartAutoDoc)
	ON_COMMAND(ID_STOCK_PROPERTY, OnStockProperty)
	ON_COMMAND(ID_CHART_PROPERTY, OnChartProperty)
	ON_COMMAND(ID_FILE_IMPORT, OnFileImport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CStockChartAutoDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CStockChartAutoDoc)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "id", GetId, SetId, VT_I4)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "name", GetName, SetName, VT_BSTR)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "statusbar", GetStatusbar, SetNotSupported, VT_DISPATCH)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "ticker", GetTicker, SetTicker, VT_BSTR)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "average", GetAverage, SetAverage, VT_BOOL)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "averagecnt", GetAveragecnt, SetAveragecnt, VT_I4)
	DISP_PROPERTY_EX(CStockChartAutoDoc, "grid", GetGrid, SetGrid, VT_BOOL)
	DISP_FUNCTION(CStockChartAutoDoc, "ShowWindow", ShowWindow, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CStockChartAutoDoc, "SetColor", SetColor, VT_EMPTY, VTS_I2 VTS_I2 VTS_I2)
	DISP_FUNCTION(CStockChartAutoDoc, "SaveFile", SaveFile, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CStockChartAutoDoc, "ImportFile", ImportFile, VT_BOOL, VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Hinweis: Wir stellen Unterstützung für IID_IStockChartAuto zur Verfügung, um typsicheres Binden 
//  von VBA zu unterstützen. Diese IID muss mit der GUID übereinstimmen, die bei der 
//  Disp-Schnittstelle in der .ODL-Datei angegeben ist.

// {CFDB3166-0122-11D2-B51C-006097A8F69A}
static const IID IID_IStockChartAuto =
{ 0xcfdb3166, 0x122, 0x11d2, { 0xb5, 0x1c, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };

BEGIN_INTERFACE_MAP(CStockChartAutoDoc, CDocument)
	INTERFACE_PART(CStockChartAutoDoc, IID_IStockChartAuto, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoDoc Konstruktion/Destruktion

CStockChartAutoDoc::CStockChartAutoDoc()
{
	m_nID          = 0;
   m_bGrid        = false;
   m_bAverage     = false;
   m_nAverageCnt  = 15;
   m_ticker       = "";
   m_name         = "";
   m_nColor       = RGB(255,0,0);

   m_pChartProperty = NULL;


	EnableAutomation();

	AfxOleLockApp();
}

CStockChartAutoDoc::~CStockChartAutoDoc()
{
   // Wenn Dialog noch offen, dann schließen und löschen:
   if (m_pChartProperty) {
      m_pChartProperty->DestroyWindow ();
      delete m_pChartProperty;
   }

	AfxOleUnlockApp();
}

BOOL CStockChartAutoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoDoc Serialisierung

void CStockChartAutoDoc::Serialize(CArchive& ar)
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
// CStockChartAutoDoc Diagnose

#ifdef _DEBUG
void CStockChartAutoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockChartAutoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);

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
   dc << "\nDurchschnitt über " << m_nAverageCnt << " Werte.";

   dc << "\n";
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoDoc Befehle

void CStockChartAutoDoc::OnStockProperty() 
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

void CStockChartAutoDoc::OnChartProperty() 
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
//  CStockChartDoc::OnPropertyChange

void CStockChartAutoDoc::OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow)
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

void CStockChartAutoDoc::OnFileImport() 
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


void CStockChartAutoDoc::DeleteContents() 
{
	// Inhalt der Liste löschen:
   m_stockData.theData.RemoveAll ();

	CDocument::DeleteContents();
}


void CStockChartAutoDoc::CalcAverages () 
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


BOOL CStockChartAutoDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
   CalcAverages (); // Durchschnittslinie berechnen
   	
	return TRUE;
}


//====================== Automationsfunktionen =================

void CStockChartAutoDoc::ShowWindow() 
{
	POSITION pos = GetFirstViewPosition();
	CView* pView = GetNextView(pos);
	if (pView != NULL)
	{
		CFrameWnd* pFrameWnd = pView->GetParentFrame();
		pFrameWnd->ActivateFrame(SW_SHOW);
		pFrameWnd = pFrameWnd->GetParentFrame();
		if (pFrameWnd != NULL)
			pFrameWnd->ActivateFrame(SW_SHOW);
	}
}

long CStockChartAutoDoc::GetId() 
{
	return m_nID;
}

void CStockChartAutoDoc::SetId(long nNewValue) 
{
   m_nID = nNewValue;

   UpdateAllViews (NULL);
   SetModifiedFlag ();
}

BSTR CStockChartAutoDoc::GetName() 
{
	return m_name.AllocSysString();
}

void CStockChartAutoDoc::SetName(LPCTSTR lpszName) 
{
   m_name = lpszName;
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}

BSTR CStockChartAutoDoc::GetTicker() 
{
	return m_ticker.AllocSysString();
}

void CStockChartAutoDoc::SetTicker(LPCTSTR lpszTicker) 
{
   m_ticker = lpszTicker;
   m_ticker.MakeUpper ();
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}


void CStockChartAutoDoc::SetColor(short red, short green, short blue) 
{
   m_nColor = RGB (red,green,blue);
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}

LPDISPATCH CStockChartAutoDoc::GetStatusbar() 
{
   CStatusBarInterface *statusBar;
   LPDISPATCH lpResult;

   // CStatusBarInterface-Objekt löscht sich selbst, wenn keine Referenzen
   // mehr auf die Schnittstelle vorhanden sind.
   statusBar = new CStatusBarInterface ();

   // Zeiger auf IDispatch-Schnittstelle besorgen:
   lpResult = statusBar->GetIDispatch (false);

   return lpResult;
}



BOOL CStockChartAutoDoc::GetAverage() 
{
	return m_bAverage;
}

void CStockChartAutoDoc::SetAverage(BOOL bAverage) 
{
   m_bAverage = bAverage;
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}

long CStockChartAutoDoc::GetAveragecnt() 
{
	return m_nAverageCnt;
}


void CStockChartAutoDoc::SetAveragecnt(long nAverageCnt) 
{
   if (nAverageCnt < 0)
      nAverageCnt = 0;
   else if (nAverageCnt > 20)
      nAverageCnt = 20;

   m_nAverageCnt = nAverageCnt;
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}


BOOL CStockChartAutoDoc::GetGrid() 
{
	return m_bGrid;
}


void CStockChartAutoDoc::SetGrid(BOOL bGrid) 
{
   m_bGrid = bGrid;
   UpdateAllViews (NULL);
   SetModifiedFlag ();
}


BOOL CStockChartAutoDoc::SaveFile(LPCTSTR pathName) 
{
	return OnSaveDocument (pathName);
}


BOOL CStockChartAutoDoc::ImportFile(LPCTSTR pathName) 
{
   DeleteContents ();

   try {
      CStdioFile file (pathName, CFile::typeText);
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
   
      // Durchschnittslinie berechnen:
      CalcAverages ();

      // Alle Ansichten aktualisieren:
      UpdateAllViews (NULL);
      // Als verändert kennzeichnen:
		SetModifiedFlag ();

      return true;  // Erfolg
   }
   catch (CFileException *e) {
      e->Delete (); 
      return false;  // Fehler
   }
}
