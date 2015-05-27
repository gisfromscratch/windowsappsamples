// SrvrItem.h
// Schnittstelle der Klasse CStockChartOleSrvrItem
//

#if !defined(AFX_SRVRITEM_H__50CB22BB_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
#define AFX_SRVRITEM_H__50CB22BB_0C37_11D2_B53C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CStockChartOleSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CStockChartOleSrvrItem)

// Konstruktoren
public:
	CStockChartOleSrvrItem(CStockChartOleDoc* pContainerDoc);

// Attribute
	CStockChartOleDoc* GetDocument() const
		{ return (CStockChartOleDoc*)COleServerItem::GetDocument(); }

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartOleSrvrItem)
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);
	//}}AFX_VIRTUAL

// Implementierung
public:
	~CStockChartOleSrvrItem();
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

#endif // !defined(AFX_SRVRITEM_H__50CB22BB_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
