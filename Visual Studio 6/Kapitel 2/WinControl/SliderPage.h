#pragma once

// SliderPage.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CSliderPage 

class CSliderPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSliderPage)

// Konstruktion
public:
	CSliderPage();
	~CSliderPage();

// Dialogfelddaten
	enum { IDD = IDD_DIALOG_SHEET2 };


// ‹berschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-UnterstŁtzung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()

};

