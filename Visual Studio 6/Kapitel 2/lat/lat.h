// LAT.h : Haupt-Header-Datei f�r die DLL LAT
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CLATApp
// Siehe LAT.cpp f�r die Implementierung dieser Klasse
//

class CLATApp : public CWinApp
{
public:
	CLATApp();

	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

