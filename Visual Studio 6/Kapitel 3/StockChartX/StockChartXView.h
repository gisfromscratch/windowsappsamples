// StockChartXView.h : Schnittstelle der Klasse CStockChartXView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTXVIEW_H__FC8ACC20_231B_11D2_B593_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTXVIEW_H__FC8ACC20_231B_11D2_B593_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartXView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartXView();
	DECLARE_DYNCREATE(CStockChartXView)

// Attribute
public:
	CStockChartXDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartXView)
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockChartXView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartXView)
	afx_msg void OnCancelEditSrvr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockChartXView.cpp
inline CStockChartXDoc* CStockChartXView::GetDocument()
   { return (CStockChartXDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTXVIEW_H__FC8ACC20_231B_11D2_B593_006097A8F69A__INCLUDED_)
