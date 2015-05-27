// ControlDlg3.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "ControlDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg3 


CControlDlg3::CControlDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CControlDlg3::IDD, pParent)
{
	m_DateTimePicker = 0;
	m_MonthCal = 0;
	m_nComboEx = -1;
}


void CControlDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_DateTimePicker);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, m_MonthCal);
	DDX_CBIndex(pDX, IDC_COMBOBOXEX1, m_nComboEx);

   // IP Steuerelement
   CIPAddressCtrl *ipAddr = (CIPAddressCtrl*) GetDlgItem (IDC_IPADDRESS1);

   if (pDX->m_bSaveAndValidate) 
      ipAddr->GetAddress (m_nIPf1, m_nIPf2, m_nIPf3, m_nIPf4);
   else 
      ipAddr->SetAddress (m_nIPf1, m_nIPf2, m_nIPf3, m_nIPf4);
}


BEGIN_MESSAGE_MAP(CControlDlg3, CDialog)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CControlDlg3 

BOOL CControlDlg3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// === Bilderliste für erweitertes Kombinationsfeld ===
   m_ImageList.Create (16,16,0,4,4);
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON1));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON2));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON3));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON4));


   CComboBoxEx *cb = (CComboBoxEx*) GetDlgItem (IDC_COMBOBOXEX1);
   cb->SetImageList (&m_ImageList);

   COMBOBOXEXITEM cbItem;
   CString str;

   str = _T("Kreuz");
   cbItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
   cbItem.iItem = 0;
   cbItem.pszText = (LPTSTR)(LPCTSTR)str;
   cbItem.cchTextMax = str.GetLength ();
   cbItem.iSelectedImage = 0;
   cbItem.iImage = 0;
   cb->InsertItem (&cbItem);

   str = _T("Chaos");
   cbItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
   cbItem.iItem = 1;
   cbItem.pszText = (LPTSTR)(LPCTSTR)str;
   cbItem.cchTextMax = str.GetLength ();
   cbItem.iSelectedImage = 1;
   cbItem.iImage = 1;
   cb->InsertItem (&cbItem);

   str = _T("Diamant");
   cbItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
   cbItem.iItem = 2;
   cbItem.pszText = (LPTSTR)(LPCTSTR)str;
   cbItem.cchTextMax = str.GetLength ();
   cbItem.iSelectedImage = 2;
   cbItem.iImage = 2;
   cb->InsertItem (&cbItem);

   str = _T("Karos");
   cbItem.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
   cbItem.iItem = 3;
   cbItem.pszText = (LPTSTR)(LPCTSTR)str;
   cbItem.cchTextMax = str.GetLength ();
   cbItem.iSelectedImage = 3;
   cbItem.iImage = 3;
   cb->InsertItem (&cbItem);

   // dritten Eintrag selektieren
   cb->SetCurSel (2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}
