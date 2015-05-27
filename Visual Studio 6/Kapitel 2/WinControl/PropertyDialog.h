#pragma once

// PropertyDialog.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// CPropertyDialog

#include "IconPage.h"	// Hinzugef�gt von ClassView
#include "SliderPage.h"	// Hinzugef�gt von ClassView
#include "BitmapPage.h"	// Hinzugef�gt von ClassView


class CPropertyDialog : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropertyDialog)

// Konstruktion
public:
	CPropertyDialog(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertyDialog(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attribute
public:

// Operationen
public:

// �berschreibungen

// Implementierung
public:
	virtual ~CPropertyDialog();

	// Generierte Nachrichtenzuordnungsfunktionen
protected:
	DECLARE_MESSAGE_MAP()
private:
	CBitmapPage m_BitmapPage;
	CSliderPage m_SliderPage;
	CIconPage m_IconPage;
};

/////////////////////////////////////////////////////////////////////////////

