// Square.h: Definition der Klasse Square
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SQUARE_H__547E8382_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_)
#define AFX_SQUARE_H__547E8382_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "resource.h"       // Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// Square

class Square : 
	public ISquare,
	public CComObjectRoot,
	public CComCoClass<Square,&CLSID_Square>
{
public:
	Square() {}
BEGIN_COM_MAP(Square)
	COM_INTERFACE_ENTRY(ISquare)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(Square) 
// Entfernen Sie den Kommentar in obiger Zeile, wenn Sie wollen, dass Ihr Objekt
// Aggregation unterstützt.

DECLARE_REGISTRY_RESOURCEID(IDR_Square)

// ISquare
public:
	STDMETHOD (GetSquare) (long value, long *pnResult);
};

#endif // !defined(AFX_SQUARE_H__547E8382_F175_11D1_90A2_D0DD2F7ACA49__INCLUDED_)
