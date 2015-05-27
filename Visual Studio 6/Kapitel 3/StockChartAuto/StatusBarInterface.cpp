// StatusBarInterface.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChartAuto.h"
#include "StatusBarInterface.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusBarInterface

IMPLEMENT_DYNCREATE(CStatusBarInterface, CCmdTarget)

CStatusBarInterface::CStatusBarInterface()
{
	EnableAutomation();
}

CStatusBarInterface::~CStatusBarInterface()
{
}


void CStatusBarInterface::OnFinalRelease()
{
	// Nachdem die letzte Referenz auf ein Automatisierungsobjekt freigegeben wurde,
	// wird OnFinalRelease aufgerufen. Die Basisklasse l�scht das Objekt
	// automatisch. F�gen Sie zus�tzlichen Bereinigungscode f�r Ihr Objekt
	// hinzu, bevor Sie die Basisklasse aufrufen.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CStatusBarInterface, CCmdTarget)
	//{{AFX_MSG_MAP(CStatusBarInterface)
		// HINWEIS - Der Klassen-Assistent f�gt hier Zuordnungsmakros ein und entfernt diese.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CStatusBarInterface, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CStatusBarInterface)
	DISP_PROPERTY_NOTIFY(CStatusBarInterface, "status", m_status, OnStatusChanged, VT_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Hinweis: Wir stellen Unterst�tzung f�r IID_IStatusBarInterface zur Verf�gung, um typsicheres Binden
//  von VBA zu erm�glichen. Diese IID muss mit der GUID �bereinstimmen, die in der
//  Disp-Schnittstelle in der .ODL-Datei angegeben ist.

// {D3A9E441-0521-11D2-B525-006097A8F69A}
static const IID IID_IStatusBarInterface =
{ 0xd3a9e441, 0x521, 0x11d2, { 0xb5, 0x25, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };

BEGIN_INTERFACE_MAP(CStatusBarInterface, CCmdTarget)
	INTERFACE_PART(CStatusBarInterface, IID_IStatusBarInterface, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen f�r Nachrichten CStatusBarInterface 

void CStatusBarInterface::OnStatusChanged() 
{
   CMainFrame *pFrame;

   pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;

   pFrame->ShowStatus (m_status);
}

