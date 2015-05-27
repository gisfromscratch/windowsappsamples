// StockChartAutoView.h : Schnittstelle der Klasse CStockChartAutoView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTAUTOVIEW_H__CFDB3174_0122_11D2_B51C_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTAUTOVIEW_H__CFDB3174_0122_11D2_B51C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartAutoView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartAutoView();
	DECLARE_DYNCREATE(CStockChartAutoView)

// Attribute
public:
	CStockChartAutoDoc* GetDocument();

// Operationen
public:

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartAutoView)
	public:
	virtual void OnDraw(CDC* pDC);  // �berladen zum Zeichnen dieser Ansicht
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
	virtual ~CStockChartAutoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartAutoView)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockChartAutoView.cpp
inline CStockChartAutoDoc* CStockChartAutoView::GetDocument()
   { return (CStockChartAutoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTAUTOVIEW_H__CFDB3174_0122_11D2_B51C_006097A8F69A__INCLUDED_)
