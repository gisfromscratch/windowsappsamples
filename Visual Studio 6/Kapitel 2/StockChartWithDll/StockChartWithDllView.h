// StockChartWithDllView.h : Schnittstelle der Klasse CStockChartWithDllView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartWithDllView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartWithDllView();
	DECLARE_DYNCREATE(CStockChartWithDllView)

// Attribute
public:
	CStockChartWithDllDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartWithDllView)
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
	virtual ~CStockChartWithDllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartWithDllView)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockChartWithDllView.cpp
inline CStockChartWithDllDoc* CStockChartWithDllView::GetDocument()
   { return (CStockChartWithDllDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_)
