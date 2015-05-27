// StockChartUDTView.h : Schnittstelle der Klasse CStockChartUDTView
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartUDTView : public CView
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartUDTView();
	DECLARE_DYNCREATE(CStockChartUDTView)

// Attribute
public:
	CStockChartUDTDoc* GetDocument();

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartUDTView)
	public:
	virtual void OnDraw(CDC* pDC);  // überladen zum Zeichnen dieser Ansicht
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockChartUDTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartUDTView)
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ConvertAndStoreData (CString text);
	bool ExtractData (COleDataObject *pDataObject, CString& text);
	COleDataSource* PutData ();

	COleDropTarget m_dropTarget;
};

#ifndef _DEBUG  // Testversion in StockChartUDTView.cpp
inline CStockChartUDTDoc* CStockChartUDTView::GetDocument()
   { return (CStockChartUDTDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTVIEW_H__BEE13F94_B045_11D1_B433_006097A8F69A__INCLUDED_)
