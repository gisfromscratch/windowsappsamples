// StockODBCSet.h : Schnittstelle der Klasse CStockODBCSet
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKODBCSET_H__39EDB6E2_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)
#define AFX_STOCKODBCSET_H__39EDB6E2_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockODBCSet : public CRecordset
{
public:
	CStockODBCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStockODBCSet)

// Feld-/Parameterdaten
	//{{AFX_FIELD(CStockODBCSet, CRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	//}}AFX_FIELD

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockODBCSet)
	public:
	virtual CString GetDefaultConnect();	// Standard-Verbindungszeichenfolge
	virtual CString GetDefaultSQL(); 	// Standard-SQL für Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_STOCKODBCSET_H__39EDB6E2_4F0C_11D2_B3BF_006097A8F69A__INCLUDED_)

