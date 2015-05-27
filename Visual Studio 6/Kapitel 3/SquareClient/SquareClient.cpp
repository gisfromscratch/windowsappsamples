// SquareClient.cpp : Legt das Klassenverhalten f�r die Anwendung fest.
//

#include "stdafx.h"
#include "SquareClient.h"
#include "SquareClientDlg.h"

// von Hand eingef�gt
#include "afxole.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSquareClientApp

BEGIN_MESSAGE_MAP(CSquareClientApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSquareClientApp Konstruktion

CSquareClientApp::CSquareClientApp()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einf�gen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CSquareClientApp-Objekt

CSquareClientApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSquareClientApp Initialisierung

BOOL CSquareClientApp::InitInstance()
{
	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Gr��e Ihrer fertigen 
	//  ausf�hrbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht ben�tigen, entfernen.

    // zus�tzlich eingef�gt!!!
    AfxOleInit ();

	CSquareClientDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// ZU ERLEDIGEN: F�gen Sie hier Code ein, um ein Schlie�en des
		//  Dialogfelds �ber OK zu steuern
	}
	else if (nResponse == IDCANCEL)
	{
		// ZU ERLEDIGEN: F�gen Sie hier Code ein, um ein Schlie�en des
		//  Dialogfelds �ber "Abbrechen" zu steuern
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zur�ckliefern, so dass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}
