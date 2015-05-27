#if !defined(AFX_QUOTES_H__8573C03F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_QUOTES_H__8573C03F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Quotes.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// DAO Satzgruppe CQuotes 

class CQuotes : public CDaoRecordset
{
public:
	CQuotes(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CQuotes)

// Feld-/Parameterdaten
	//{{AFX_FIELD(CQuotes, CDaoRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	long	m_Aktiennummer2;
	COleDateTime	m_Datum;
	COleCurrency	m_Kurs;
	//}}AFX_FIELD

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CQuotes)
	public:
	virtual CString GetDefaultDBName();		// Standard-Datenbankname
	virtual CString GetDefaultSQL();		// Standard-SQL für Satzgruppe
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_QUOTES_H__8573C03F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_
