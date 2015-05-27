#ifndef AFX_CHARTPROPERTY_H__BEE13F9D_B045_11D1_B433_006097A8F69A__INCLUDED_
#define AFX_CHARTPROPERTY_H__BEE13F9D_B045_11D1_B433_006097A8F69A__INCLUDED_

// ChartProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CChartProperty 


class CStockChartWithDllDoc; // Vorw�rtsdeklaration


class CChartProperty : public CDialog
{
// Konstruktion
public:
	CChartProperty(CStockChartWithDllDoc *pDoc, CWnd* pParent = NULL); 

   BOOL Create();
// Dialogfelddaten
	//{{AFX_DATA(CChartProperty)
	enum { IDD = IDD_CHARTPROPERTY };
	BOOL	m_bGrid;
	int		m_nColor;
	BOOL	m_bAverage;
	int		m_nAverageCnt;
	//}}AFX_DATA

// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CChartProperty)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:
   enum {
      sliderRangeMin = 1,
      sliderRangeMax = 20
   };
   CStockChartWithDllDoc *pDoc;

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
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_CHARTPROPERTY_H__BEE13F9D_B045_11D1_B433_006097A8F69A__INCLUDED_
