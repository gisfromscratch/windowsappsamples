// SquareClient.h : Haupt-Header-Datei f�r die Anwendung SQUARECLIENT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CSquareClientApp:
// Siehe SquareClient.cpp f�r die Implementierung dieser Klasse
//

class CSquareClientApp : public CWinApp
{
public:
	CSquareClientApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

