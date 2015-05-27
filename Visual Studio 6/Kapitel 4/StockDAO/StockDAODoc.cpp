// StockDAODoc.cpp : Implementierung der Klasse CStockDAODoc
//

#include "stdafx.h"
#include "StockDAO.h"

#include "StockDAOSet.h"
#include "StockDAODoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockDAODoc

IMPLEMENT_DYNCREATE(CStockDAODoc, CDocument)

BEGIN_MESSAGE_MAP(CStockDAODoc, CDocument)
	//{{AFX_MSG_MAP(CStockDAODoc)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockDAODoc Konstruktion/Destruktion

CStockDAODoc::CStockDAODoc()
{
	// ZU ERLEDIGEN: Hier Code für One-Time-Konstruktion einfügen

}

CStockDAODoc::~CStockDAODoc()
{
}

BOOL CStockDAODoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStockDAODoc Diagnose

#ifdef _DEBUG
void CStockDAODoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStockDAODoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStockDAODoc Befehle
