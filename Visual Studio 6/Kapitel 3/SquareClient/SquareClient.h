// SquareClient.h : Haupt-Header-Datei für die Anwendung SQUARECLIENT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CSquareClientApp:
// Siehe SquareClient.cpp für die Implementierung dieser Klasse
//

class CSquareClientApp : public CWinApp
{
public:
	CSquareClientApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

