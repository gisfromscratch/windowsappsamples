#if !defined(AFX_STOCKCHOOSER_H__55AC958D_53E1_11D2_B3CE_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHOOSER_H__55AC958D_53E1_11D2_B3CE_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StockChooser.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockChooser 

class CStockChooser : public CDialog
{
// Konstruktion
public:
	CStockChooser(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CStockChooser)
	enum { IDD = IDD_STOCKCHOOSER };
	CString	m_strShareName;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CStockChooser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CStockChooser)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_STOCKCHOOSER_H__55AC958D_53E1_11D2_B3CE_006097A8F69A__INCLUDED_
