// Square.cpp: Implementierungsdatei
//


#include "stdafx.h"
#include "MFCServer.h"
#include "Square.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSquare

IMPLEMENT_DYNCREATE(CSquare, CCmdTarget)

CSquare::CSquare()
{
	EnableAutomation();
	
	// Um die Ausführung der Anwendung fortzusetzen, solange ein OLE-Automatisierungs
	//	objekt aktiv ist, ruft der Konstruktor AfxOleLockApp auf.
	
	AfxOleLockApp();
}

CSquare::~CSquare()
{
	// Um die Anwendung zu beenden, nachdem alle Objekte durch OLE-Automatisierung
	// 	erstellt wurden, ruft der Destruktor AfxOleUnlockApp auf.
	
	AfxOleUnlockApp();
}


void CSquare::OnFinalRelease()
{
	// Nachdem die letzte Referenz auf ein Automatisierungsobjekt freigegeben wurde,
	// wird OnFinalRelease aufgerufen. Die Basisklasse löscht das Objekt
	// automatisch. Fügen Sie zusätzlichen Bereinigungscode für Ihr Objekt
	// hinzu, bevor Sie die Basisklasse aufrufen.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CSquare, CCmdTarget)
	//{{AFX_MSG_MAP(CSquare)
		// HINWEIS - Der Klassen-Assistent fügt hier Zuordnungsmakros ein und entfernt diese.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// Hier IID_ISquare ausgetauscht
static const GUID IID_ISquare = {0x547E8380,0xF175,0x11D1,0x90,0xA2,0xD0,0xDD,0x2F,0x7A,0xCA,0x49};


BEGIN_INTERFACE_MAP(CSquare, CCmdTarget)
	INTERFACE_PART(CSquare, IID_ISquare, SquareItf)
END_INTERFACE_MAP()

// {4831F131-F290-11D1-90A2-D0DD2F7ACA49}
IMPLEMENT_OLECREATE(CSquare, "MFCServer.Square", 0x4831f131, 0xf290, 0x11d1, 0x90, 0xa2, 0xd0, 0xdd, 0x2f, 0x7a, 0xca, 0x49)



/////// Implementierung der COM-Methoden ////////////
ULONG CSquare::XSquareItf::AddRef ()
{
   METHOD_PROLOGUE(CSquare,SquareItf);
   return pThis->ExternalAddRef ();
}

ULONG CSquare::XSquareItf::Release ()
{
   METHOD_PROLOGUE(CSquare,SquareItf);
   return pThis->ExternalRelease ();
}

HRESULT CSquare::XSquareItf::QueryInterface (REFIID riid, void **ppvObj)
{
   METHOD_PROLOGUE(CSquare,SquareItf)
   return pThis->ExternalQueryInterface (&riid, ppvObj);
}

HRESULT CSquare::XSquareItf::GetSquare (long value, long *pnResult)
{
   *pnResult = value * value;
   return S_OK;
}