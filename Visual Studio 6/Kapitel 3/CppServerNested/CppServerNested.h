// CppServerNested.h

#pragma once


#include "unknwn.h"

interface ISquare : public IUnknown
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetSquare (long nValue, long *pnResult) = 0;
};

class CPPServerNested : public IUnknown
{
public:
	CPPServerNested ();

	// IUnknown-Methoden
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void **ppvObj);
	ULONG STDMETHODCALLTYPE AddRef ();
	ULONG STDMETHODCALLTYPE Release ();

	class SquareItf : public ISquare
	{
	public:
		// IUnknown-Methoden
		HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void **ppvObj);
		ULONG STDMETHODCALLTYPE AddRef ();
		ULONG STDMETHODCALLTYPE Release ();

		// ISquare-Methoden
		HRESULT STDMETHODCALLTYPE GetSquare (long nValue, long *pnResult);

      // Zeiger auf die einbettende Klasse	
		CPPServerNested *m_pParent;
	} m_SquareItf;  // Hier wird gleich ein Objekt der Klasse angelegt!

private:
	DWORD m_dwRefCount;
};

class CPPServerNestedFactory : public IClassFactory
{
public:
	CPPServerNestedFactory ();

	// IUnknown-Methoden
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void **ppvObj);
	ULONG STDMETHODCALLTYPE AddRef ();
	ULONG STDMETHODCALLTYPE Release ();

	// IClassFactory 
	STDMETHODIMP CreateInstance (IUnknown *pUnkOuter,
		                          REFIID riid,
								        void **ppvObj);
	STDMETHODIMP LockServer (BOOL fLock);


private:
	DWORD m_dwRefCount;
};


