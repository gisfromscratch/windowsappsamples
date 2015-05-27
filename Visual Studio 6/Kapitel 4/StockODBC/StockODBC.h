// StockODBC.h : Haupt-Header-Datei für die Anwendung STOCKODBC
//

#if !defined(AFX_STOCKODBC_H__39EDB6D8_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
#define AFX_STOCKODBC_H__39EDB6D8_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockODBCApp:
// Siehe StockODBC.cpp für die Implementierung dieser Klasse
//

class CStockODBCApp : public CWinApp
{
public:
	CStockODBCApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(CStockODBCApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKODBC_H__39EDB6D8_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
