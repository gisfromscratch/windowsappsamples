#pragma once

// StocklistEdit.h : header file
//

class CStockList;

/////////////////////////////////////////////////////////////////////////////
// CStockListEdit dialog

class CStockListEdit : public CDialog
{
// Construction
public:
	CStockListEdit(CWnd* pParent = NULL);   // standard constructor

   void SetStockList (CStockList * pStockList);

// Dialog Data
	enum { IDD = IDD_DIALOG_STOCK };
	long	m_nIDtoAdd;


// Overrides
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support


// Implementation
protected:
   CStockList *pStockList;

	afx_msg void OnButtonAdd();
	afx_msg void OnButtonRemove();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	DECLARE_MESSAGE_MAP()
};

