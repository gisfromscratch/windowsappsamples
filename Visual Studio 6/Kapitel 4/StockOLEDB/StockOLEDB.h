// StockOLEDB.h : Haupt-Header-Datei für die Anwendung STOCKOLEDB
//

#if !defined(AFX_STOCKOLEDB_H__9222C989_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_STOCKOLEDB_H__9222C989_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockOLEDBApp:
// Siehe StockOLEDB.cpp für die Implementierung dieser Klasse
//

class CStockOLEDBApp : public CWinApp
{
public:
	CStockOLEDBApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockOLEDBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(CStockOLEDBApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKOLEDB_H__9222C989_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
