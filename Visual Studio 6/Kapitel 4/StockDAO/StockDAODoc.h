// StockDAODoc.h : Schnittstelle der Klasse CStockDAODoc
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKDAODOC_H__8573C01B_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_STOCKDAODOC_H__8573C01B_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StockDAOSet.h"


class CStockDAODoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockDAODoc();
	DECLARE_DYNCREATE(CStockDAODoc)

// Attribute
public:
	CStockDAOSet m_stockDAOSet;

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockDAODoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementierung
public:
	virtual ~CStockDAODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	//{{AFX_MSG(CStockDAODoc)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKDAODOC_H__8573C01B_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
