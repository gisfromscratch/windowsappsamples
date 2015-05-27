// StockChartDebugDoc.h : Schnittstelle der Klasse CStockChartDebugDoc
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <afxtempl.h>  // die Template Werkzeugklassen
#include "ChartProperty.h"

class CStockData 
{
public:
   double               min, max;
   CList<double,double> theData;

   void Serialize (CArchive& ar);
};


class CStockChartDebugDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockChartDebugDoc();
	DECLARE_DYNCREATE(CStockChartDebugDoc)

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
   void SetStockData (const int id, const CString& name, const CString& ticker);

// Überladungen
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

// Implementierung
public:
	virtual ~CStockChartDebugDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();  // Berechnet die Durchschnittslinie

// Generierte Message-Map-Funktionen
protected:
	afx_msg void OnChartProperty();
	afx_msg void OnStockProperty();
	afx_msg void OnFileImport();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

