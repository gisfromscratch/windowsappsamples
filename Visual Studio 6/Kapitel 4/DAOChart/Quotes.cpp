// Quotes.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "DAOChart.h"
#include "Quotes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CQuotes

IMPLEMENT_DYNAMIC(CQuotes, CDaoRecordset)

CQuotes::CQuotes(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CQuotes)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_Aktiennummer2 = 0;
	m_Datum = (DATE)0;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}


extern CDAOChartApp theApp;

CString CQuotes::GetDefaultDBName()
{  
   return theApp.strDBName;
}


CString CQuotes::GetDefaultSQL()
{
   return _T("[Aktie],[Kurs]");
}

void CQuotes::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CQuotes)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[Aktie].[Aktiennummer]"), m_Aktiennummer);
	DFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	DFX_Long(pFX, _T("[WKN]"), m_WKN);
	DFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	DFX_Long(pFX, _T("[Kurs].[Aktiennummer]"), m_Aktiennummer2);
	DFX_DateTime(pFX, _T("[Datum]"), m_Datum);
	DFX_Currency(pFX, _T("[Kurs]"), m_Kurs);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// Diagnose CQuotes

#ifdef _DEBUG
void CQuotes::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CQuotes::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
