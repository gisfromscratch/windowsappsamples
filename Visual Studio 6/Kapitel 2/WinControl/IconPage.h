#pragma once

// IconPage.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CIconPage 

class CIconPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CIconPage)

// Konstruktion
public:
	CIconPage();
	~CIconPage();

// Dialogfelddaten
	enum { IDD = IDD_DIALOG_SHEET1 };


// �berschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()

};

