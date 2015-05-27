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
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBDoc Konstruktion/Destruktion

CStockOLEDBDoc::CStockOLEDBDoc()
{
	// ZU ERLEDIGEN: Hier Code für One-Time-Konstruktion einfügen

}

CStockOLEDBDoc::~CStockOLEDBDoc()
{
}

BOOL CStockOLEDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
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
