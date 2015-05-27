// ChartProperty.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "StockChartWithDll.h"
#include "StockChartWithDllDoc.h"
#include "ChartProperty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CChartProperty 


CChartProperty::CChartProperty(CStockChartWithDllDoc *pDoc, CWnd* pParent /*=NULL*/)
	: CDialog(CChartProperty::IDD, pParent),
     pDoc (pDoc)
{
	//{{AFX_DATA_INIT(CChartProperty)
	m_bGrid = FALSE;
	m_nColor = -1;
	m_bAverage = FALSE;
	m_nAverageCnt = 5;
	//}}AFX_DATA_INIT
}


void CChartProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChartProperty)
	DDX_Check(pDX, IDC_CHECK_GRID, m_bGrid);
	DDX_Radio(pDX, IDC_RADIO_RED, m_nColor);
	DDX_Check(pDX, IDC_CHECK_LINE, m_bAverage);
	DDX_Slider(pDX, IDC_SLIDER_AVERAGE, m_nAverageCnt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChartProperty, CDialog)
	//{{AFX_MSG_MAP(CChartProperty)
	ON_BN_CLICKED(ID_APPLY_NOW, OnApplyNow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CChartProperty 

void CChartProperty::OnApplyNow() 
{
   //DDX ausführen
   UpdateData (TRUE); 
   pDoc->OnPropertyChange (TRUE, FALSE);	
}

void CChartProperty::OnCancel() 
{
   pDoc->OnPropertyChange (FALSE, TRUE);
}

void CChartProperty::OnOK() 
{
   //DDX ausführen
   UpdateData (TRUE); 
   pDoc->OnPropertyChange (TRUE, TRUE);
}


BOOL CChartProperty::Create()
{	
// Namen der Aktie in den Titel übernehmen
   if (CDialog::Create(IDD)) {
      ASSERT_VALID (pDoc);
      SetWindowText (pDoc->m_name);
      return true;
   }
   else {
      return false;
   }	
}

BOOL CChartProperty::OnInitDialog() 
{
	CSliderCtrl *sl = (CSliderCtrl*) GetDlgItem (IDC_SLIDER_AVERAGE);
   sl->SetRange (sliderRangeMin, sliderRangeMax);

   CDialog::OnInitDialog();
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}
