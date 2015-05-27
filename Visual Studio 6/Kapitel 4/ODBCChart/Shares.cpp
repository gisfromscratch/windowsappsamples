// Shares.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "ODBCChart.h"
#include "Shares.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShares

IMPLEMENT_DYNAMIC(CShares, CRecordset)

CShares::CShares(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CShares)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CShares::GetDefaultConnect()
{
	return _T("ODBC;DSN=Aktien");
}

CString CShares::GetDefaultSQL()
{
	return _T("[Aktie]");
}

void CShares::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CShares)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Aktiennummer]"), m_Aktiennummer);
	RFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	RFX_Long(pFX, _T("[WKN]"), m_WKN);
	RFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CShares

#ifdef _DEBUG
void CShares::AssertValid() const
{
	CRecordset::AssertValid();
}

void CShares::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
