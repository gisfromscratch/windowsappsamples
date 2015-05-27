#if !defined(AFX_QUOTES_H__CEFC5F41_53F2_11D2_B3CE_006097A8F69A__INCLUDED_)
#define AFX_QUOTES_H__CEFC5F41_53F2_11D2_B3CE_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Quotes.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Satzgruppe CQuotes 

class CQuotes : public CRecordset
{
public:
	CQuotes(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CQuotes)

// Feld-/Parameterdaten
	//{{AFX_FIELD(Quotes, CRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	long	m_Aktiennummer2;
	CTime	m_Datum;
	CString	m_Kurs;
	//}}AFX_FIELD


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(Quotes)
	public:
	virtual CString GetDefaultConnect();    // Standard-Verbindungszeichenfolge
	virtual CString GetDefaultSQL();    // Standard-SQL für Satzgruppe
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_QUOTES_H__CEFC5F41_53F2_11D2_B3CE_006097A8F69A__INCLUDED_
