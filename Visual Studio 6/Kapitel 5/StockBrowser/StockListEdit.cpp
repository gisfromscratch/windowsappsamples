// StocklistEdit.cpp : implementation file
//

#include "stdafx.h"
#include "StockBrowser.h"
#include "StocklistEdit.h"

#include "StockBrowserDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockListEdit dialog


CStockListEdit::CStockListEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CStockListEdit::IDD, pParent)
{
	m_nIDtoAdd = 0;

    pStockList = NULL;
}


void CStockListEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ADD, m_nIDtoAdd);
	DDV_MinMaxLong(pDX, m_nIDtoAdd, 0, 999999);
}


BEGIN_MESSAGE_MAP(CStockListEdit, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE, OnButtonRemove)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockListEdit message handlers

void CStockListEdit::OnButtonAdd() 
{
	CString str;

   UpdateData ();
   str.Format ("%li", m_nIDtoAdd);

   CListBox *list = (CListBox*)GetDlgItem (IDC_LIST_STOCK);
	list->AddString (str);
   list->SelectString (-1, str);
}

void CStockListEdit::OnButtonRemove() 
{
   CListBox *list = (CListBox*)GetDlgItem (IDC_LIST_STOCK);
   list->DeleteString (list->GetCurSel ());
   list->SetCurSel (0);	
}


BOOL CStockListEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (pStockList && !pStockList->m_theList.IsEmpty()) {
      CListBox *list = (CListBox*)GetDlgItem (IDC_LIST_STOCK);
      POSITION pos = pStockList->m_theList.GetHeadPosition ();

      while (pos != NULL) 
         list->AddString (pStockList->m_theList.GetNext (pos));

      list->SetCurSel (0);

   }

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStockListEdit::SetStockList (CStockList * pStockList)
{
   this->pStockList = pStockList;
}

void CStockListEdit::OnOK() 
{
   // die Liste neu aufbauen
   if (pStockList) {
      CString str;

      // zunächst löschen
      pStockList->EmptyList ();

      // Zeiger auf ListBox besorgen
      CListBox *list = (CListBox*)GetDlgItem (IDC_LIST_STOCK);
      
      // Liste aus der Listbox kopieren
      for (int i=0; i<list->GetCount (); i++) {
         list->GetText (i, str);
         pStockList->m_theList.AddTail (str);
      }
   }
	
	CDialog::OnOK();
}
