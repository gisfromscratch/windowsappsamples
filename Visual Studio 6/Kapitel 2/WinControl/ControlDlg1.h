#pragma once

// ControlDlg1.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg1 

class CControlDlg1 : public CDialog
{
// Konstruktion
public:
	CControlDlg1(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_DIALOG1 };
	BOOL	m_bCheck;
	CString	m_strEdit;
	int		m_nRadio;
	CString	m_strCombo;
	CString	m_strStatic;
	CString	m_strList;
	int		m_nScroll;


// Überschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
   enum {
      scrollMin  = 0,
      scrollMax  = 100,
      scrollPage = 10
   };

	// Generierte Nachrichtenzuordnungsfunktionen
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()
};

