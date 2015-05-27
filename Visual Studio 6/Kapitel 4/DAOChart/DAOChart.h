// DAOChart.h : Haupt-Header-Datei f�r die Anwendung DAOCHART
//

#if !defined(AFX_DAOCHART_H__8573C02C_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_DAOCHART_H__8573C02C_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CDAOChartApp:
// Siehe DAOChart.cpp f�r die Implementierung dieser Klasse
//

class CDAOChartApp : public CWinApp
{
public:
	CDAOChartApp();

   CString strDBName;  // Pfad und Name der Datenbank

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CDAOChartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(CDAOChartApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_DAOCHART_H__8573C02C_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
