// StockOLEDBView.h : Schnittstelle der Klasse CStockOLEDBView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKOLEDBVIEW_H__9222C991_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_STOCKOLEDBVIEW_H__9222C991_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockOLEDBSet;

class CStockOLEDBView : public COleDBRecordView
{
protected: // Nur aus Serialisierung erzeugen
	CStockOLEDBView();
	DECLARE_DYNCREATE(CStockOLEDBView)

public:
	//{{AFX_DATA(CStockOLEDBView)
	enum { IDD = IDD_STOCKOLEDB_FORM };
	CStockOLEDBSet* m_pSet;
	CString	m_strShareName;
	long	m_nShareNo;
	CString	m_strTicker;
	long	m_nShareID;
	//}}AFX_DATA

// Attribute
public:
	CStockOLEDBDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockOLEDBView)
	public:
	virtual CRowset* OnGetRowset();
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
	virtual ~CStockOLEDBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockOLEDBView)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Testversion in StockOLEDBView.cpp
inline CStockOLEDBDoc* CStockOLEDBView::GetDocument()
   { return (CStockOLEDBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKOLEDBVIEW_H__9222C991_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
