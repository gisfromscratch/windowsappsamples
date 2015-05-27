// SliderPage.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "SliderPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseite CSliderPage 

IMPLEMENT_DYNCREATE(CSliderPage, CPropertyPage)

CSliderPage::CSliderPage() : CPropertyPage(CSliderPage::IDD)
{
}

CSliderPage::~CSliderPage()
{
}

void CSliderPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSliderPage, CPropertyPage)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CSliderPage 
