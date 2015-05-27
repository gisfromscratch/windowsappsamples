// MFCAutoClient2.h : Haupt-Header-Datei für die Anwendung MFCAUTOCLIENT2
//

#if !defined(AFX_MFCAUTOCLIENT2_H__50CB2283_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
#define AFX_MFCAUTOCLIENT2_H__50CB2283_0C37_11D2_B53C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient2App:
// Siehe MFCAutoClient2.cpp für die Implementierung dieser Klasse
//

class CMFCAutoClient2App : public CWinApp
{
public:
	CMFCAutoClient2App();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCAutoClient2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CMFCAutoClient2App)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_MFCAUTOCLIENT2_H__50CB2283_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
