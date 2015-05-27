// StockChartX.h : Haupt-Header-Datei f�r die Anwendung STOCKCHARTX
//

#if !defined(AFX_STOCKCHARTX_H__FC8ACC16_231B_11D2_B593_006097A8F69A__INCLUDED_)
#define AFX_STOCKCHARTX_H__FC8ACC16_231B_11D2_B593_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CStockChartXApp:
// Siehe StockChartX.cpp f�r die Implementierung dieser Klasse
//

class CStockChartXApp : public CWinApp
{
public:
	CStockChartXApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockChartXApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung
	COleTemplateServer m_server;
		// Server-Objekt f�r Dokumenterstellung

	//{{AFX_MSG(CStockChartXApp)
	afx_msg void OnAppAbout();
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_STOCKCHARTX_H__FC8ACC16_231B_11D2_B593_006097A8F69A__INCLUDED_)
