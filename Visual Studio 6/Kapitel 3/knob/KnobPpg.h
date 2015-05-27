#if !defined(AFX_KNOBPPG_H__21D56987_2604_11D2_B59C_006097A8F69A__INCLUDED_)
#define AFX_KNOBPPG_H__21D56987_2604_11D2_B59C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// KnobPpg.h: Deklaration der Eigenschaftenseitenklasse CKnobPropPage.

////////////////////////////////////////////////////////////////////////////
// CKnobPropPage: Siehe KnobPpg.cpp.cpp für Implementierung

class CKnobPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CKnobPropPage)
	DECLARE_OLECREATE_EX(CKnobPropPage)

// Konstruktor
public:
	CKnobPropPage();

// Dialogfelddaten
	//{{AFX_DATA(CKnobPropPage)
	enum { IDD = IDD_PROPPAGE_KNOB };
	long	m_nMaxValue;
	//}}AFX_DATA

// Implementierung
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Nachrichtenzuordnungstabellen
protected:
	//{{AFX_MSG(CKnobPropPage)
		// HINWEIS - Der Klassen-Assistent fügt Member-Funktionen hier ein und entfernt diese.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_KNOBPPG_H__21D56987_2604_11D2_B59C_006097A8F69A__INCLUDED)
