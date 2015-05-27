// PropertyDialog.cpp: Implementierungsdatei
// 
#include "stdafx.h"
#include "WinControl.h"
#include "PropertyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertyDialog

IMPLEMENT_DYNAMIC(CPropertyDialog, CPropertySheet)

CPropertyDialog::CPropertyDialog(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
   m_psh.dwFlags |= PSH_NOAPPLYNOW;

   AddPage (&m_IconPage);
   AddPage (&m_SliderPage);
   AddPage (&m_BitmapPage);
}

CPropertyDialog::CPropertyDialog(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
   m_psh.dwFlags |= PSH_NOAPPLYNOW;
 
   AddPage (&m_IconPage);
   AddPage (&m_SliderPage);
   AddPage (&m_BitmapPage);
}

CPropertyDialog::~CPropertyDialog()
{
}


BEGIN_MESSAGE_MAP(CPropertyDialog, CPropertySheet)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CPropertyDialog 
