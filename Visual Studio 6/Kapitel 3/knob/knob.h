#if !defined(AFX_KNOB_H__21D5697D_2604_11D2_B59C_006097A8F69A__INCLUDED_)
#define AFX_KNOB_H__21D5697D_2604_11D2_B59C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// knob.h: Haupt-Header-Datei für KNOB.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CKnobApp: Siehe knob.cpp für Implementierung

class CKnobApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_KNOB_H__21D5697D_2604_11D2_B59C_006097A8F69A__INCLUDED)
