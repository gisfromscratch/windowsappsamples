// StockPropertyDll.cpp : Legt die Initialisierungsroutinen f�r die DLL fest.
//

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE StockPropertyDllDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Entfernen Sie dies, wenn Sie lpReserved verwenden
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("STOCKPROPERTYDLL.DLL Initializing!\n");
		
		// One-Time-Initialisierung der Erweiterungs-DLL
		if (!AfxInitExtensionModule(StockPropertyDllDLL, hInstance))
			return 0;

		// Diese DLL in Ressourcenkette einf�gen
		// HINWEIS: Wird diese Erweiterungs-DLL implizit durch eine regul�re
		//  MFC-DLL (wie z.B. ein ActiveX-Steuerelement) anstelle einer
		//  MFC-Anwendung eingebunden, dann m�chten Sie m�glicherweise diese
		//  Zeile aus DllMain entfernen und eine eigene Funktion einf�gen,
		//  die von dieser Erweiterungs-DLL exportiert wird. Die regul�re DLL,
		//  die diese Erweiterungs-DLL verwendet, sollte dann explizit die 
		//  Initialisierungsfunktion der Erweiterungs-DLL aufrufen. Anderenfalls 
		//  wird das CDynLinkLibrary-Objekt nicht mit der Recourcenkette der 
		//  regul�ren DLL verbunden, was zu ernsthaften Problemen
		//  f�hren kann.

		new CDynLinkLibrary(StockPropertyDllDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STOCKPROPERTYDLL.DLL Terminating!\n");
		// Bibliothek vor dem Aufruf der Destruktoren schlie�en
		AfxTermExtensionModule(StockPropertyDllDLL);
	}
	return 1;   // OK
}
