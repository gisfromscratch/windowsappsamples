#pragma once

// BitmapPage.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CBitmapPage 

class CBitmapPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CBitmapPage)

// Konstruktion
public:
	CBitmapPage();
	~CBitmapPage();

// Dialogfelddaten
	enum { IDD = IDD_DIALOG_SHEET3 };


// �berschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()

};

