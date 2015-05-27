// StockProperty.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChartX.h"
#include "StockProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockProperty 


CStockProperty::CStockProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CStockProperty::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockProperty)
	m_name = _T("");
	m_nID = 0;
	m_ticker = _T("");
	//}}AFX_DATA_INIT
}


void CStockProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockProperty)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_nID);
	DDV_MinMaxInt(pDX, m_nID, 0, 999999);
	DDX_Text(pDX, IDC_EDIT3, m_ticker);
	DDV_MaxChars(pDX, m_ticker, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockProperty, CDialog)
	//{{AFX_MSG_MAP(CStockProperty)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CStockProperty 
