#pragma once

// ChartProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CChartProperty 


class CStockChartDebugDoc; // Vorwärtsdeklaration


class CChartProperty : public CDialog
{
// Konstruktion
public:
	CChartProperty(CStockChartDebugDoc *pDoc, CWnd* pParent = NULL); 

   BOOL Create();
// Dialogfelddaten
	enum { IDD = IDD_CHARTPROPERTY };
	BOOL	m_bGrid;
	int		m_nColor;
	BOOL	m_bAverage;
	int		m_nAverageCnt;

// Überschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
   enum {
      sliderRangeMin = 1,
      sliderRangeMax = 20
   };
   CStockChartDebugDoc *pDoc;

	// Generierte Nachrichtenzuordnungsfunktionen
	afx_msg void OnApplyNow();
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
};

