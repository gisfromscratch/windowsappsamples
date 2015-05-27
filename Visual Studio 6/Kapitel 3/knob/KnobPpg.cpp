// KnobPpg.cpp: Implementierung der Eigenschaftenseitenklasse CKnobPropPage.

#include "stdafx.h"
#include "knob.h"
#include "KnobPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CKnobPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Nachrichtenzuordnungstabelle

BEGIN_MESSAGE_MAP(CKnobPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CKnobPropPage)
	// HINWEIS - Der Klassen-Assistent fügt Nachrichtenzuordnungseinträge hinzu und entfernt diese
	//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Klassenerzeugung und GUID initialisieren

IMPLEMENT_OLECREATE_EX(CKnobPropPage, "KNOB.KnobPropPage.1",
	0x21d56978, 0x2604, 0x11d2, 0xb5, 0x9c, 0, 0x60, 0x97, 0xa8, 0xf6, 0x9a)


/////////////////////////////////////////////////////////////////////////////
// CKnobPropPage::CKnobPropPageFactory::UpdateRegistry -
// Fügt Einträge der Systemregistrierung für CKnobPropPage hinzu oder entfernt diese

BOOL CKnobPropPage::CKnobPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_KNOB_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CKnobPropPage::CKnobPropPage - Konstruktor

CKnobPropPage::CKnobPropPage() :
	COlePropertyPage(IDD, IDS_KNOB_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CKnobPropPage)
	m_nMaxValue = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CKnobPropPage::DoDataExchange - Verschiebt Daten zwischen Dialogfeld+++ und den Variablen+++

void CKnobPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CKnobPropPage)
	DDP_Text(pDX, IDC_EDIT2, m_nMaxValue, _T("MaxValue") );
	DDX_Text(pDX, IDC_EDIT2, m_nMaxValue);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CKnobPropPage-Behandlungsroutinen für Nachrichten
