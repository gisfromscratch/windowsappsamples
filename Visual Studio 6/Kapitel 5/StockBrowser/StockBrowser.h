// StockBrowser.h : Haupt-Header-Datei für die Anwendung STOCKBROWSER
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp:
// Siehe StockBrowser.cpp für die Implementierung dieser Klasse
//

class CStockBrowserApp : public CWinApp
{
public:
	CStockBrowserApp();

// Überladungen
	public:
	virtual BOOL InitInstance();

// Implementierung
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

