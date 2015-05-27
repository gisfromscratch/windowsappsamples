// WinControlView.h : Schnittstelle der Klasse CWinControlView
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CWinControlView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CWinControlView();
	DECLARE_DYNCREATE(CWinControlView)

// Attribute
public:
	CWinControlDoc* GetDocument();

// Operationen
public:

// Überladungen
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:

// Implementierung
public:
	virtual ~CWinControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	afx_msg void OnControlsPart1();
	afx_msg void OnControlsPart2();
	afx_msg void OnControlsProperty();
	afx_msg void OnControlsPart3();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in WinControlView.cpp
inline CWinControlDoc* CWinControlView::GetDocument()
   { return (CWinControlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

