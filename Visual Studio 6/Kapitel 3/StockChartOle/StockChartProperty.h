#ifndef AFX_STOCKCHARTPROPERTY_H__24EFF551_0C7A_11D2_B53C_006097A8F69A__INCLUDED_
#define AFX_STOCKCHARTPROPERTY_H__24EFF551_0C7A_11D2_B53C_006097A8F69A__INCLUDED_

// StockChartProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockChartProperty 

class CStockChartProperty : public CDialog
{
// Konstruktion
public:
	CStockChartProperty(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(CStockChartProperty)
	enum { IDD = IDD_STOCKPROPERTY };
	CString	m_name;
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CStockChartProperty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CStockChartProperty)
		// HINWEIS: Der Klassen-Assistent f�gt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_STOCKCHARTPROPERTY_H__24EFF551_0C7A_11D2_B53C_006097A8F69A__INCLUDED_
