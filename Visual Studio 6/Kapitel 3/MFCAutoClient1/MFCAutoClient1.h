// MFCAutoClient1.h : Haupt-Header-Datei f�r die Anwendung MFCAUTOCLIENT1
//

#if !defined(AFX_MFCAUTOCLIENT1_H__48969668_0A05_11D2_B530_006097A8F69A__INCLUDED_)
#define AFX_MFCAUTOCLIENT1_H__48969668_0A05_11D2_B530_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1App:
// Siehe MFCAutoClient1.cpp f�r die Implementierung dieser Klasse
//

class CMFCAutoClient1App : public CWinApp
{
public:
	CMFCAutoClient1App();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCAutoClient1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CMFCAutoClient1App)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_MFCAUTOCLIENT1_H__48969668_0A05_11D2_B530_006097A8F69A__INCLUDED_)
