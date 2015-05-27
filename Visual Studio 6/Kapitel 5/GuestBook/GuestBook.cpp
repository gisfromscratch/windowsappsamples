// GUESTBOOK.CPP - Implementierungsdatei für Ihren Internet-Server
//    GuestBook Extension

#include "stdafx.h"
#include "GuestBook.h"

///////////////////////////////////////////////////////////////////////
// Das einzige CWinApp-Objekt
// HINWEIS: Sie können dieses Objekt entfernen, wenn Sie Ihr Projekt in ein
// Nicht-MFC-Projekt ändern und in einer DLL verwenden.

CWinApp theApp;

///////////////////////////////////////////////////////////////////////
// Tabelle zur Befehlsinterpretation

BEGIN_PARSE_MAP(CGuestBookExtension, CHttpServer)
	// ZU ERLEDIGEN: Fügen Sie Ihr ON_PARSE_COMMAND() ein und 
	// ON_PARSE_COMMAND_PARAMS() hier, um Ihre Befehle einzubinden.
	// Beispiel:

	ON_PARSE_COMMAND(Default, CGuestBookExtension, ITS_EMPTY)
   ON_PARSE_COMMAND(Add, CGuestBookExtension, ITS_PSTR ITS_PSTR)
   ON_PARSE_COMMAND_PARAMS("Name Text")

	DEFAULT_PARSE_COMMAND(Default, CGuestBookExtension)
END_PARSE_MAP(CGuestBookExtension)


///////////////////////////////////////////////////////////////////////
// Das einzige CGuestBookExtension-Objekt

CGuestBookExtension theExtension;


///////////////////////////////////////////////////////////////////////
// CGuestBookExtension Implementierung

CGuestBookExtension::CGuestBookExtension()
{
}

CGuestBookExtension::~CGuestBookExtension()
{
}

BOOL CGuestBookExtension::GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
	// Aufruf der Standardimplementierung für die Initialisierung
	CHttpServer::GetExtensionVersion(pVer);

	// Einlesen der Beschreibungszeichenfolge
	TCHAR sz[HSE_MAX_EXT_DLL_NAME_LEN+1];
	ISAPIVERIFY(::LoadString(AfxGetResourceHandle(),
			IDS_SERVER, sz, HSE_MAX_EXT_DLL_NAME_LEN));
	_tcscpy(pVer->lpszExtensionDesc, sz);
	return TRUE;
}

BOOL CGuestBookExtension::TerminateExtension(DWORD dwFlags)
{
	// Erweiterung wird beendet
	//ZU ERLEDIGEN: Alle Per-Instanz-Ressourcen bereinigen
	return TRUE;
}

///////////////////////////////////////////////////////////////////////
// CGuestBookExtension Befehls-Handler

void CGuestBookExtension::Default(CHttpServerContext* pCtxt)
{
	StartContent(pCtxt);
	WriteTitle(pCtxt);


	*pCtxt << _T("<h1>");
	*pCtxt << _T("Gästebuch");
	*pCtxt << _T("</h1>\r\n");

	*pCtxt << _T("<hr>");

   POSITION pos;
   CEntry anEntry;

   // Kritischer Bereich
   m_cs.Lock (); 
   // Liste der Einträge ausgeben
   pos = entryList.GetHeadPosition ();
   while (pos != NULL) {
      anEntry = entryList.GetNext (pos);
      
      *pCtxt << _T("<b>");
      *pCtxt << anEntry.strName;
      *pCtxt << _T("</b>\r\n<pre>");
      *pCtxt << anEntry.strText;
      *pCtxt << _T("</pre>\r\n");
   	*pCtxt << _T("<hr>");
   }
   // Ende kritischer Bereich
   m_cs.Unlock ();

   // Link auf Hauptseite
   *pCtxt << _T("<a href=\"main.html\">Hauptseite</a>");

	EndContent(pCtxt);
}


void CGuestBookExtension::Add(CHttpServerContext* pCtxt, LPCTSTR name, LPCTSTR message)
{
	StartContent(pCtxt);
	WriteTitle(pCtxt);

   *pCtxt << _T("Folgender Eintrag wurde ins Gästebuch übernommen:");
   *pCtxt << _T("<hr><p><b>");
   *pCtxt << name;
   *pCtxt << _T("</b><p><pre>");
   *pCtxt << message;
   *pCtxt << _T("</pre><hr>");

   // Link auf Hauptseite
   *pCtxt << _T("<a href=\"main.html\">Hauptseite</a>");

	EndContent(pCtxt);

   // Eintrag zusammenbauen
   CEntry anEntry;

   anEntry.strName = name;
   anEntry.strText = message;

   // Eintrag threadsicher zur Liste hinzufügen
   m_cs.Lock ();
   entryList.AddTail (anEntry);
   m_cs.Unlock ();
}

// Die folgenden Zeilen nicht bearbeiten. Sie werden vom Klassenassistenten benötigt.
#if 0
BEGIN_MESSAGE_MAP(CGuestBookExtension, CHttpServer)
	//{{AFX_MSG_MAP(CGuestBookExtension)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0



///////////////////////////////////////////////////////////////////////
// Verwendet Ihre Erweiterung nicht die MFC, benötigen Sie diesen Code, um sicherzustellen,
// dass die Erweiterungsobjekte das Ressourcen-Handle für das Modul finden können.
// Wollen Sie Ihre Erweiterung so umwandeln, dass sie nicht von MFC abhängt,
// entfernen Sie die Kommentare um die nachfolgenden AfxGetResourceHandle()
// und DllMain()-Funktionen sowie die globale Varaible g_hInstance.

/****

static HINSTANCE g_hInstance;

HINSTANCE AFXISAPI AfxGetResourceHandle()
{
	return g_hInstance;
}

BOOL WINAPI DllMain(HINSTANCE hInst, ULONG ulReason,
					LPVOID lpReserved)
{
	if (ulReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInst;
	}

	return TRUE;
}

****/

LPCTSTR CGuestBookExtension::GetTitle() const
{
	return _T("Gästebuch");
}
