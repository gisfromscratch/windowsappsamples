#if !defined(AFX_GUESTBOOK_H__49A0C69B_4331_11D2_B8FE_006097A8F69A__INCLUDED_)
#define AFX_GUESTBOOK_H__49A0C69B_4331_11D2_B8FE_006097A8F69A__INCLUDED_

// GUESTBOOK.H - Header-Datei f�r Ihren Internet-Server
//    GuestBook Extension

#include "resource.h"


// Klasse f�r Eintr�ge in das G�stebuch
class CEntry 
{
public:
   CString strName;
   CString strText;
};


class CGuestBookExtension : public CHttpServer
{
public:
	CGuestBookExtension();
	~CGuestBookExtension();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//{{AFX_VIRTUAL(CGuestBookExtension)
	public:
	virtual BOOL GetExtensionVersion(HSE_VERSION_INFO* pVer);
	virtual LPCTSTR GetTitle() const;
	//}}AFX_VIRTUAL
	virtual BOOL TerminateExtension(DWORD dwFlags);

	// ZU ERLEDIGEN: Hier Handler f�r Ihre Befehle einf�gen.
	// Beispiel:

	void Default(CHttpServerContext* pCtxt);
   void Add (CHttpServerContext* pCtxt, LPCTSTR name, LPCTSTR message);

	DECLARE_PARSE_MAP()

	//{{AFX_MSG(CGuestBookExtension)
	//}}AFX_MSG

private:
   CCriticalSection m_cs;

   CList <CEntry, CEntry&> entryList;
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_GUESTBOOK_H__49A0C69B_4331_11D2_B8FE_006097A8F69A__INCLUDED)
