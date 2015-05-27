// cppserver.cpp
#include <olectl.h>
#include "cppserver.h"

// GUIDs
static const GUID IID_ISquare = {0x547E8380,0xF175,0x11D1,0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49};
static const GUID CLSID_CPPSquareServerClass = {0xB8EF6063,0xF1C2,0x11d1,0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49};

// Globale Variablen
static HINSTANCE hInstance;
static long nServerLockCount = 0;
static CPPServerFactory serverFactory;

// Prototypen zum Festhalten der DLL im Speicher
static void DllLockServer (void);
static void DllUnlockServer (void);



CPPServer::CPPServer ()
{
	m_dwRefCount = 0;
}

ULONG CPPServer::AddRef() 
{
	if (!m_dwRefCount)
      DllLockServer ();
   return ++m_dwRefCount;
}

ULONG CPPServer::Release ()
{
	DWORD dw;

	dw = m_dwRefCount--;
	if (0 == m_dwRefCount)
   {
		delete this;
      DllUnlockServer ();
   }

	return dw;
}

HRESULT CPPServer::QueryInterface (REFIID riid, void **ppvObj)
{
	HRESULT hr = E_NOINTERFACE;

	if (riid == IID_IUnknown)
      *ppvObj =  LPUNKNOWN(this);
   else if (riid == IID_ISquare)
		*ppvObj = (ISquare *)this;
   else
      *ppvObj = NULL;

   if (*ppvObj) 
   {
      LPUNKNOWN(*ppvObj)->AddRef ();
		hr = NOERROR;
	}

	return hr;
}

HRESULT CPPServer::GetSquare (long value, long *pnResult)
{
	*pnResult = value * value;
	return S_OK;
}


//////////////// Factory class //////////////////////////

CPPServerFactory::CPPServerFactory ()
{
	m_dwRefCount = 0;
}


DWORD CPPServerFactory::AddRef ()
{
	DllLockServer ();
   return ++m_dwRefCount;
}


DWORD CPPServerFactory::Release ()
{
	DllUnlockServer ();
   return --m_dwRefCount;
}

HRESULT CPPServerFactory::QueryInterface (REFIID riid, void **ppvObj)
{
	HRESULT hr = E_NOINTERFACE;

	if (riid == IID_IClassFactory)
		*ppvObj = LPCLASSFACTORY(this);
	else if (riid == IID_IUnknown)
		*ppvObj = LPUNKNOWN(this);
   else
      *ppvObj = NULL;

	if (*ppvObj) {
		LPUNKNOWN(*ppvObj)->AddRef();
		return NOERROR;
	}

	return hr;
}

HRESULT CPPServerFactory::CreateInstance (IUnknown *pUnkOuter,
		                                    REFIID riid,
								                  void **ppvObj)
{
	HRESULT hr;
	CPPServer *pServer;

	hr = E_OUTOFMEMORY;

	pServer = new CPPServer;
	if (pServer)
	{
		hr = pServer->QueryInterface (riid, ppvObj);
		if (FAILED (hr))
			delete pServer;
	}
   else 
      *ppvObj = NULL;

	return hr;
}


HRESULT CPPServerFactory::LockServer (BOOL fLock)
{
	if (fLock)
		DllLockServer ();
	else
		DllUnlockServer ();

	return S_OK;
}


//////////////////////////////////////////////////////////////
// Exportierte DLL-Funktionen
//

STDAPI DllGetClassObject (REFCLSID rclsid,
						        REFIID riid,
                          void **ppvObj)
{
	if (rclsid == CLSID_CPPSquareServerClass) 
		return serverFactory.QueryInterface (riid, ppvObj);

	*ppvObj = NULL;
	return CLASS_E_CLASSNOTAVAILABLE;
}

///////////////////////////////////////////////////////////////
// Registrierung durch RegSvr32 erlauben:
//
STDAPI DllRegisterServer(void)
{
   HKEY hKey;
   DWORD dwDisposition;
   char lpszFileName[_MAX_PATH];
   LONG nRetVal;

   // Pfadnamen der DLL besorgen:
   GetModuleFileName (hInstance, lpszFileName, _MAX_PATH);

   // Schlüssel in der Registrierungsdatenbank anlegen:
   nRetVal = RegCreateKeyEx (
                HKEY_CLASSES_ROOT,
                "CLSID\\{B8EF6063-F1C2-11d1-90A2-D0DD2F7ACA49}\\InProcServer32",
                0,
                NULL,
                REG_OPTION_NON_VOLATILE,
                KEY_ALL_ACCESS,
                NULL,
                &hKey,
                &dwDisposition);

   // Fehler?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS;

   // Pfad eintragen:
   nRetVal = RegSetValueEx (
                hKey,
                NULL, // "Standard"-Wert setzen
                0,
                REG_SZ,
                (const unsigned char*)lpszFileName,
                strlen(lpszFileName));

   // Zugriff auf Registrierungsdatenbank beenden:
   RegCloseKey (hKey);

   // Fehler beim Setzen des Pfads?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS;
   else
      return S_OK;
}


///////////////////////////////////////////////////////////////
// Deregistrierung durch RegSvr32 erlauben
//
STDAPI DllUnregisterServer(void)
{
   LONG nRetVal;
   HKEY hKey;

   // Schlüssel öffnen
   nRetVal = RegOpenKeyEx (
                HKEY_CLASSES_ROOT,
                "CLSID\\{B8EF6063-F1C2-11d1-90A2-D0DD2F7ACA49}",
                0,
                KEY_ALL_ACCESS,
                &hKey);

   // Fehler?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS;
                   
   // Schlüssel löschen: InProcServer32
   nRetVal = RegDeleteKey (hKey, "InProcServer32");

   // Schlüssel schließen
   RegCloseKey (hKey);

   // Fehler beim Löschen?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS ;
      
   // Schlüssel öffnen
   nRetVal = RegOpenKeyEx (
                HKEY_CLASSES_ROOT,
                "CLSID",
                0,
                KEY_ALL_ACCESS,
                &hKey);

   // Fehler?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS;

   // Schlüssel löschen: {B8EF6063-F1C2-11d1-90A2-D0DD2F7ACA49}
   nRetVal = RegDeleteKey (hKey, "{B8EF6063-F1C2-11d1-90A2-D0DD2F7ACA49}");

   // Schlüssel schließen
   RegCloseKey (hKey);

   // Fehler?
   if (ERROR_SUCCESS != nRetVal)
      return SELFREG_E_CLASS;
   else
      return S_OK;
}


STDAPI DllCanUnloadNow(void)
{  
   if (nServerLockCount > 0) 
      return S_FALSE;
   else
      return S_OK;
}


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
   // Instanzhandle merken, wird in DllRegisterServer gebraucht!
   hInstance = hinstDLL;

   return TRUE;  
}

///////////////////////////////////////
// Funktionen zum Setzen des DLL-Locks

void DllLockServer (void)
{
   nServerLockCount++;
}

void DllUnlockServer (void)
{
   nServerLockCount--;
}
