// StockODBCSet.cpp : Implementierung der Klasse CStockODBCSet
//

#include "stdafx.h"
#include "StockODBC.h"
#include "StockODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockODBCSet Implementierung

IMPLEMENT_DYNAMIC(CStockODBCSet, CRecordset)

CStockODBCSet::CStockODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStockODBCSet)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStockODBCSet::GetDefaultConnect()
{
   return _T("ODBC;DSN=Aktien");
}

CString CStockODBCSet::GetDefaultSQL()
{
	return _T("[Aktie]");
}

void CStockODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStockODBCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Aktiennummer]"), m_Aktiennummer);
	RFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	RFX_Long(pFX, _T("[WKN]"), m_WKN);
	RFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStockODBCSet Diagnose

#ifdef _DEBUG
void CStockODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStockODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
