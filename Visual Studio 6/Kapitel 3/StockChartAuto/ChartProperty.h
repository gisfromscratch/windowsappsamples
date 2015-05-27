#ifndef AFX_CHARTPROPERTY_H__CFDB317E_0122_11D2_B51C_006097A8F69A__INCLUDED_
#define AFX_CHARTPROPERTY_H__CFDB317E_0122_11D2_B51C_006097A8F69A__INCLUDED_

// ChartProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CChartProperty 

class CStockChartAutoDoc; // Vorwärtsdeklaration


class CChartProperty : public CDialog
{
// Konstruktion
public:
	CChartProperty(CStockChartAutoDoc *pDoc, CWnd* pParent = NULL);   // Standardkonstruktor

   BOOL Create ();

   // Dialogfelddaten
	//{{AFX_DATA(CChartProperty)
	enum { IDD = IDD_CHARTPROPERTY };
	BOOL	m_bGrid;
	int		m_nColor;
	BOOL	m_bAverage;
	int		m_nAverageCnt;
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CChartProperty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
   enum {
      sliderRangeMin = 1,
      sliderRangeMax = 20
   };
   CStockChartAutoDoc *pDoc;

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CChartProperty)
	afx_msg void OnApplyNow();
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_CHARTPROPERTY_H__CFDB317E_0122_11D2_B51C_006097A8F69A__INCLUDED_
