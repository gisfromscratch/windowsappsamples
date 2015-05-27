#pragma once

// ControlDlg3.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg3 

class CControlDlg3 : public CDialog
{
// Konstruktion
public:
	CControlDlg3(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_DIALOG3 };
	CTime	m_DateTimePicker;
	CTime	m_MonthCal;
	int		m_nComboEx;
    BYTE m_nIPf1, m_nIPf2, m_nIPf3, m_nIPf4;


// Überschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
   // Bilderliste für erweitertes Kombinationsfeld
   CImageList m_ImageList;

	// Generierte Nachrichtenzuordnungsfunktionen
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

