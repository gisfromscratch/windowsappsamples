// WinControl.h : Haupt-Header-Datei f�r die Anwendung WINCONTROL
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CWinControlApp:
// Siehe WinControl.cpp f�r die Implementierung dieser Klasse
//

class CWinControlApp : public CWinApp
{
public:
	CWinControlApp();

// �berladungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

