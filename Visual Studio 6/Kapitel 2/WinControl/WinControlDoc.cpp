// WinControlDoc.cpp : Implementierung der Klasse CWinControlDoc
//

#include "stdafx.h"
#include "WinControl.h"

#include "WinControlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinControlDoc

IMPLEMENT_DYNCREATE(CWinControlDoc, CDocument)

BEGIN_MESSAGE_MAP(CWinControlDoc, CDocument)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinControlDoc Konstruktion/Destruktion

CWinControlDoc::CWinControlDoc()
{
	// ZU ERLEDIGEN: Hier Code f�r One-Time-Konstruktion einf�gen

}

CWinControlDoc::~CWinControlDoc()
{
}

BOOL CWinControlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// ZU ERLEDIGEN: Hier Code zur Reinitialisierung einf�gen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWinControlDoc Serialisierung

void CWinControlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// ZU ERLEDIGEN: Hier Code zum Speichern einf�gen
	}
	else
	{
		// ZU ERLEDIGEN: Hier Code zum Laden einf�gen
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWinControlDoc Diagnose

#ifdef _DEBUG
void CWinControlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinControlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinControlDoc Befehle
