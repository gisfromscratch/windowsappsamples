#if !defined(AFX_DLLDATAX_H__547E837D_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_)
#define AFX_DLLDATAX_H__547E837D_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifdef _MERGE_PROXYSTUB

extern "C" 
{
BOOL WINAPI PrxDllMain(HINSTANCE hInstance, DWORD dwReason, 
	LPVOID lpReserved);
STDAPI PrxDllCanUnloadNow(void);
STDAPI PrxDllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
STDAPI PrxDllRegisterServer(void);
STDAPI PrxDllUnregisterServer(void);
}

#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio f�gt zus�tzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_DLLDATAX_H__547E837D_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_)
