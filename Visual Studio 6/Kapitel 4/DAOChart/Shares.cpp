// Shares.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "DAOChart.h"
#include "Shares.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CShares

IMPLEMENT_DYNAMIC(CShares, CDaoRecordset)

CShares::CShares(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CShares)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


extern CDAOChartApp theApp;

CString CShares::GetDefaultDBName()
{
	return theApp.strDBName;
}

CString CShares::GetDefaultSQL()
{
	return _T("[Aktie]");
}

void CShares::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CShares)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[Aktiennummer]"), m_Aktiennummer);
	DFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	DFX_Long(pFX, _T("[WKN]"), m_WKN);
	DFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CShares

#ifdef _DEBUG
void CShares::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CShares::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
