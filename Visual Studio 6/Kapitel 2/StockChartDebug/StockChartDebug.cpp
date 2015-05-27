// StockChartDebug.cpp : Legt das Klassenverhalten für die Anwendung fest.
//

#include "stdafx.h"
#include "StockChartDebug.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "StockChartDebugDoc.h"
#include "StockChartDebugView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartDebugApp

BEGIN_MESSAGE_MAP(CStockChartDebugApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_CHECKPOINT, OnCheckpoint)
	ON_COMMAND(ID_DUMPALLOBJ, OnDumpAllObjectsSince)
	ON_COMMAND(ID_DIFFERENCE, OnDifference)
	// Dateibasierte Standard-Dokumentbefehle
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard-Druckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartDebugApp Konstruktion

CStockChartDebugApp::CStockChartDebugApp()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CStockChartDebugApp-Objekt

CStockChartDebugApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStockChartDebugApp Initialisierung

BOOL CStockChartDebugApp::InitInstance()
{
	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Größe Ihrer fertigen 
	//  ausführbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht benötigen, entfernen.


	// Ändern des Registrierungsschlüssels, unter dem unsere Einstellungen gespeichert sind.
	// Sie sollten dieser Zeichenfolge einen geeigneten Inhalt geben
	// wie z.B. den Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Addison Wesley Longman"));

	LoadStdProfileSettings();  // Standard-INI-Dateioptionen einlesen (einschließlich MRU)

	// Dokumentvorlagen der Anwendung registrieren. Dokumentvorlagen
	//  dienen als Verbindung zwischen Dokumenten, Rahmenfenstern und Ansichten.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_STOCKCTYPE,
		RUNTIME_CLASS(CStockChartDebugDoc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CStockChartDebugView));
	AddDocTemplate(pDocTemplate);

	// Haupt-MDI-Rahmenfenster erzeugen
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// Öffnen per DragDrop aktivieren
	m_pMainWnd->DragAcceptFiles();

	// DDE-Execute-Open aktivieren
	EnableShellOpen(); 
	RegisterShellFileTypes(TRUE);

	// Befehlszeile parsen, um zu prüfen auf Standard-Umgebungsbefehle DDE, Datei offen
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
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

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

// Anwendungsbefehl, um das Dialogfeld aufzurufen
void CStockChartDebugApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartDebugApp-Befehle

void CStockChartDebugApp::OnCheckpoint() 
{
#ifdef _DEBUG
   memoryState.Checkpoint ();
#endif	
}

void CStockChartDebugApp::OnDumpAllObjectsSince() 
{
#ifdef _DEBUG
	memoryState.DumpAllObjectsSince ();
#endif
}



void CStockChartDebugApp::OnDifference() 
{
#ifdef _DEBUG
   CMemoryState ms, diff;
   
   ms.Checkpoint ();
   diff.Difference (memoryState, ms);
   diff.DumpStatistics ();
#endif	
}
