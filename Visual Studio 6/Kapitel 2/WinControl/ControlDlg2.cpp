// ControlDlg2.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "ControlDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg2 


CControlDlg2::CControlDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CControlDlg2::IDD, pParent)
{
	m_nSlider = 0;
	m_strRichEdit = _T("");
   m_nProgress = 0;
}


void CControlDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_nSlider);
	//DDX_Text(pDX, IDC_RICHEDIT1, m_strRichEdit);

   // Zeiger auf Steuerelemente besorgen
   CProgressCtrl *pc = (CProgressCtrl*) GetDlgItem (IDC_PROGRESS1);
   CTreeCtrl *tr = (CTreeCtrl*) GetDlgItem (IDC_TREE1);

   // Datenaustausch
   // Dialog => Anwendung
   if (pDX->m_bSaveAndValidate) {
      if (tr->GetSelectedItem ())
         m_strTree = tr->GetItemText (tr->GetSelectedItem ());
      else 
         m_strTree = _T("");
   }
   // Anwendung => Dialog
   else {
      if (progressMin <= m_nProgress && m_nProgress <= progressMax)
         pc->SetPos (m_nProgress);
      m_strList = _T(""); // Initialisierung
   }

}


BEGIN_MESSAGE_MAP(CControlDlg2, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CControlDlg2 

BOOL CControlDlg2::OnInitDialog() 
{
	CDialog::OnInitDialog();

   // === Drehfeld ===
   CSpinButtonCtrl *sb = (CSpinButtonCtrl*) GetDlgItem (IDC_SPIN1);
   sb->SetRange (spinMin,spinMax);

   // === Statusanzeige ===
   CProgressCtrl *pc = (CProgressCtrl*) GetDlgItem (IDC_PROGRESS1);
   pc->SetRange (progressMin, progressMax);
     	
   // === Regler ===
   CSliderCtrl *sl = (CSliderCtrl*) GetDlgItem (IDC_SLIDER1);
   sl->SetRange (sliderMin, sliderMax, true);

   // === Animation ===
   CAnimateCtrl *ani = (CAnimateCtrl*)GetDlgItem (IDC_ANIMATE1);
   ani->Open (IDR_AVI1);
   ani->Play (0,-1,-1);

   // === Rich Edit ===
   CRichEditCtrl *re = (CRichEditCtrl*) GetDlgItem (IDC_RICHEDIT21);
   CHARFORMAT cf;

   re->SetWindowText (_T("Live long and prosper!"));

   // Das erste Wort fett
   re->SetSel (0,4);
   cf.cbSize = sizeof(CHARFORMAT);
   cf.dwMask = CFM_BOLD;
   cf.dwEffects = CFM_BOLD;
   re->SetSelectionCharFormat (cf);

   // Das zweite mit anderer Schriftart und Größe
   re->SetSel (5,10);
   cf.dwMask = CFM_SIZE | CFM_FACE;
   cf.yHeight = 250;
   strcpy (cf.szFaceName, _T("Arial"));
   re->SetSelectionCharFormat (cf);

   // Das letzte Wort rot und unterstrichen
   re->SetSel (14,21);
   cf.dwMask = CFM_COLOR | CFM_UNDERLINE;
   cf.dwEffects = CFM_UNDERLINE;
   cf.crTextColor = RGB (255,0,0);
   re->SetSelectionCharFormat (cf);

   // Selektion aufheben
   re->SetSel (0,0);

	// === Bilderliste für Listenelement und Strukturansicht ===
   m_ImageList.Create (16,16,0,4,4);
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON1));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON2));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON3));
   m_ImageList.Add (AfxGetApp()->LoadIcon (IDI_ICON4));

   // === Listenelement ===
   CListCtrl *lc = (CListCtrl*) GetDlgItem (IDC_LIST1);
   lc->SetImageList (&m_ImageList, LVSIL_SMALL);
   lc->InsertItem (0, _T("Kreuz"), 0);
   lc->InsertItem (1, _T("Chaos"), 1);
   lc->InsertItem (2, _T("Diamant"), 2);
   lc->InsertItem (3, _T("Karos"), 3);

   // === Strukturansicht ===
   CTreeCtrl *tr = (CTreeCtrl*) GetDlgItem (IDC_TREE1);
   HTREEITEM hTreeItem;
   tr->SetImageList (&m_ImageList, TVSIL_NORMAL);
   hTreeItem = tr->InsertItem (_T("Chaos"), 1, 1);
               tr->InsertItem (_T("Karos"), 3, 3, hTreeItem);
   hTreeItem = tr->InsertItem (_T("Kreuz"), 0, 0, hTreeItem);
               tr->InsertItem (_T("Diamant"), 2, 2, hTreeItem);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}

void CControlDlg2::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

   int nSelected = pNMListView->iItem;
   CListCtrl *lc = (CListCtrl*) GetDlgItem (IDC_LIST1);

   if (nSelected >= 0) 
      m_strList = lc->GetItemText (nSelected, 0);

	*pResult = 0;
}

