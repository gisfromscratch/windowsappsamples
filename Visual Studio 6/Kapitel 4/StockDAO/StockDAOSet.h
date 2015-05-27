// StockDAOSet.h : Schnittstelle der Klasse CStockDAOSet
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKDAOSET_H__8573C01F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)
#define AFX_STOCKDAOSET_H__8573C01F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStockDAOSet : public CDaoRecordset
{
public:
	CStockDAOSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStockDAOSet)

// Feld-/Parameterdaten
	//{{AFX_FIELD(CStockDAOSet, CDaoRecordset)
	long	m_Aktiennummer;
	CString	m_Aktienname;
	long	m_WKN;
	CString	m_Tickersymbol;
	//}}AFX_FIELD

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CStockDAOSet)
	public:
	virtual CString GetDefaultDBName();		// �BERABEITEN:  Hier einen Befehl holen
	virtual CString GetDefaultSQL(); 	// Standard-SQL f�r Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);	// RFX-Unterst�tzung
	//}}AFX_VIRTUAL

// Implementierung
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_STOCKDAOSET_H__8573C01F_5C45_11D2_B3E8_006097A8F69A__INCLUDED_)

