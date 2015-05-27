// FileRobotDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "FileRobot.h"
#include "FileRobotDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CFileRobotDlg Dialogfeld

CFileRobotDlg::CFileRobotDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileRobotDlg::IDD, pParent)
{
	m_strURL = _T("");
	m_strFileName = _T("");
	m_strStatus = _T("");
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
   m_pSession = NULL;
}

CFileRobotDlg::~CFileRobotDlg ()
{
   if (m_pSession)
      delete m_pSession;
}

void CFileRobotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_URL, m_strURL);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_strFileName);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatus);
}

BEGIN_MESSAGE_MAP(CFileRobotDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADDFILE, OnButtonAddFile)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEFILE, OnButtonRemoveFile)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileRobotDlg Nachrichten-Handler

BOOL CFileRobotDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// *** Eigene Initialisierungen kommen hier ***
   try
   {
      // Sitzungsobjekt anlegen:
      m_pSession = new CInternetSession ();

      m_strStatus = _T("Bereit");
   }
   catch (CMemoryException *e)
   {
      m_strStatus = _T("InternetSession-Objekt konnte nicht erzeugt werden!");

      e->Delete ();
   }
	
   // DDX durchführen
   UpdateData (false);
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CFileRobotDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CFileRobotDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CFileRobotDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileRobotDlg::OnButtonAddFile() 
{
	CListBox *pList = (CListBox*)GetDlgItem (IDC_LIST_FILES);
   
   UpdateData ();
   
   if (!m_strURL.IsEmpty () &&
       !m_strFileName.IsEmpty ()) {
      pList->AddString (CreateURL (m_strURL, m_strFileName));
      pList->SelectString (-1, CreateURL (m_strURL, m_strFileName));
   }
	
}

void CFileRobotDlg::OnButtonRemoveFile() 
{
   CListBox *pList = (CListBox*)GetDlgItem (IDC_LIST_FILES);
   pList->DeleteString (pList->GetCurSel ());
   pList->SetCurSel (0);	
}

void CFileRobotDlg::OnButtonStart() 
{
   CListBox *pList = (CListBox*)GetDlgItem (IDC_LIST_FILES);
   CString strURL;
	
   for (int i=0; i<pList->GetCount (); i++) {
      pList->SetCurSel (i);
      pList->GetText (i, strURL);
      GetURLFile (strURL);
	}
}



CString CFileRobotDlg::CreateURL(const CString &strURL, const CString &strFile) const
{
   if (!strURL.Right(1).Compare (_T("/")))
      return strURL + strFile;
   else
      return strURL + _T("/") + strFile;
}


bool CFileRobotDlg::GetURLFile(const CString &strURL)
{
   DWORD dwServiceType;
   CString strServer, strFile;
   INTERNET_PORT nPort;
   CStdioFile *pInFile = NULL;
   CFile outFile;
   int nLoadCnt = 0;
   static const int BUFFERSIZE = 1024;

   char buffer[BUFFERSIZE];

   pInFile = m_pSession->OpenURL (strURL, 1, INTERNET_FLAG_TRANSFER_BINARY);
   if (pInFile &&
       AfxParseURL (strURL, dwServiceType, strServer, strFile, nPort)) {
      CWaitCursor cursor;
      int nCount;

      try {
         // Dateinamen zusammenbauen und Ausgabedatei öffnen:
         ::GetModuleFileName (AfxGetInstanceHandle (), buffer, BUFFERSIZE);
         CString strOutFile = buffer;
         strOutFile = strOutFile.Left (strOutFile.ReverseFind ('\\') + 1)
                    + strFile.Right (strFile.GetLength () - strFile.ReverseFind ('/') - 1);

         outFile.Open (strOutFile, CFile::modeCreate | CFile::modeWrite | CFile::shareExclusive);

         // jetzt Datei übertragen:
         nCount = pInFile->Read (buffer, BUFFERSIZE);
         m_strStatus.Format (_T("%i KB geladen"), nLoadCnt++ * BUFFERSIZE/1024);
         UpdateData (false);
         while (nCount > 0) {
            outFile.Write (buffer, nCount);
            nCount = pInFile->Read (buffer, BUFFERSIZE);
            m_strStatus.Format (_T("%i KB geladen"), nLoadCnt++ * BUFFERSIZE/1024);
            UpdateData (false);
         }

         m_strStatus = _T("Fertig!");
         UpdateData (false);

         // Objekte löschen und Dateien schließen:
         outFile.Close ();

         // Serverdatei schließen und löschen:
         pInFile->Close ();

         delete pInFile;
      } // try

      catch (CInternetException *e) {
         e->ReportError ();
         e->Delete ();

         // Objekte löschen und Dateien schließen:
         outFile.Close ();

         return false;
      }
      catch (CFileException *e) {
         e->ReportError ();
         e->Delete ();

         // Objekte löschen und Dateien schließen:
         outFile.Close ();

         return false;
      }

      return true;
   }      

   // Da ging etwas schief
   else {
      m_strStatus = _T("Fehler in URL!");
      UpdateData (false);

      return false;
   }
}
