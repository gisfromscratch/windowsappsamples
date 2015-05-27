// StockDAOSet.cpp : Implementierung der Klasse CStockDAOSet
//

#include "stdafx.h"
#include "StockDAO.h"
#include "StockDAOSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockDAOSet Implementierung

IMPLEMENT_DYNAMIC(CStockDAOSet, CDaoRecordset)

CStockDAOSet::CStockDAOSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStockDAOSet)
	m_Aktiennummer = 0;
	m_Aktienname = _T("");
	m_WKN = 0;
	m_Tickersymbol = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}

CString CStockDAOSet::GetDefaultDBName()
{
   // Dateidialog zum Abfragen der 
   // Datenbank
   CFileDialog fileDialog(true,
                          _T("mdb"), 
                          _T("Aktien.mdb"),
                          NULL,
                          _T("MDB-Dateien (*.mdb)|*.mdb"));

   // Wenn der Benutzer den Dialog mit OK verlassen hat:
   if (IDOK == fileDialog.DoModal ()) { 
      return fileDialog.GetPathName ();
	}
   else {
      return _T("Aktien.mdb");
   }
}


CString CStockDAOSet::GetDefaultSQL()
{
	return _T("[Aktie]");
}

void CStockDAOSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStockDAOSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Long(pFX, _T("[Aktiennummer]"), m_Aktiennummer);
	DFX_Text(pFX, _T("[Aktienname]"), m_Aktienname);
	DFX_Long(pFX, _T("[WKN]"), m_WKN);
	DFX_Text(pFX, _T("[Tickersymbol]"), m_Tickersymbol);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStockDAOSet Diagnose

#ifdef _DEBUG
void CStockDAOSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CStockDAOSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
