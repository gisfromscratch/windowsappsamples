// MFCServer.h : Haupt-Header-Datei für die DLL MFCSERVER
//

#if !defined(AFX_MFCSERVER_H__77A848A7_FC79_11D1_B50B_006097A8F69A__INCLUDED_)
#define AFX_MFCSERVER_H__77A848A7_FC79_11D1_B50B_006097A8F69A__INCLUDED_


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CMFCServerApp
// Siehe MFCServer.cpp für die Implementierung dieser Klasse
//

class CMFCServerApp : public CWinApp
{
public:
	CMFCServerApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMFCServerApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_MFCSERVER_H__77A848A7_FC79_11D1_B50B_006097A8F69A__INCLUDED_)
