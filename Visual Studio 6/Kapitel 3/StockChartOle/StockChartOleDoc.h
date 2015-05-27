// StockChartOleDoc.h : Schnittstelle der Klasse CStockChartOleDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTOLEDOC_H__50CB22B6_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTOLEDOC_H__50CB22B6_0C37_11D2_B53C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxtempl.h>  // die Template Werkzeugklassen
#include "ChartProperty.h"

class CStockChartOleSrvrItem;

class CStockData 
{
public:
   double               min, max;
   CList<double,double> theData;

   void Serialize (CArchive& ar);
};

class CStockChartOleDoc : public COleServerDoc
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartOleDoc();
	DECLARE_DYNCREATE(CStockChartOleDoc)

// Attribute
public:
   BOOL     m_bGrid;        // Flag für Gitternetz
   BOOL     m_bAverage;     // Flag für Durchschnittslinie
   int      m_nAverageCnt;  // Anzahl der Werte für Durchschnitt
   COLORREF m_nColor;       // Farbe der Kurve
   CString  m_name;         // Name der Aktie
   CString  m_ticker;       // Ticker-Symbol  
   int      m_nID;          // WKN

   CStockData           m_stockData;   // hält die Kursdaten
   CList<double,double> m_averageData; // hält Daten der Durchschnittslinie

	CStockChartOleSrvrItem* GetEmbeddedItem()
		{ return (CStockChartOleSrvrItem*)COleServerDoc::GetEmbeddedItem(); }

protected:
   CChartProperty *m_pChartProperty;  // nichtmodaler Dialog   

// Operationen
public:
   void OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow);

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartOleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockChartOleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();  // Berechnet die Durchschnittslinie

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartOleDoc)
	afx_msg void OnChartProperty();
	afx_msg void OnFileImport();
	afx_msg void OnStockProperty();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTOLEDOC_H__50CB22B6_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
