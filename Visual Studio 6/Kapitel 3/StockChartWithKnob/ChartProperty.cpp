// ChartProperty.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChart.h"
#include "StockChartDoc.h"
#include "ChartProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CChartProperty 


CChartProperty::CChartProperty(CStockChartDoc *pDoc, CWnd* pParent /*=NULL*/)
	: CDialog(CChartProperty::IDD, pParent),
     pDoc (pDoc)
{
	//{{AFX_DATA_INIT(CChartProperty)
	m_bGrid = FALSE;
	m_nColor = -1;
	m_bAverage = FALSE;
	m_nAverageCnt = 0;
	//}}AFX_DATA_INIT
}


void CChartProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChartProperty)
	DDX_Check(pDX, IDC_CHECK_GRID, m_bGrid);
	DDX_Radio(pDX, IDC_RADIO_RED, m_nColor);
	DDX_Check(pDX, IDC_CHECK_LINE, m_bAverage);
	DDX_OCInt(pDX, IDC_KNOBCTRL1, DISPID(2), m_nAverageCnt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChartProperty, CDialog)
	//{{AFX_MSG_MAP(CChartProperty)
	ON_BN_CLICKED(ID_APPLY_NOW, OnApplyNow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen f�r Nachrichten CChartProperty 

void CChartProperty::OnApplyNow() 
{
   //DDX ausf�hren
   UpdateData (TRUE); 
   pDoc->OnPropertyChange (TRUE, FALSE);	
}

void CChartProperty::OnCancel() 
{
   pDoc->OnPropertyChange (FALSE, TRUE);
}

void CChartProperty::OnOK() 
{
   //DDX ausf�hren
   UpdateData (TRUE); 
   pDoc->OnPropertyChange (TRUE, TRUE);
}


BOOL CChartProperty::Create()
{	
// Namen der Aktie in den Titel �bernehmen
   if (CDialog::Create(IDD)) {
      ASSERT_VALID (pDoc);
      SetWindowText (pDoc->m_name);
      return true;
   }
   else {
      return false;
   }	
}


BEGIN_EVENTSINK_MAP(CChartProperty, CDialog)
    //{{AFX_EVENTSINK_MAP(CChartProperty)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

