// StockBrowser.cpp : Legt das Klassenverhalten f�r die Anwendung fest.
//

#include "stdafx.h"
#include "StockBrowser.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "StockBrowserDoc.h"
#include "StockBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp

BEGIN_MESSAGE_MAP(CStockBrowserApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// Dateibasierte Standard-Dokumentbefehle
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard-Druckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp Konstruktion

CStockBrowserApp::CStockBrowserApp()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einf�gen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CStockBrowserApp-Objekt

CStockBrowserApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp Initialisierung

BOOL CStockBrowserApp::InitInstance()
{
	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Gr��e Ihrer fertigen 
	//  ausf�hrbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht ben�tigen, entfernen.


	// �ndern des Registrierungsschl�ssels, unter dem unsere Einstellungen gespeichert sind.
	// ZU ERLEDIGEN: Sie sollten dieser Zeichenfolge einen geeigneten Inhalt geben
	// wie z.B. den Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Addison Wesley"));

	LoadStdProfileSettings();  // Standard INI-Dateioptionen laden (einschlie�lich MRU)

	// Dokumentvorlagen der Anwendung registrieren. Dokumentvorlagen
	//  dienen als Verbindung zwischen Dokumenten, Rahmenfenstern und Ansichten.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_STOCKBTYPE,
		RUNTIME_CLASS(CStockBrowserDoc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CStockBrowserView));
	AddDocTemplate(pDocTemplate);

	// Haupt-MDI-Rahmenfenster erzeugen
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// �ffnen per DragDrop aktivieren
	m_pMainWnd->DragAcceptFiles();

	// DDE-Execute-Open aktivieren
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// Befehlszeile parsen, um zu pr�fen auf Standard-Umgebungsbefehle DDE, Datei offen
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Verteilung der in der Befehlszeile angegebenen Befehle
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Das Hauptfenster ist initialisiert und kann jetzt angezeigt und aktualisiert werden.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialog f�r Info �ber Anwendung

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogdaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// Anwendungsbefehl zum Ausf�hren des Dialogfelds
void CStockBrowserApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CStockBrowserApp-Nachrichtenbehandlungsroutinen
