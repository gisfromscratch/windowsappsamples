// DlgProxy.h : Header-Datei
//

#if !defined(AFX_DLGPROXY_H__4896966C_0A05_11D2_B530_006097A8F69A__INCLUDED_)
#define AFX_DLGPROXY_H__4896966C_0A05_11D2_B530_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMFCAutoClient1Dlg;

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1DlgAutoProxy Befehlsziel

class CMFCAutoClient1DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFCAutoClient1DlgAutoProxy)

	CMFCAutoClient1DlgAutoProxy();           // Dynamische Erstellung verwendet geschützten Konstruktor

// Attribute
public:
	CMFCAutoClient1Dlg* m_pDialog;

// Operationen
public:

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCAutoClient1DlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CMFCAutoClient1DlgAutoProxy();

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CMFCAutoClient1DlgAutoProxy)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFCAutoClient1DlgAutoProxy)

	// Generierte OLE-Dispatch-Map-Funktionen
	//{{AFX_DISPATCH(CMFCAutoClient1DlgAutoProxy)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_DLGPROXY_H__4896966C_0A05_11D2_B530_006097A8F69A__INCLUDED_)
