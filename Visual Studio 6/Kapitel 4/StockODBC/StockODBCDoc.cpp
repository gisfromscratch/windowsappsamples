// StockODBCDoc.cpp : Implementierung der Klasse CStockODBCDoc
//

#include "stdafx.h"
#include "StockODBC.h"

#include "StockODBCSet.h"
#include "StockODBCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockODBCDoc

IMPLEMENT_DYNCREATE(CStockODBCDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockODBCDoc, CDocument)
	//{{AFX_MSG_MAP(CStockODBCDoc)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockODBCDoc Konstruktion/Destruktion

CStockODBCDoc::CStockODBCDoc()
{
	// ZU ERLEDIGEN: Hier Code f�r One-Time-Konstruktion einf�gen

}

CStockODBCDoc::~CStockODBCDoc()
{
}

BOOL CStockODBCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockODBCDoc Diagnose

#ifdef _DEBUG
void CStockODBCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockODBCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockODBCDoc Befehle
