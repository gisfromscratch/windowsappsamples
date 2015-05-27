// StockChartDebugView.h : Schnittstelle der Klasse CStockChartDebugView
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CStockChartDebugView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartDebugView();
	DECLARE_DYNCREATE(CStockChartDebugView)

// Attribute
public:
	CStockChartDebugDoc* GetDocument();

// Operationen
public:

// Überladungen
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementierung
public:
	virtual ~CStockChartDebugView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	afx_msg void OnDumpDocument();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockChartDebugView.cpp
inline CStockChartDebugDoc* CStockChartDebugView::GetDocument()
   { return (CStockChartDebugDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

