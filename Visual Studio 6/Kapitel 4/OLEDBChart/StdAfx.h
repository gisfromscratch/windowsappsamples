// stdafx.h : Include-Datei f�r Standard-System-Include-Dateien,
//  oder projektspezifische Include-Dateien, die h�ufig benutzt, aber
//      in unregelm��igen Abst�nden ge�ndert werden.
//

#if !defined(AFX_STDAFX_H__9222C925_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
#define AFX_STDAFX_H__9222C925_6036_11D2_B3F3_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Selten verwendete Teile der Windows-Header nicht einbinden

#include <afxwin.h>         // MFC-Kern- und -Standardkomponenten
#include <afxext.h>         // MFC-Erweiterungen
#include <afxdtctl.h>		// MFC-Unterst�tzung f�r allgemeine Steuerelemente von Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC-Unterst�tzung f�r g�ngige Windows-Steuerelemente
#endif // _AFX_NO_AFXCMN_SUPPORT


	#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//Sie k�nnen eine Klasse von CComModule ableiten und dies verwenden, wenn Sie
//etwas �berladen wollen. �ndern Sie aber nicht den Namen von _Module
class COLEDBChartModule : public CComModule
{
public:
	LONG Unlock();
	LONG Lock();
	LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2);
	DWORD dwThreadID;
};
extern COLEDBChartModule _Module;
#include <atlcom.h>
#include <atldbcli.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_STDAFX_H__9222C925_6036_11D2_B3F3_006097A8F69A__INCLUDED_)
