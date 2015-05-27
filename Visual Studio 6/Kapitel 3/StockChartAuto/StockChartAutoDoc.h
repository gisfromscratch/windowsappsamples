// StockChartAutoDoc.h : Schnittstelle der Klasse CStockChartAutoDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKCHARTAUTODOC_H__CFDB3172_0122_11D2_B51C_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTAUTODOC_H__CFDB3172_0122_11D2_B51C_006097A8F69A__INCLUDED_

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


class CStockChartAutoDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartAutoDoc();
	DECLARE_DYNCREATE(CStockChartAutoDoc)

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

protected:
   CChartProperty *m_pChartProperty;  // nichtmodaler Dialog   

// Operationen
public:
   void OnPropertyChange (BOOL bUpdateData, BOOL bCloseWindow);

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartAutoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockChartAutoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();  // Berechnet die Durchschnittslinie

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockChartAutoDoc)
	afx_msg void OnStockProperty();
	afx_msg void OnChartProperty();
	afx_msg void OnFileImport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generierte OLE-Dispatch-Map-Funktionen
	//{{AFX_DISPATCH(CStockChartAutoDoc)
	afx_msg long GetId();
	afx_msg void SetId(long nNewValue);
	afx_msg BSTR GetName();
	afx_msg void SetName(LPCTSTR lpszNewValue);
	afx_msg LPDISPATCH GetStatusbar();
	afx_msg BSTR GetTicker();
	afx_msg void SetTicker(LPCTSTR lpszNewValue);
	afx_msg BOOL GetAverage();
	afx_msg void SetAverage(BOOL bNewValue);
	afx_msg long GetAveragecnt();
	afx_msg void SetAveragecnt(long nNewValue);
	afx_msg BOOL GetGrid();
	afx_msg void SetGrid(BOOL bNewValue);
	afx_msg void ShowWindow();
	afx_msg void SetColor(short red, short green, short blue);
	afx_msg BOOL SaveFile(LPCTSTR pathName);
	afx_msg BOOL ImportFile(LPCTSTR pathName);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTAUTODOC_H__CFDB3172_0122_11D2_B51C_006097A8F69A__INCLUDED_)
