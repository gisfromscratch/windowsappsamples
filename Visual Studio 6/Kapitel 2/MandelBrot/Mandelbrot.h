// Mandelbrot.h : Haupt-Header-Datei für die Anwendung MANDELBROT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole


// selbstdefinerte Windows-Nachricht
#define WM_LINEDONE WM_APP+1


// Konstante, die die Ansichtgröße angibt
const int kViewSize = 500;

/////////////////////////////////////////////////////////////////////////////
// CMandelbrotApp:
// Siehe Mandelbrot.cpp für die Implementierung dieser Klasse
//

class CMandelbrotApp : public CWinApp
{
public:
	CMandelbrotApp();

// Überladungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	afx_msg void OnAppAbout();

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

