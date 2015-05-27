// StockChartUDT.h : Haupt-Header-Datei für die Anwendung STOCKCHART
//

#if !defined(AFX_STOCKCHART_H__BEE13F8A_B045_11D1_B433_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHART_H__BEE13F8A_B045_11D1_B433_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockChartUDTApp:
// Siehe StockChartUDT.cpp für die Implementierung dieser Klasse
//

class CStockChartUDTApp : public CWinApp
{
public:
	CStockChartUDTApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartUDTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CStockChartUDTApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHART_H__BEE13F8A_B045_11D1_B433_006097A8F69A__INCLUDED_)
