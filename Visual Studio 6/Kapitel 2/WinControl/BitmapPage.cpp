// BitmapPage.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "BitmapPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseite CBitmapPage 

IMPLEMENT_DYNCREATE(CBitmapPage, CPropertyPage)

CBitmapPage::CBitmapPage() : CPropertyPage(CBitmapPage::IDD)
{
}

CBitmapPage::~CBitmapPage()
{
}

void CBitmapPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBitmapPage, CPropertyPage)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CBitmapPage 
