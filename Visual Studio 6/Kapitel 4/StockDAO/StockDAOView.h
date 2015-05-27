// StockDAOView.h : Schnittstelle der Klasse CStockDAOView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKDAOVIEW_H__8573C01D_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_STOCKDAOVIEW_H__8573C01D_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockDAOSet;

class CStockDAOView : public CDaoRecordView
{
protected: // Nur aus Serialisierung erzeugen
	CStockDAOView();
	DECLARE_DYNCREATE(CStockDAOView)

public:
	//{{AFX_DATA(CStockDAOView)
	enum { IDD = IDD_STOCKDAO_FORM };
	CStockDAOSet* m_pSet;
	//}}AFX_DATA

// Attribute
public:
	CStockDAODoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockDAOView)
	public:
	virtual CDaoRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	virtual void OnInitialUpdate(); // das erste mal nach der Konstruktion aufgerufen
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockDAOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockDAOView)
	afx_msg void OnRecordNew();
	afx_msg void OnRecordDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
   bool m_bNewRecord;
};

#ifndef _DEBUG  // Testversion in StockDAOView.cpp
inline CStockDAODoc* CStockDAOView::GetDocument()
   { return (CStockDAODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKDAOVIEW_H__8573C01D_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
