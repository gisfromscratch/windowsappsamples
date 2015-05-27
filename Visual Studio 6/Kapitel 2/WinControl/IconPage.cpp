// IconPage.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "IconPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseite CIconPage 

IMPLEMENT_DYNCREATE(CIconPage, CPropertyPage)

CIconPage::CIconPage() : CPropertyPage(CIconPage::IDD)
{
}

CIconPage::~CIconPage()
{
}

void CIconPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CIconPage, CPropertyPage)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CIconPage 


