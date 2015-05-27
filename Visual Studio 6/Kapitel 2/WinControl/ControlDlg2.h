#pragma once

// ControlDlg2.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CControlDlg2 

class CControlDlg2 : public CDialog
{
// Konstruktion
public:
	CControlDlg2(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_DIALOG2 };
	int		m_nSlider;    // DDX-Variablen
	CString	m_strRichEdit;
   
   // Definition der (nicht-DDX) Austauschvariablen
   int m_nProgress;       // Statusanzeige
   CString m_strList;     // Listenelement
   CString m_strTree;     // Strukturansicht

// �berschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
   // Wertebereiche f�r das Drehfeld die Statusanzeige und den Regler
   enum {
      spinMin = 0,
      spinMax = 100,
      progressMin = 0,
      progressMax = 50,
      progressStep = 1,
      sliderMin = 0,
      sliderMax = 200
   };

   // Bilderliste f�r Listenelement und Strukturansicht
   CImageList m_ImageList;

	// Generierte Nachrichtenzuordnungsfunktionen
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
};

