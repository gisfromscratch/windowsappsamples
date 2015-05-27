// FileRobot.h : Haupt-Header-Datei für die Anwendung FILEROBOT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CFileRobotApp:
// Siehe FileRobot.cpp für die Implementierung dieser Klasse
//

class CFileRobotApp : public CWinApp
{
public:
	CFileRobotApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

