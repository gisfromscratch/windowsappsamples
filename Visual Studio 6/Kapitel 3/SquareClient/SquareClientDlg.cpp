// SquareClientDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "SquareClient.h"
#include "SquareClientDlg.h"

// Von Hand eingefügt:
#include "afxole.h"

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
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
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
// CSquareClientDlg Dialogfeld

CSquareClientDlg::CSquareClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSquareClientDlg::IDD, pParent),
     m_pISquare (NULL)
{
	m_strOut = _T("");
	m_nIn = 0;
	m_strMessage = _T("");
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSquareClientDlg::~CSquareClientDlg ()
{
   // Wenn noch eine ISquare-Schnittstelle gehalten wird, diese freigeben
   if (m_pISquare) 
   {
      m_pISquare->Release ();
   }
}


void CSquareClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_OUT, m_strOut);
	DDX_Text(pDX, IDC_EDIT1, m_nIn);
	DDX_Text(pDX, IDC_STATIC_MSG, m_strMessage);
}

BEGIN_MESSAGE_MAP(CSquareClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, OnRadioATL)
	ON_BN_CLICKED(IDC_RADIO2, OnRadioCpp)
	ON_BN_CLICKED(IDC_RADIO3, OnRadioCppNested)
	ON_BN_CLICKED(IDC_RADIO4, OnRadioMFC)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSquareClientDlg Nachrichten-Handler

BOOL CSquareClientDlg::OnInitDialog()
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
	
   // Zunächst Eingabefeld abschalten
   EnableInput (false);
   	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CSquareClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSquareClientDlg::OnPaint() 
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
HCURSOR CSquareClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSquareClientDlg::OnRadioATL() 
{
   // CLSID des ATL-Servers
   static const CString strCLSID (_T("{547E8381-F175-11D1-90A2-D0DD2F7ACA49}"));

   if (AttachToServer (strCLSID)) 
   {
      m_strMessage = _T("Verbunden mit ATL-Server: ") + strCLSID;
      EnableInput (true);
   }
   else
   {
      m_strMessage = _T("Verbindung mit ATL-Server konnte nicht hergestellt werden.");
      EnableInput (false);
   }

   UpdateData (false);
}

void CSquareClientDlg::OnRadioCpp() 
{
   // CLSID des Cpp-Servers
   static const CString strCLSID (_T("{B8EF6063-F1C2-11d1-90A2-D0DD2F7ACA49}"));

   if (AttachToServer (strCLSID))
   {
      m_strMessage = _T("Verbunden mit CPP-Server: ") + strCLSID;
      EnableInput (true);
   }
   else
   {
      m_strMessage = _T("Verbindung mit CPP-Server konnte nicht hergestellt werden.");
      EnableInput (false);
   }

   UpdateData (false);
}

void CSquareClientDlg::OnRadioCppNested() 
{
   // CLSID des Cpp-Servers (nested)
   static const CString strCLSID (_T("{E3C91780-F24F-11d1-90A2-D0DD2F7ACA49}"));

   if (AttachToServer (strCLSID))
   {
      m_strMessage = _T("Verbunden mit CPP-Server (nested): ") + strCLSID;
      EnableInput (true);
   }
   else
   {
      m_strMessage = _T("Verbindung mit CPP-Server (nested)"
                        " konnte nicht hergestellt werden.");
      EnableInput (false);
   }

   UpdateData (false);
}

void CSquareClientDlg::OnRadioMFC() 
{
   // CLSID des MFC-Servers
   static const CString strCLSID (_T("{4831F131-F290-11D1-90A2-D0DD2F7ACA49}"));

   if (AttachToServer (strCLSID))
   {
      m_strMessage = _T("Verbunden mit MFC-Server: ") + strCLSID;
      EnableInput (true);
   }
   else
   {
      m_strMessage = _T("Verbindung mit MFC-Server konnte nicht hergestellt werden.");
      EnableInput (false);
   }


   UpdateData (false);
}

