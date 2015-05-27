// FileRobotDlg.h : Header-Datei
//

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CFileRobotDlg Dialogfeld

class CFileRobotDlg : public CDialog
{
// Konstruktion
public:
	CFileRobotDlg(CWnd* pParent = NULL);	// standard constructor
   ~CFileRobotDlg ();

// Dialogfelddaten
	enum { IDD = IDD_FILEROBOT_DIALOG };
	CString	m_strURL;
	CString	m_strFileName;
	CString	m_strStatus;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung

// Implementierung
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAddFile();
	afx_msg void OnButtonRemoveFile();
	afx_msg void OnButtonStart();

	DECLARE_MESSAGE_MAP()

private:
	bool GetHTTPFile (const CString& strURL);
	CInternetSession* m_pSession;

	CString CreateURL (const CString& strURL, const CString& strFile) const;
};

