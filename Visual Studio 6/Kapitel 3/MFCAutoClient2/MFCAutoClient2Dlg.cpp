// MFCAutoClient2Dlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "MFCAutoClient2.h"
#include "MFCAutoClient2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld f�r Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
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

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient2Dlg Dialogfeld

CMFCAutoClient2Dlg::CMFCAutoClient2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCAutoClient2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCAutoClient2Dlg)
		// HINWEIS: Der Klassenassistent f�gt hier Member-Initialisierung ein
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf ben�tigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAutoClient2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCAutoClient2Dlg)
		// HINWEIS: Der Klassenassistent f�gt an dieser Stelle DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCAutoClient2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMFCAutoClient2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
   ON_WM_DROPFILES()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient2Dlg Nachrichten-Handler

BOOL CMFCAutoClient2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzuf�gen des Men�befehls "Info..." zum Systemmen�.

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

	// Symbol f�r dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Gro�es Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	
   // Hier eigene Initialisierungen
   SetTimer (1, 150, NULL);

   try {
      m_itfStockChart.CreateInstance(__uuidof(Server::Document));
      m_itfStockChart->ShowWindow ();
   }
   catch (_com_error c) {
      MessageBox (c.ErrorMessage());      
   }

   // Drop von Dateien akzeptieren
   DragAcceptFiles ();
	
	return TRUE;  // Geben Sie TRUE zur�ck, au�er ein Steuerelement soll den Fokus erhalten
}

void CMFCAutoClient2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Wollen Sie Ihrem Dialogfeld eine Schaltfl�che "Minimieren" hinzuf�gen, ben�tigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. F�r MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch f�r Sie erledigt.

void CMFCAutoClient2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Ger�tekontext f�r Zeichnen

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

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, w�hrend der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CMFCAutoClient2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCAutoClient2Dlg::OnTimer(UINT nIDEvent) 
{
   static int cnt	= 0;
   static const CString text = 
       "*********************************************"
       " Achtung, das Programm wird ferngesteuert!!! "
       "*********************************************";
   CString str;

   if (cnt > text.GetLength() - 45)
      cnt = 0;
   else
      cnt++;

   str = text.Mid (cnt, 45);

   try {
      Server::IStatusBarInterfacePtr pStatus(m_itfStockChart->Getstatusbar ());

      pStatus->Putstatus (str.AllocSysString ());
   }
   catch (_com_error c) {
      KillTimer (1);
      MessageBox (c.ErrorMessage());
   } 

	
	CDialog::OnTimer(nIDEvent);
}


void CMFCAutoClient2Dlg::OnDropFiles( HDROP hDropInfo )
{
   char lpszBuffer[_MAX_PATH];

   // Nur erste Datei!
   ::DragQueryFile (hDropInfo, 0, lpszBuffer, _MAX_PATH);

   try {
      CString str(lpszBuffer);
      m_itfStockChart->ImportFile (str.AllocSysString());         
   }
   catch (_com_error c) {
      MessageBox (c.ErrorMessage());
   }
   
   ::DragFinish (hDropInfo);
}
