// Mit Microsoft Visual C++ automatisch erstellte IDispatch-Kapselungsklasse(n).

// HINWEIS: Die Inhalte dieser Datei nicht ändern. Wenn Microsoft Visual C++
// diese Klasse erneuert, werden Ihre Änderungen überschrieben.


#include "stdafx.h"
#include "knob.h"

/////////////////////////////////////////////////////////////////////////////
// CKnob

IMPLEMENT_DYNCREATE(CKnob, CWnd)

/////////////////////////////////////////////////////////////////////////////
// Eigenschaften CKnob 

OLE_COLOR CKnob::GetBackColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_BACKCOLOR, VT_I4, (void*)&result);
	return result;
}

void CKnob::SetBackColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_BACKCOLOR, VT_I4, propVal);
}

OLE_COLOR CKnob::GetForeColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_FORECOLOR, VT_I4, (void*)&result);
	return result;
}

void CKnob::SetForeColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_FORECOLOR, VT_I4, propVal);
}

long CKnob::GetValue()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void CKnob::SetValue(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

long CKnob::GetMaxValue()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void CKnob::SetMaxValue(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// Operationen CKnob 

void CKnob::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