//////////////////////////////////////////////////////////////////
// AttachToServer
//
// Diese Funktion baut die Verbindung mit dem COM-Server auf.
//
BOOL CSquareClientDlg::AttachToServer(const CString & strCLSID)
{
   // IID für ISquare als String:
   static const CString strIIDSquare (_T("{547E8380-F175-11D1-90A2-D0DD2F7ACA49}"));
   CLSID clsid;
   IID iid;
   HRESULT hRes;
   IUnknown *pIUnknown;
   IClassFactory *pIClassFactory;

   // Wenn noch eine ISquare-Schnittstelle gehalten wird, diese erst freigeben:
   if (m_pISquare) 
   {
      m_pISquare->Release ();
      m_pISquare = NULL;
   }
      

   // String in eine CLSID umwandeln:
   if (FAILED(AfxGetClassIDFromString (strCLSID, &clsid)))
   {
      MessageBox (_T("CLSID hat ungültiges Format"));
      return false;
   }

   // String in eine IID umwandeln:
   if (FAILED(AfxGetClassIDFromString (strIIDSquare, &iid)))
   {
      MessageBox (_T("IID hat ungültiges Format"));
      return false;
   }
   
   // Zeiger auf IUnknown-Schnittstelle besorgen:
   hRes = CoGetClassObject (clsid, CLSCTX_ALL, NULL, IID_IUnknown, (void**)&pIUnknown);
   if (FAILED (hRes))
   {
      ShowCOMError (hRes);
      return false;
   }

   // Fragen, ob das Klassenobjekt eine Klassenfabrik implementiert:
   pIUnknown->QueryInterface (IID_IClassFactory, (void**)&pIClassFactory);
   // IUnknown-Schnittstelle freigeben:
   pIUnknown->Release ();
   if (!pIClassFactory) 
   {
      MessageBox (_T("COM-Server hat keine Klassenfabrik!"));
      return false;
   }

   // Object instanziieren, ISquare-Schnittstelle anfordern:
   pIClassFactory->CreateInstance (NULL, iid, (void**)&m_pISquare);
   // IClassFactory-Schnittstelle freigeben:
   pIClassFactory->Release ();
   if (!m_pISquare)
   {  
      MessageBox (_T("Konnte kein Objekt erzeugen"));
      m_pISquare = NULL;
      return false;
   }

   return true;
}



void CSquareClientDlg::ShowCOMError(HRESULT hRes)
{
   CString strErr;

   switch (hRes) {
      case REGDB_E_CLASSNOTREG:
         strErr = _T("CLSID nicht registriert.");
         break;

      case CO_E_DLLNOTFOUND:
         strErr = _T("COM-Server-DLL nicht gefunden");
         break;

      case CO_E_APPNOTFOUND:
         strErr = _T("COM-Server-EXE nicht gefunden");
         break;

      case E_ACCESSDENIED:
         strErr = _T("Zugriffsfehler");
         break;

      case CO_E_ERRORINDLL:
         strErr = _T("Fehler in COM-Server-Datei");
         break;

      case CO_E_APPDIDNTREG:
         strErr = _T("Server gestartet, aber hat sich nicht registriert!");
         break;

      default:
         strErr = _T("Unbekannter Fehler");
         break;
   }

   MessageBox (strErr);
}

void CSquareClientDlg::OnOK() 
{
   // Nur ausführen, wenn eine Verbindung mit einem COM-Server besteht:
   if (m_pISquare)
   {
      long nResult;

      UpdateData (true);
      // Methode des COM-Servers aufrufen:
      m_pISquare->GetSquare (m_nIn, &nResult);
      m_strOut.Format ("%li", nResult);

      UpdateData (false);
   }
}

void CSquareClientDlg::EnableInput(BOOL bEnable)
{
   if (bEnable) 
      GetDlgItem (IDC_EDIT1)->EnableWindow (true);
   else
      GetDlgItem (IDC_EDIT1)->EnableWindow (false);

   m_nIn = 0;
   m_strOut = _T("");

   UpdateData (false);
}
