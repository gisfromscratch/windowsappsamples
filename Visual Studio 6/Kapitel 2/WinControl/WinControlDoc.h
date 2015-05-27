// WinControlDoc.h : Schnittstelle der Klasse CWinControlDoc
//
/////////////////////////////////////////////////////////////////////////////

#pragma once


class CWinControlDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CWinControlDoc();
	DECLARE_DYNCREATE(CWinControlDoc)

// Attribute
public:

// Operationen
public:

// Überladungen
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementierung
public:
	virtual ~CWinControlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

