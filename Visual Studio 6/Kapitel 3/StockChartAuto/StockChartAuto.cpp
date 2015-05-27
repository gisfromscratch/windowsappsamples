// StockChartAuto.cpp : Legt das Klassenverhalten für die Anwendung fest.
//

#include "stdafx.h"
#include "StockChartAuto.h"


#include "MainFrm.h"
#include "ChildFrm.h"
#include "StockChartAutoDoc.h"
#include "StockChartAutoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoApp

BEGIN_MESSAGE_MAP(CStockChartAutoApp, CWinApp)
	//{{AFX_MSG_MAP(CStockChartAutoApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
	// Dateibasierte Standard-Dokumentbefehle
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard-Druckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoApp Konstruktion

CStockChartAutoApp::CStockChartAutoApp()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CStockChartAutoApp-Objekt

CStockChartAutoApp theApp;

// Dieser Bezeichner wurde als statistisch eindeutig für Ihre Anwendung generiert.
// Sie können ihn ändern, wenn Sie einen bestimmten Bezeichnernamen bevorzugen.

// {CFDB3164-0122-11D2-B51C-006097A8F69A}
static const CLSID clsid =
{ 0xcfdb3164, 0x122, 0x11d2, { 0xb5, 0x1c, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoApp Initialisierung

BOOL CStockChartAutoApp::InitInstance()
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
		RUNTIME_CLASS(CStockChartAutoDoc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CStockChartAutoView));
	AddDocTemplate(pDocTemplate);

	// Verbinden des COleTemplateServer mit der Dokumentvorlage.
	//  Der COleTemplateServer legt auf Basis der Informationen in der
	//  Dokumentvorlage bei der Anforderung von OLE-Containern
	//  neue Dokumente an.
	m_server.ConnectTemplate(clsid, pDocTemplate, FALSE);

	// Alle OLE-Server (-fabriken) als aktiv registrieren. Dies aktiviert die
	//  OLE-Bibliotheken, um Objekte von anderen Anwendungen zu erstellen.
	COleTemplateServer::RegisterAll();
		// Hinweis: MDI-Anwendungen registrieren alle Server-Objekte, ohne Rücksicht
		//  auf die Parameter /Embedding oder /Automation in der Befehlszeile.

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

	// Testen, ob Ausführung als OLE-Server
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Anwendung mit /Embedding oder /Automation gestartet. In diesem Fall
		//  kein Hauptfenster anzeigen.
		return TRUE;
	}

	// Wird eine Server-Anwendung im Standalone-Modus betrieben, ist es ratsam,
	//  die Systemregistrierung zu aktualisieren, falls diese beschädigt wurde.
	m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
	COleObjectFactory::UpdateRegistryAll();

   // Registrierung der Typbibliothek
   GUID typeLibGUID;
   AfxGetClassIDFromString (_T("{CFDB3165-0122-11D2-B51C-006097A8F69A}"), &typeLibGUID);
   AfxOleRegisterTypeLib (AfxGetInstanceHandle(), typeLibGUID);

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
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// Anwendungsbefehl, um das Dialogfeld aufzurufen
void CStockChartAutoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartAutoApp-Befehle
