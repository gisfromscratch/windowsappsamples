// StockOLEDBDoc.cpp : Implementierung der Klasse CStockOLEDBDoc
//

#include "stdafx.h"
#include "StockOLEDB.h"

#include "StockOLEDBSet.h"
#include "StockOLEDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBDoc

IMPLEMENT_DYNCREATE(CStockOLEDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CStockOLEDBDoc, CDocument)
	//{{AFX_MSG_MAP(CStockOLEDBDoc)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBDoc Konstruktion/Destruktion

CStockOLEDBDoc::CStockOLEDBDoc()
{
	// ZU ERLEDIGEN: Hier Code f�r One-Time-Konstruktion einf�gen

}

CStockOLEDBDoc::~CStockOLEDBDoc()
{
}

BOOL CStockOLEDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBDoc Diagnose

#ifdef _DEBUG
void CStockOLEDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockOLEDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBDoc Befehle
