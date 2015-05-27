// cppserver.h

#pragma once

#include "unknwn.h"

interface ISquare : public IUnknown
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetSquare (long value, long *pnResult) = 0;
};

class CPPServer : public ISquare 
{
public:
	// IUnknown-Methoden
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void **ppvObj);
	ULONG STDMETHODCALLTYPE AddRef ();
	ULONG STDMETHODCALLTYPE Release ();

	// ISquare-Methoden
	HRESULT STDMETHODCALLTYPE GetSquare (long value, long *pnResult);

	CPPServer ();

private:
	DWORD m_dwRefCount;
};

class CPPServerFactory : public IClassFactory
{
public:
	CPPServerFactory ();

	// IUnknown-Methoden
	HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void **ppvObj);
	ULONG STDMETHODCALLTYPE AddRef ();
	ULONG STDMETHODCALLTYPE Release ();

	// IClassFactory 
	HRESULT STDMETHODCALLTYPE CreateInstance (IUnknown *pUnkOuter,
		                                       REFIID riid,
								                     void **ppvObj);
	HRESULT STDMETHODCALLTYPE LockServer (BOOL fLock);

private:
	DWORD m_dwRefCount;
};


