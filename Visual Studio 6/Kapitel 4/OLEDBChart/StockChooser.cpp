// StockChooser.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "OLEDBChart.h"
#include "StockChooser.h"

#include "Share.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockChooser 


CStockChooser::CStockChooser(CWnd* pParent /*=NULL*/)
	: CDialog(CStockChooser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockChooser)
	m_strShareName = _T("");
	//}}AFX_DATA_INIT
}


void CStockChooser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockChooser)
	DDX_LBString(pDX, IDC_LIST1, m_strShareName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockChooser, CDialog)
	//{{AFX_MSG_MAP(CStockChooser)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen f�r Nachrichten CStockChooser 

BOOL CStockChooser::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Rowset
   CShare share;
   // Listenfeld des Dialogs besorgen:
   CListBox *lb = (CListBox*) GetDlgItem (IDC_LIST1);

   if (S_OK != share.Open ()) {
      MessageBox (_T("Konnte nicht auf Datenbank zugreifen"));
      return true;
   }

   // Aktiennamen in das Listenfeld
   // kopieren
   while (share.MoveNext () == S_OK)
      lb->AddString (share.m_Aktienname);

   // ListBox auf erstes Element setzen
   lb->SetCurSel (0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zur�ckgeben
}

void CStockChooser::OnDblclkList1() 
{
   // Daten �bertragen
   UpdateData ();
   // Dialog schlie�en
   EndDialog (IDOK);
}
