// StockBrowserDoc.cpp : Implementierung der Klasse CStockBrowserDoc
//

#include "stdafx.h"
#include "StockBrowser.h"

#include "StockBrowserDoc.h"
#include "StockBrowserView.h"
#include "StockListEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserDoc

IMPLEMENT_DYNCREATE(CStockBrowserDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockBrowserDoc, CDocument)
	ON_COMMAND(ID_EDIT_LIST, OnEditList)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserDoc Konstruktion/Destruktion

CStockBrowserDoc::CStockBrowserDoc()
{
}

CStockBrowserDoc::~CStockBrowserDoc()
{
}

BOOL CStockBrowserDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockBrowserDoc Serialisierung

void CStockBrowserDoc::Serialize(CArchive& ar)
{
   m_stockList.m_theList.Serialize (ar);
}

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserDoc Diagnose

#ifdef _DEBUG
void CStockBrowserDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockBrowserDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserDoc commands

void CStockBrowserDoc::OnEditList() 
{
   CStockListEdit stockListEdit;
   
   // Liste an den Dialog übergeben
   stockListEdit.SetStockList (&m_stockList); 
   // Dialog aufrufen
   stockListEdit.DoModal ();
   
   // jetzt allen Ansichten "Bescheid sagen"
   POSITION pos = GetFirstViewPosition();
   while (pos != NULL)   {
      CStockBrowserView* pView = (CStockBrowserView*) GetNextView(pos);
      pView->NavigateURL ();
   }  

   SetModifiedFlag ();
}


CString CStockBrowserDoc::GetURL () const
{
   CString str;

   if (m_stockList.m_theList.IsEmpty ()) {
      str = _T("about:blank");
   }
   else {
      POSITION pos = m_stockList.m_theList.GetHeadPosition ();

      str = _T("http://de.finance.yahoo.com/q?s=");
      if (pos != NULL)
	  {
		 str += m_stockList.m_theList.GetNext (pos) + _T(".F");
	  }
      while (pos != NULL) 
	  {
         str += _T("+") + m_stockList.m_theList.GetNext (pos) + _T(".F");
	  }
   }

   return str;
}


//////////////////////////////////////////////////////////////////////////
// CStockList Funktionen

void CStockList::EmptyList ()
{
   m_theList.RemoveAll();
}
