// StockChartUDTDoc.h : Schnittstelle der Klasse CStockChartUDTDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTDOC_H__BEE13F92_B045_11D1_B433_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTDOC_H__BEE13F92_B045_11D1_B433_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxtempl.h>  // die Template Werkzeugklassen
#include "ChartProperty.h"

class CStockData 
{
public:
   double               min, max;
   CList<double,double> theData;

   void Serialize (CArchive& ar);
};


class CStockChartUDTDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartUDTDoc();
	DECLARE_DYNCREATE(CStockChartUDTDoc)

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

   bool     m_bDrag;        // Drag und Drop in gleiches Dokument verhindern
protected:
   CChartProperty *m_pChartProperty;  // nichtmodaler Dialog   

// Operationen
public:
   void OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow);
   void SetStockData (const int id, const CString& name, const CString& ticker);

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartUDTDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockChartUDTDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();  // Berechnet die Durchschnittslinie

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartUDTDoc)
	afx_msg void OnChartProperty();
	afx_msg void OnStockProperty();
	afx_msg void OnFileImport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTDOC_H__BEE13F92_B045_11D1_B433_006097A8F69A__INCLUDED_)
