// StockBrowserDoc.h : Schnittstelle der Klasse CStockBrowserDoc
//
/////////////////////////////////////////////////////////////////////////////

#pragma once


#include <afxtempl.h>  // die Template-Werkzeugklassen


// Klasse, um die Liste der Aktien zu halten
class CStockList 
{
public:
   CList<CString,CString&> m_theList;

   void EmptyList ();
};


class CStockBrowserDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CStockBrowserDoc();
	DECLARE_DYNCREATE(CStockBrowserDoc)

// Attribute
public:

// Operationen
public:
   CString GetURL () const;

// Überladungen
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementierung
public:
	virtual ~CStockBrowserDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
   CStockList m_stockList;

// Generierte Message-Map-Funktionen
protected:
	afx_msg void OnEditList();
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

