// MFCAutoClient1.cpp : Legt das Klassenverhalten für die Anwendung fest.
//

#include "stdafx.h"
#include "MFCAutoClient1.h"
#include "MFCAutoClient1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1App

BEGIN_MESSAGE_MAP(CMFCAutoClient1App, CWinApp)
	//{{AFX_MSG_MAP(CMFCAutoClient1App)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1App Konstruktion

CMFCAutoClient1App::CMFCAutoClient1App()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CMFCAutoClient1App-Objekt

CMFCAutoClient1App theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1App Initialisierung

BOOL CMFCAutoClient1App::InitInstance()
{
	// OLE-Bibliotheken initialisieren
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Größe Ihrer fertigen 
	//  ausführbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht benötigen, entfernen.

#ifdef _AFXDLL
	Enable3dControls();			// Diese Funktion bei Verwendung von MFC in gemeinsam genutzten DLLs aufrufen
#else
	Enable3dControlsStatic();	// Diese Funktion bei statischen MFC-Anbindungen aufrufen
#endif

	// Befehlszeile parsen, um festzustellen, ob Ausführung als OLE-Server erfolgt
	if (RunEmbedded() || RunAutomated())
	{
		// Alle OLE-Server (-fabriken) als aktiv registrieren. Dies aktiviert die
		//  OLE-Bibliotheken, um Objekte von anderen Anwendungen zu erstellen.
		COleTemplateServer::RegisterAll();
	}
	else
	{
		// Wird eine Server-Anwendung im Standalone-Modus betrieben, ist es ratsam,
		//  die Systemregistrierung zu aktualisieren, falls diese beschädigt wurde.
		COleObjectFactory::UpdateRegistryAll();
	}

	CMFCAutoClient1Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// ZU ERLEDIGEN: Fügen Sie hier Code ein, um ein Schließen des
		//  Dialogfelds über OK zu steuern
	}
	else if (nResponse == IDCANCEL)
	{
		// ZU ERLEDIGEN: Fügen Sie hier Code ein, um ein Schließen des
		//  Dialogfelds über "Abbrechen" zu steuern
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zurückliefern, so dass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}
