// DlgProxy.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "MFCAutoClient1.h"
#include "DlgProxy.h"
#include "MFCAutoClient1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1DlgAutoProxy

IMPLEMENT_DYNCREATE(CMFCAutoClient1DlgAutoProxy, CCmdTarget)

CMFCAutoClient1DlgAutoProxy::CMFCAutoClient1DlgAutoProxy()
{
	EnableAutomation();
	
	// Um die Ausf�hrung der Anwendung fortzusetzen, solange ein OLE-Automatisierungsobjekt
	//	aktiv ist, ruft der Konstruktor AfxOleLockApp auf.
	AfxOleLockApp();

	// Greifen Sie �ber den Hauptfensterzeiger der Anwendung auf das
	//  Dialogfeld zu. Setzen Sie den internen Zeiger des Proxy
	//  auf das Dialogfeld und den Gegenzeiger (Back Pointer) des Dialogfelds 
	//  auf diesen Proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CMFCAutoClient1Dlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMFCAutoClient1Dlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMFCAutoClient1DlgAutoProxy::~CMFCAutoClient1DlgAutoProxy()
{
	// Um die Anwendung zu beenden, sobald alle mit OLE-Automatisierung erstellten
	// Objekte freigegeben sind, ruft der Destruktor AfxOleUnlockApp auf.
	//  Dies zerst�rt unter anderem das Hauptdialogfeld.
	AfxOleUnlockApp();
}

void CMFCAutoClient1DlgAutoProxy::OnFinalRelease()
{
	// Wird der letzte Verweis auf ein Automatisierungsobjekt freigegeben,
	// wird OnFinalRelease aufgerufen. Die Basisklasse l�scht das Objekt
	// automatisch. F�gen Sie zus�tzlichen Bereinigungscode f�r Ihr Objekt
	// hinzu, bevor Sie die Basisklasse aufrufen.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFCAutoClient1DlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMFCAutoClient1DlgAutoProxy)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingef�gt und entfernt.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCAutoClient1DlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFCAutoClient1DlgAutoProxy)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingef�gt und entfernt.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Hinweis: Wir stellen Unterst�tzung f�r IID_IMFCAutoClient1 zur Verf�gung, um typsicheres Binden 
//  von VBA zu unterst�tzen. Diese IID muss mit der GUID �bereinstimmen, die bei der 
//  Disp-Schnittstelle in der .ODL-Datei angegeben ist.

// {48969665-0A05-11D2-B530-006097A8F69A}
static const IID IID_IMFCAutoClient1 =
{ 0x48969665, 0xa05, 0x11d2, { 0xb5, 0x30, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };

BEGIN_INTERFACE_MAP(CMFCAutoClient1DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFCAutoClient1DlgAutoProxy, IID_IMFCAutoClient1, Dispatch)
END_INTERFACE_MAP()

// Das Makro IMPLEMENT_OLECREATE2 ist in der Datei StdAfx.h dieses Projekts definiert
// {48969663-0A05-11D2-B530-006097A8F69A}
IMPLEMENT_OLECREATE2(CMFCAutoClient1DlgAutoProxy, "MFCAutoClient1.Application", 0x48969663, 0xa05, 0x11d2, 0xb5, 0x30, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a)

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1DlgAutoProxy Nachrichten-Handler
