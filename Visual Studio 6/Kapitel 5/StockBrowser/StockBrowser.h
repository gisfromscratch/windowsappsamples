// StockBrowser.h : Haupt-Header-Datei f�r die Anwendung STOCKBROWSER
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp:
// Siehe StockBrowser.cpp f�r die Implementierung dieser Klasse
//

class CStockBrowserApp : public CWinApp
{
public:
	CStockBrowserApp();

// �berladungen
	public:
	virtual BOOL InitInstance();

// Implementierung
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

