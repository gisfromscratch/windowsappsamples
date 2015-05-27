// CppServerNested.cpp
#include <olectl.h>
#include "CppServerNested.h"


static const GUID IID_ISquare = {0x547E8380,0xF175,0x11D1,0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49};
// {E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}
static const GUID CLSID_WIN32SquareServerNestedClass = 
{ 0xe3c91780, 0xf24f, 0x11d1, { 0x90, 0xa2, 0xd0, 0xdd, 0x2f, 0x7a, 0xca, 0x49 } };


// Globale Variablen
static HINSTANCE hInstance;
static long nServerLockCount = 0;
static CPPServerNestedFactory serverFactory;

// Prototypen zum Festhalten der DLL im Speicher
static void DllLockServer (void);
static void DllUnlockServer (void);



CPPServerNested::CPPServerNested ()
{
	m_dwRefCount = 0;
	m_SquareItf.m_pParent = this;
}

ULONG CPPServerNested::AddRef() 
{
   if (!m_dwRefCount)
      DllLockServer ();
	return ++m_dwRefCount;
}

ULONG CPPServerNested::Release ()
{
	DWORD dw;

	dw = m_dwRefCount--;
	if (0 == m_dwRefCount) {
		delete this;
      DllUnlockServer ();
   }

	return dw;
}

HRESULT CPPServerNested::QueryInterface (REFIID riid, void **ppvObj)
{
	HRESULT hr = E_NOINTERFACE;

	if (riid == IID_IUnknown) 
		*ppvObj = LPUNKNOWN(this);
	else if (riid == IID_ISquare) 
		*ppvObj = (ISquare*)&m_SquareItf;
   else 
      *ppvObj = NULL;

   if (*ppvObj) 
   {
      LPUNKNOWN(*ppvObj)->AddRef ();
		hr = NOERROR;
	}

	return hr;
}

// Methoden der eingebetteten Interface-Klasse:
// Zuerst wird IUnknown delegiert.
ULONG CPPServerNested::SquareItf::AddRef ()
{
	return m_pParent->AddRef ();
}

ULONG CPPServerNested::SquareItf::Release ()
{
	return m_pParent->Release ();
}

HRESULT CPPServerNested::SquareItf::QueryInterface (REFIID riid, void **ppvObj)
{
	return m_pParent->QueryInterface (riid, ppvObj);
}

// ISquare-Methode
HRESULT CPPServerNested::SquareItf::GetSquare (long value, long *pnResult)
{
	*pnResult = value * value;
	return S_OK;
}


//////////////// Factory class //////////////////////////

CPPServerNestedFactory::CPPServerNestedFactory ()
{
	m_dwRefCount = 0;
}


DWORD CPPServerNestedFactory::AddRef ()
{
	DllLockServer ();
   return ++m_dwRefCount;
}


DWORD CPPServerNestedFactory::Release ()
{
	DllUnlockServer ();
   return --m_dwRefCount;
}

HRESULT CPPServerNestedFactory::QueryInterface (REFIID riid, void **ppvObj)
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

HRESULT CPPServerNestedFactory::CreateInstance (IUnknown *pUnkOuter,
		                                          REFIID riid,
                                                void **ppvObj)
{
	HRESULT hr;
	CPPServerNested *pServer;

	hr = E_OUTOFMEMORY;

	pServer = new CPPServerNested;
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


HRESULT CPPServerNestedFactory::LockServer (BOOL fLock)
{
	if (fLock)
		DllLockServer ();
	else
		DllUnlockServer();

	return S_OK;
}


/////////////////////////////////////////////////////
// Funktionen, die aus der DLL exportiert werden:

STDAPI DllGetClassObject (REFCLSID rclsid,
                          REFIID riid,
                          void **ppvObj)
{
	if (rclsid == CLSID_WIN32SquareServerNestedClass) 
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
                "CLSID\\{E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}\\InProcServer32",
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
                "CLSID\\{E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}",
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
      return SELFREG_E_CLASS;
      
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

   // Schlüssel löschen: {E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}
   nRetVal = RegDeleteKey (hKey, "{E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}");

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
