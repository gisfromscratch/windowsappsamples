// StockChooser.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "DAOChart.h"
#include "StockChooser.h"

#include "Shares.h"

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
// Behandlungsroutinen für Nachrichten CStockChooser 


BOOL CStockChooser::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
   CShares shares;

   // Listenfeld des Dialogs besorgen:
   CListBox *lb = (CListBox*) GetDlgItem (IDC_LIST1);

   try {
      // Satzgruppe öffnen
      shares.Open ();

      // prüfen ob Satzgruppe leer
      if (shares.IsBOF ()) {
         // leer
         shares.Close ();
         return true;
      }

      // über die Satzgruppe
      // iterieren
      shares.MoveFirst ();
      while (!shares.IsEOF ()) {
         // Aktienname der ListBox zufügen
         lb->AddString (shares.m_Aktienname);
         shares.MoveNext ();
      }

	   // Satzgruppe schließen
      shares.Close ();   

      // ListBox auf erstes Element setzen
      lb->SetCurSel (0);
   }
   catch (CDaoException *e) {
      e->ReportError ();
      e->Delete ();
   }	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}


// Doppelklick auf ListBox
void CStockChooser::OnDblclkList1() 
{
   // Daten übertragen
   UpdateData ();
   // Dialog schließen
   EndDialog (IDOK);
}
