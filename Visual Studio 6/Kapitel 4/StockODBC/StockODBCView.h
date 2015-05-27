// StockODBCView.h : Schnittstelle der Klasse CStockODBCView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKODBCVIEW_H__39EDB6E0_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
#define AFX_STOCKODBCVIEW_H__39EDB6E0_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockODBCSet;

class CStockODBCView : public CRecordView
{
protected: // Nur aus Serialisierung erzeugen
	CStockODBCView();
	DECLARE_DYNCREATE(CStockODBCView)

public:
	//{{AFX_DATA(CStockODBCView)
	enum { IDD = IDD_STOCKODBC_FORM };
	CStockODBCSet* m_pSet;
	//}}AFX_DATA

// Attribute
public:
	CStockODBCDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockODBCView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	virtual void OnInitialUpdate(); // das erste mal nach der Konstruktion aufgerufen
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockODBCView)
	afx_msg void OnRecordNew();
	afx_msg void OnRecordDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
   bool m_bNewRecord;
};

#ifndef _DEBUG  // Testversion in StockODBCView.cpp
inline CStockODBCDoc* CStockODBCView::GetDocument()
   { return (CStockODBCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKODBCVIEW_H__39EDB6E0_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
