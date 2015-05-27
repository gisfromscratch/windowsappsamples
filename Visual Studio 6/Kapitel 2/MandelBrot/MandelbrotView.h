// MandelbrotView.h : Schnittstelle der Klasse CMandelbrotView
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CMandelbrotView : public CScrollView
{
protected: // Nur aus Serialisierung erzeugen
	CMandelbrotView();
	DECLARE_DYNCREATE(CMandelbrotView)

// Attribute
public:
	CMandelbrotDoc* GetDocument();

// Operationen
public:

// Überladungen
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // das erste mal nach der Konstruktion aufgerufen

// Implementierung
public:
	virtual ~CMandelbrotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	LRESULT OnLineDone (WPARAM wParam, LPARAM lParam);

// Generierte Message-Map-Funktionen
protected:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in MandelbrotView.cpp
inline CMandelbrotDoc* CMandelbrotView::GetDocument()
   { return (CMandelbrotDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

