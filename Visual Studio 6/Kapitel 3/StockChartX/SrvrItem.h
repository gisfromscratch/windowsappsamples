// SrvrItem.h : Schnittstelle der Klasse CStockChartXSrvrItem
//

#if !defined(AFX_SRVRITEM_H__FC8ACC23_231B_11D2_B593_006097A8F69A__INCLUDED_)
#define AFX_SRVRITEM_H__FC8ACC23_231B_11D2_B593_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartXSrvrItem : public CDocObjectServerItem
{
	DECLARE_DYNAMIC(CStockChartXSrvrItem)

// Konstruktoren
public:
	CStockChartXSrvrItem(CStockChartXDoc* pContainerDoc);

// Attribute
	CStockChartXDoc* GetDocument() const
		{ return (CStockChartXDoc*)CDocObjectServerItem::GetDocument(); }

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartXSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementierung
public:
	~CStockChartXSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // überladen für Dokument-E/A
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_SRVRITEM_H__FC8ACC23_231B_11D2_B593_006097A8F69A__INCLUDED_)
