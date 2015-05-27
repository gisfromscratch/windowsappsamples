// OLEDBChartDoc.h : Schnittstelle der Klasse COLEDBChartDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBCHARTDOC_H__9222C92B_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_OLEDBCHARTDOC_H__9222C92B_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>  // die Template Werkzeugklassen


class CStockData 
{
public:
   double               min, max;
   CList<double,double> theData;
};


class COLEDBChartDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	COLEDBChartDoc();
	DECLARE_DYNCREATE(COLEDBChartDoc)

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

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(COLEDBChartDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~COLEDBChartDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(COLEDBChartDoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_OLEDBCHARTDOC_H__9222C92B_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
