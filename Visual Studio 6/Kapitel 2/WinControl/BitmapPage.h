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


// Überschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()

};

