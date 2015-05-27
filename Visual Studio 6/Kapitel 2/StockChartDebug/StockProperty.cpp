// StockProperty.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChartDebug.h"
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
	m_name = _T("");
	m_nID = 0;
	m_ticker = _T("");
}


void CStockProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_nID);
	DDV_MinMaxInt(pDX, m_nID, 0, 999999);
	DDX_Text(pDX, IDC_EDIT3, m_ticker);
	DDV_MaxChars(pDX, m_ticker, 10);
}


BEGIN_MESSAGE_MAP(CStockProperty, CDialog)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CStockProperty 
