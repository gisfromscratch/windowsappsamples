#if !defined(AFX_SHARES_H__55AC958E_53E1_11D2_B3CE_006097A8F69A__INCLUDED_)
#define AFX_SHARES_H__55AC958E_53E1_11D2_B3CE_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shares.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Satzgruppe CShares 

class CShares : public CRecordset
{
public:
	CShares(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CShares)

// Feld-/Parameterdaten
	//{{AFX_FIELD(CShares, CRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	//}}AFX_FIELD


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CShares)
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

#endif // AFX_SHARES_H__55AC958E_53E1_11D2_B3CE_006097A8F69A__INCLUDED_
