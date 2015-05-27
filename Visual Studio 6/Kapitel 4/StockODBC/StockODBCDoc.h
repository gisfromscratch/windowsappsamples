// StockODBCDoc.h : Schnittstelle der Klasse CStockODBCDoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKODBCDOC_H__39EDB6DE_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
#define AFX_STOCKODBCDOC_H__39EDB6DE_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StockODBCSet.h"


class CStockODBCDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockODBCDoc();
	DECLARE_DYNCREATE(CStockODBCDoc)

// Attribute
public:
	CStockODBCSet m_stockODBCSet;

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockODBCDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockODBCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockODBCDoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKODBCDOC_H__39EDB6DE_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
