// SquareServer.cpp : Implementierung der DLL-Exporte.


// Hinweis: Proxy/Stub-Information
//		Zur Aufnahme des Proxy/Stub-Codes in die Objekt-DLL f�gen Sie die Datei 
//		dlldatax.c dem Projekt hinzu.  Stellen Sie sicher, dass vorcompilierte Header
//		f�r diese Datei deaktiviert sind und f�gen Sie _MERGE_PROXYSTUB zu 
//		den Projektdefinitionen hinzu.  
//
//		Wenn Sie WinNT4.0 oder Win95 nicht mit DCOM ausf�hren,
//		m�ssen Sie die folgende define-Anweisung aus dlldatax.c entfernen.
//		#define _WIN32_WINNT 0x0400
//
//		Wenn Sie dar�ber hinaus MIDL ohne den Schalter /Oicf ausf�hren, 
//		m�ssen Sie auch die folgende define-Anweisung aus dlldatax.c entfernen.
//		#define USE_STUBLESS_PROXY
//
//		�ndern Sie die benutzerspezifische Build-Regel f�r SquareServer.idl durch Hinzuf�gen
//		folgender Dateien.
//			SquareServer_p.c
//			dlldata.c
//		Um eine eigene Proxy/Stub-DLL zu erstellen, 
//		f�hren Sie nmake -f SquareServerps.mk im Projektverzeichnis aus.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "SquareServer.h"
#include "dlldatax.h"

#include "SquareServer_i.c"
#include "Square.h"

#ifdef _MERGE_PROXYSTUB
extern "C" HINSTANCE hProxyDll;
#endif

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_Square, Square)
END_OBJECT_MAP()

class CSquareServerApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
};

CSquareServerApp theApp;

BOOL CSquareServerApp::InitInstance()
{
#ifdef _MERGE_PROXYSTUB
	hProxyDll = m_hInstance;
#endif
	_Module.Init(ObjectMap, m_hInstance);
	return CWinApp::InitInstance();
}

int CSquareServerApp::ExitInstance()
{
	_Module.Term();
	return CWinApp::ExitInstance();
}

/////////////////////////////////////////////////////////////////////////////
// Verwendet, um zu entscheiden, ob die DLL von OLE aus dem Speicher entfernt werden kann

STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
	if (PrxDllCanUnloadNow() != S_OK)
		return S_FALSE;
#endif
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return (AfxDllCanUnloadNow()==S_OK && _Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Liefert eine Klassenfabrik zur�ck, um ein Objekt des angeforderten Typs anzulegen

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
	if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
		return S_OK;
#endif
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - F�gt der Systemregistrierung Eintr�ge hinzu

STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
	HRESULT hRes = PrxDllRegisterServer();
	if (FAILED(hRes))
		return hRes;
#endif
	// Registriert Objekt, Typelib und alle Schnittstellen in Typelib
	return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Entfernt Eintr�ge aus der Systemregistrierung

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
	PrxDllUnregisterServer();
#endif
	_Module.UnregisterServer();
	return S_OK;
}


