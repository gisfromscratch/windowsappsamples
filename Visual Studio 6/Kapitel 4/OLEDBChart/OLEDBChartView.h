// OLEDBChartView.h : Schnittstelle der Klasse COLEDBChartView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBCHARTVIEW_H__9222C92D_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_OLEDBCHARTVIEW_H__9222C92D_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COLEDBChartView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	COLEDBChartView();
	DECLARE_DYNCREATE(COLEDBChartView)

// Attribute
public:
	COLEDBChartDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(COLEDBChartView)
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
	virtual ~COLEDBChartView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(COLEDBChartView)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in OLEDBChartView.cpp
inline COLEDBChartDoc* COLEDBChartView::GetDocument()
   { return (COLEDBChartDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_OLEDBCHARTVIEW_H__9222C92D_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
