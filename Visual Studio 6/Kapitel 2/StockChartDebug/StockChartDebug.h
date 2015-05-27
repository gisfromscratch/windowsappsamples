// StockChartDebug.h : Haupt-Header-Datei für die Anwendung STOCKCHART
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockChartDebugApp:
// Siehe StockChartDebug.cpp für die Implementierung dieser Klasse
//

class CStockChartDebugApp : public CWinApp
{
public:
	CStockChartDebugApp();

// Überladungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	afx_msg void OnAppAbout();
	afx_msg void OnCheckpoint();
	afx_msg void OnDumpAllObjectsSince();
	afx_msg void OnDifference();
	DECLARE_MESSAGE_MAP()
protected:
#ifdef _DEBUG
   CMemoryState memoryState;
#endif
};


/////////////////////////////////////////////////////////////////////////////

