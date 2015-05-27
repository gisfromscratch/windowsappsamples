// StockChartProperty.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChartOle.h"
#include "StockChartProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockChartProperty 


CStockChartProperty::CStockChartProperty(CWnd* pParent /*=NULL*/)
	: CDialog(CStockChartProperty::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStockChartProperty)
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CStockChartProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockChartProperty)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockChartProperty, CDialog)
	//{{AFX_MSG_MAP(CStockChartProperty)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CStockChartProperty 
