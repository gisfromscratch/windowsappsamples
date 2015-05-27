// WinControl.h : Haupt-Header-Datei für die Anwendung WINCONTROL
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CWinControlApp:
// Siehe WinControl.cpp für die Implementierung dieser Klasse
//

class CWinControlApp : public CWinApp
{
public:
	CWinControlApp();

// Überladungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

