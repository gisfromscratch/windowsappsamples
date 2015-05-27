// ODBCChart.h : Haupt-Header-Datei für die Anwendung ODBCCHART
//

#if !defined(AFX_ODBCCHART_H__55AC957A_53E1_11D2_B3CE_006097A8F69A__INCLUDED_)
#define AFX_ODBCCHART_H__55AC957A_53E1_11D2_B3CE_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CODBCChartApp:
// Siehe ODBCChart.cpp für die Implementierung dieser Klasse
//

class CODBCChartApp : public CWinApp
{
public:
	CODBCChartApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CODBCChartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(CODBCChartApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_ODBCCHART_H__55AC957A_53E1_11D2_B3CE_006097A8F69A__INCLUDED_)
