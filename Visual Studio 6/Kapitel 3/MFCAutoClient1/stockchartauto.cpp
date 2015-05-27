// Von Klassen-Assistent automatisch erstellte IDispatch-Kapselungsklasse(n).

#include "stdafx.h"
#include "stockchartauto.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// Eigenschaften IStockChartAuto 

long IStockChartAuto::GetId()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void IStockChartAuto::SetId(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

CString IStockChartAuto::GetName()
{
	CString result;
	GetProperty(0x2, VT_BSTR, (void*)&result);
	return result;
}

void IStockChartAuto::SetName(LPCTSTR propVal)
{
	SetProperty(0x2, VT_BSTR, propVal);
}

LPDISPATCH IStockChartAuto::GetStatusbar()
{
	LPDISPATCH result;
	GetProperty(0x3, VT_DISPATCH, (void*)&result);
	return result;
}

void IStockChartAuto::SetStatusbar(LPDISPATCH propVal)
{
	SetProperty(0x3, VT_DISPATCH, propVal);
}

CString IStockChartAuto::GetTicker()
{
	CString result;
	GetProperty(0x4, VT_BSTR, (void*)&result);
	return result;
}

void IStockChartAuto::SetTicker(LPCTSTR propVal)
{
	SetProperty(0x4, VT_BSTR, propVal);
}

BOOL IStockChartAuto::GetAverage()
{
	BOOL result;
	GetProperty(0x5, VT_BOOL, (void*)&result);
	return result;
}

void IStockChartAuto::SetAverage(BOOL propVal)
{
	SetProperty(0x5, VT_BOOL, propVal);
}

long IStockChartAuto::GetAveragecnt()
{
	long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}

void IStockChartAuto::SetAveragecnt(long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}

BOOL IStockChartAuto::GetGrid()
{
	BOOL result;
	GetProperty(0x7, VT_BOOL, (void*)&result);
	return result;
}

void IStockChartAuto::SetGrid(BOOL propVal)
{
	SetProperty(0x7, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// Operationen IStockChartAuto 

void IStockChartAuto::ShowWindow()
{
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IStockChartAuto::SetColor(short red, short green, short blue)
{
	static BYTE parms[] =
		VTS_I2 VTS_I2 VTS_I2;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 red, green, blue);
}

BOOL IStockChartAuto::SaveFile(LPCTSTR pathName)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		pathName);
	return result;
}

BOOL IStockChartAuto::ImportFile(LPCTSTR pathName)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		pathName);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// Eigenschaften IStatusBarInterface 

CString IStatusBarInterface::GetStatus()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void IStatusBarInterface::SetStatus(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// Operationen IStatusBarInterface 
