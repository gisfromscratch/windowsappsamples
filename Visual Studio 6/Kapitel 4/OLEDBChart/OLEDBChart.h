// OLEDBChart.h : Haupt-Header-Datei f�r die Anwendung OLEDBCHART
//

#if !defined(AFX_OLEDBCHART_H__9222C923_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_OLEDBCHART_H__9222C923_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole
#include "OLEDBChart_i.h"

/////////////////////////////////////////////////////////////////////////////
// COLEDBChartApp:
// Siehe OLEDBChart.cpp f�r die Implementierung dieser Klasse
//

class COLEDBChartApp : public CWinApp
{
public:
	COLEDBChartApp();

   CString strDBName;  // Pfad und Name der Datenbank

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(COLEDBChartApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	//{{AFX_MSG(COLEDBChartApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_OLEDBCHART_H__9222C923_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
