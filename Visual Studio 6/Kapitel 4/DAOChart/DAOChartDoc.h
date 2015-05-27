// DAOChartDoc.h : Schnittstelle der Klasse CDAOChartDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAOCHARTDOC_H__8573C034_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_DAOCHARTDOC_H__8573C034_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

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

class CDAOChartDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CDAOChartDoc();
	DECLARE_DYNCREATE(CDAOChartDoc)

// Attribute
public:

// Operationen
public:
   BOOL     m_bGrid;        // Flag f�r Gitternetz
   BOOL     m_bAverage;     // Flag f�r Durchschnittslinie
   int      m_nAverageCnt;  // Anzahl der Werte f�r Durchschnitt
   COLORREF m_nColor;       // Farbe der Kurve
   CString  m_name;         // Name der Aktie
   CString  m_ticker;       // Ticker-Symbol  
   int      m_nID;          // WKN

   CStockData           m_stockData;   // h�lt die Kursdaten
   CList<double,double> m_averageData; // h�lt Daten der Durchschnittslinie

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CDAOChartDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CDAOChartDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   void CalcAverages ();

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CDAOChartDoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_DAOCHARTDOC_H__8573C034_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
