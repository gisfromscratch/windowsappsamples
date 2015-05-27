#ifndef AFX_SQUARE_H__77A848B0_FC79_11D1_B50B_006097A8F69A__INCLUDED_
#define AFX_SQUARE_H__77A848B0_FC79_11D1_B50B_006097A8F69A__INCLUDED_

// Square.h : Header-Datei
//


interface ISquare : public IUnknown
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetSquare (long value, long *pnResult) = 0;
};


/////////////////////////////////////////////////////////////////////////////
// Befehlsziel CSquare 

class CSquare : public CCmdTarget
{
	DECLARE_DYNCREATE(CSquare)

	CSquare();           // Dynamische Erstellung verwendet geschützten Konstruktor

// Attribute
public:

// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CSquare)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CSquare();

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CSquare)
		// HINWEIS - Der Klassen-Assistent fügt hier Member-Funktionen ein und entfernt diese.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSquare)

	DECLARE_INTERFACE_MAP()

	BEGIN_INTERFACE_PART(SquareItf,ISquare)
		STDMETHOD(GetSquare) (long value, long* pnResult);
	END_INTERFACE_PART(SquareItf)

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_SQUARE_H__77A848B0_FC79_11D1_B50B_006097A8F69A__INCLUDED_
