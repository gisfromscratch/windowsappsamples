// StockChartAuto.h : Haupt-Header-Datei für die Anwendung STOCKCHARTAUTO
//

#if !defined(AFX_STOCKCHARTAUTO_H__CFDB3169_0122_11D2_B51C_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTAUTO_H__CFDB3169_0122_11D2_B51C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoApp:
// Siehe StockChartAuto.cpp für die Implementierung dieser Klasse
//

class CStockChartAutoApp : public CWinApp
{
public:
	CStockChartAutoApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartAutoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	COleTemplateServer m_server;
		// Server-Objekt für Dokumenterstellung

	//{{AFX_MSG(CStockChartAutoApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTAUTO_H__CFDB3169_0122_11D2_B51C_006097A8F69A__INCLUDED_)
