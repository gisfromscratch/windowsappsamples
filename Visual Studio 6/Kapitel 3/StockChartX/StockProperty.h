#ifndef AFX_STOCKPROPERTY_H__F0309C61_0C7B_11D2_B53C_006097A8F69A__INCLUDED_
#define AFX_STOCKPROPERTY_H__F0309C61_0C7B_11D2_B53C_006097A8F69A__INCLUDED_

// StockProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockProperty 

class CStockProperty : public CDialog
{
// Konstruktion
public:
	CStockProperty(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CStockProperty)
	enum { IDD = IDD_STOCKPROPERTY };
	CString	m_name;
	int		m_nID;
	CString	m_ticker;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CStockProperty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CStockProperty)
		// HINWEIS: Der Klassen-Assistent fügt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_STOCKPROPERTY_H__F0309C61_0C7B_11D2_B53C_006097A8F69A__INCLUDED_
