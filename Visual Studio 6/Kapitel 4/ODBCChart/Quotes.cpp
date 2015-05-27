// Quotes.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "ODBCChart.h"
#include "Quotes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuotes

IMPLEMENT_DYNAMIC(CQuotes, CRecordset)

CQuotes::CQuotes(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CQuotes)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_Aktiennummer2 = 0;
	m_Kurs = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CQuotes::GetDefaultConnect()
{
	return _T("ODBC;DSN=Aktien");
}

CString CQuotes::GetDefaultSQL()
{
	return _T("[Aktie],[Kurs]");
}

void CQuotes::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CQuotes)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Aktie].[Aktiennummer]"), m_Aktiennummer);
	RFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	RFX_Long(pFX, _T("[WKN]"), m_WKN);
	RFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	RFX_Long(pFX, _T("[Kurs].[Aktiennummer]"), m_Aktiennummer2);
	RFX_Date(pFX, _T("[Datum]"), m_Datum);
	RFX_Text(pFX, _T("[Kurs]"), m_Kurs);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CQuotes

#ifdef _DEBUG
void CQuotes::AssertValid() const
{
	CRecordset::AssertValid();
}

void CQuotes::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
