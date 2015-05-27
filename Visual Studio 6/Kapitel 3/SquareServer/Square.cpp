// Square.cpp : Implementierung von CSquareServerApp und DLL-Registrierung.

#include "stdafx.h"
#include "SquareServer.h"
#include "Square.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP Square::GetSquare (long value, long *pnResult)
{
	*pnResult = value * value;
	return S_OK;
}
