// StockBrowserView.h : Schnittstelle der Klasse CStockBrowserView
//
/////////////////////////////////////////////////////////////////////////////

#pragma once


class CStockBrowserView : public CHtmlView
{
protected: // Nur aus Serialisierung erzeugen
	CStockBrowserView();
	DECLARE_DYNCREATE(CStockBrowserView)

// Attribute
public:
	CStockBrowserDoc* GetDocument();

   void NavigateURL ();

// Operations
public:

// Überladungen
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // das erste mal nach der Konstruktion aufgerufen

// Implementierung
public:
	virtual ~CStockBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	afx_msg void OnEditReload();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockBrowserView.cpp
inline CStockBrowserDoc* CStockBrowserView::GetDocument()
   { return (CStockBrowserDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

