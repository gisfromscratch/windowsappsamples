// StockChartOle.h : Haupt-Header-Datei für die Anwendung STOCKCHARTOLE
//

#if !defined(AFX_STOCKCHARTOLE_H__50CB22AE_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTOLE_H__50CB22AE_0C37_11D2_B53C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleApp:
// Siehe StockChartOle.cpp für die Implementierung dieser Klasse
//

class CStockChartOleApp : public CWinApp
{
public:
	CStockChartOleApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartOleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	COleTemplateServer m_server;
		// Server-Objekt für Dokumenterstellung

	//{{AFX_MSG(CStockChartOleApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTOLE_H__50CB22AE_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
