// FileRobot.h : Haupt-Header-Datei f�r die Anwendung FILEROBOT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CFileRobotApp:
// Siehe FileRobot.cpp f�r die Implementierung dieser Klasse
//

class CFileRobotApp : public CWinApp
{
public:
	CFileRobotApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

