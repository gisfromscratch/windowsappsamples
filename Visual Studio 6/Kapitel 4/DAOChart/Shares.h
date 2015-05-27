#if !defined(AFX_SHARES_H__8573C03E_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_SHARES_H__8573C03E_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shares.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// DAO Satzgruppe CShares 

class CShares : public CDaoRecordset
{
public:
	CShares(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CShares)

// Feld-/Parameterdaten
	//{{AFX_FIELD(CShares, CDaoRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	//}}AFX_FIELD

// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CShares)
	public:
	virtual CString GetDefaultDBName();		// Standard-Datenbankname
	virtual CString GetDefaultSQL();		// Standard-SQL f�r Satzgruppe
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_SHARES_H__8573C03E_5C45_11D2_B3E8_006097A8F69A__INCLUDED_
