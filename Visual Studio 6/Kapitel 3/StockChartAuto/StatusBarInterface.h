#ifndef AFX_STATUSBARINTERFACE_H__D3A9E442_0521_11D2_B525_006097A8F69A__INCLUDED_
#define AFX_STATUSBARINTERFACE_H__D3A9E442_0521_11D2_B525_006097A8F69A__INCLUDED_

// StatusBarInterface.h : Header-Datei
//



/////////////////////////////////////////////////////////////////////////////
// Befehlsziel CStatusBarInterface 

class CStatusBarInterface : public CCmdTarget
{
	DECLARE_DYNCREATE(CStatusBarInterface)

	CStatusBarInterface();           // Dynamische Erstellung verwendet geschützten Konstruktor

// Attribute
public:

// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CStatusBarInterface)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementierung
protected:
	virtual ~CStatusBarInterface();

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CStatusBarInterface)
		// HINWEIS - Der Klassen-Assistent fügt hier Member-Funktionen ein und entfernt diese.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generierte OLE-Dispatch-Zuordnungsfunktionen
	//{{AFX_DISPATCH(CStatusBarInterface)
	CString m_status;
	afx_msg void OnStatusChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_STATUSBARINTERFACE_H__D3A9E442_0521_11D2_B525_006097A8F69A__INCLUDED_
