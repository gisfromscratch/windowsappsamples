#ifndef AFX_KNOB_H__4865B343_2DF9_11D2_B5B2_006097A8F69A__INCLUDED_
#define AFX_KNOB_H__4865B343_2DF9_11D2_B5B2_006097A8F69A__INCLUDED_

// Mit Microsoft Visual C++ automatisch erstellte IDispatch-Kapselungsklasse(n). 

// HINWEIS: Die Inhalte dieser Datei nicht ändern. Wenn Microsoft Visual C++
// diese Klasse erneuert, werden Ihre Änderungen überschrieben.

/////////////////////////////////////////////////////////////////////////////
// Wrapper-Klasse CKnob 

class CKnob : public CWnd
{
protected:
	DECLARE_DYNCREATE(CKnob)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x21d56977, 0x2604, 0x11d2, { 0xb5, 0x9c, 0x0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attribute
public:
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	long GetValue();
	void SetValue(long);
	long GetMaxValue();
	void SetMaxValue(long);

// Operationen
public:
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // AFX_KNOB_H__4865B343_2DF9_11D2_B5B2_006097A8F69A__INCLUDED_
