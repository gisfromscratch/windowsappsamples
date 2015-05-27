// SquareClientDlg.h : Header-Datei
//

#pragma once

#include "unknwn.h"

////////////////////////////////////////////////////
// Definition der ISquare-Schnittstelle:
interface ISquare : public IUnknown
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetSquare (long value, long *pnResult) = 0;
};


/////////////////////////////////////////////////////////////////////////////
// CSquareClientDlg Dialogfeld

class CSquareClientDlg : public CDialog
{
// Konstruktion
public:
	CSquareClientDlg(CWnd* pParent = NULL);	// Standard-Konstruktor
   ~CSquareClientDlg ();

// Dialogfelddaten
	enum { IDD = IDD_SQUARECLIENT_DIALOG };
	CString	m_strOut;
	long	m_nIn;
	CString	m_strMessage;

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioATL();
	afx_msg void OnRadioCpp();
	afx_msg void OnRadioCppNested();
	afx_msg void OnRadioMFC();
	virtual void OnOK();
	DECLARE_MESSAGE_MAP()
private:
	void EnableInput (BOOL bEnable);
   ISquare *m_pISquare;

	void ShowCOMError (HRESULT hRes);
	BOOL AttachToServer (const CString &strCLSID);
};

