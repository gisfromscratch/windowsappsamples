// ControlDlg1.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "WinControl.h"
#include "ControlDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg1 


CControlDlg1::CControlDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CControlDlg1::IDD, pParent)
{
	m_bCheck = FALSE;
	m_strEdit = _T("");
	m_nRadio = -1;
	m_strCombo = _T("");
	m_strStatic = _T("");
	m_strList = _T("");
	m_nScroll = 0;
}


void CControlDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Check(pDX, IDC_CHECK1, m_bCheck);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);
	DDV_MaxChars(pDX, m_strEdit, 10);
	DDX_Radio(pDX, IDC_RADIO1, m_nRadio);
	DDX_CBString(pDX, IDC_COMBO1, m_strCombo);
	DDV_MaxChars(pDX, m_strCombo, 20);
	DDX_Text(pDX, IDC_STATIC1, m_strStatic);
	DDV_MaxChars(pDX, m_strStatic, 20);
	DDX_LBString(pDX, IDC_LIST1, m_strList);
	DDX_Scroll(pDX, IDC_SCROLLBAR1, m_nScroll);
}


BEGIN_MESSAGE_MAP(CControlDlg1, CDialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CControlDlg1 

BOOL CControlDlg1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
   // Initialisierung des Listenfelds:
   CListBox *lb = (CListBox*) GetDlgItem (IDC_LIST1);

   lb->InsertString (-1, "Hamburg");
   lb->InsertString (-1, "Berlin");
   lb->InsertString (-1, "Köln");
   lb->InsertString (-1, "München");
   lb->SetCurSel (1);

   // Bildlaufleiste (ScrollBar) initialisieren:
   CScrollBar *sb = (CScrollBar*) GetDlgItem (IDC_SCROLLBAR1);
   sb->SetScrollRange (scrollMin, scrollMax, FALSE);
   sb->SetScrollPos ((scrollMax-scrollMin)/2);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}

void CControlDlg1::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
   UINT nCurrentPos;

   nCurrentPos = pScrollBar->GetScrollPos ();

   switch (nSBCode) {
      case SB_THUMBPOSITION:
         pScrollBar->SetScrollPos (nPos);
         break;

      case SB_LINELEFT:
         pScrollBar->SetScrollPos (max (scrollMin, nCurrentPos-1));
         break;

      case SB_LINERIGHT:
         pScrollBar->SetScrollPos (min (scrollMax, nCurrentPos+1));
         break;

      case SB_PAGELEFT:
         pScrollBar->SetScrollPos (max (scrollMin, nCurrentPos-scrollPage));
         break;

      case SB_PAGERIGHT:
         pScrollBar->SetScrollPos (min (scrollMax, nCurrentPos+scrollPage));
         break;
   }
   	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
