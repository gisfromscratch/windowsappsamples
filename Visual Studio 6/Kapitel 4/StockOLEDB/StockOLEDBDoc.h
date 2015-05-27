// StockOLEDBDoc.h : Schnittstelle der Klasse CStockOLEDBDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKOLEDBDOC_H__9222C98F_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_STOCKOLEDBDOC_H__9222C98F_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StockOLEDBSet.h"


class CStockOLEDBDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockOLEDBDoc();
	DECLARE_DYNCREATE(CStockOLEDBDoc)

// Attribute
public:
	CStockOLEDBSet m_stockOLEDBSet;

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockOLEDBDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockOLEDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockOLEDBDoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKOLEDBDOC_H__9222C98F_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
