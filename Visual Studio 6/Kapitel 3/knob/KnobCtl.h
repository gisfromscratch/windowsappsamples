#if !defined(AFX_KNOBCTL_H__21D56985_2604_11D2_B59C_006097A8F69A__INCLUDED_)
#define AFX_KNOBCTL_H__21D56985_2604_11D2_B59C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


// KnobCtl.h: Deklaration der CKnobCtrl-ActiveX-Steuerelementeklasse.

/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl: Siehe KnobCtl.cpp für Implementierung.

class CKnobCtrl : public COleControl
{
	DECLARE_DYNCREATE(CKnobCtrl)

// Konstruktor
public:
	CKnobCtrl();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CKnobCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementierung
protected:
	~CKnobCtrl();

	DECLARE_OLECREATE_EX(CKnobCtrl)    // Klassenerzeugung und GUID
	DECLARE_OLETYPELIB(CKnobCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CKnobCtrl)     // Eigenschaftenseiten-IDs
	DECLARE_OLECTLTYPE(CKnobCtrl)		// Typname und versch. Status

// Nachrichtenzuordnungstabellen
	//{{AFX_MSG(CKnobCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch-Tabellen
	//{{AFX_DISPATCH(CKnobCtrl)
	afx_msg long GetMaxValue();
	afx_msg void SetMaxValue(long nNewValue);
	afx_msg long GetValue();
	afx_msg void SetValue(long nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Ereignistabellen
	//{{AFX_EVENT(CKnobCtrl)
	void FireOnValueChanged(long nValue)
		{FireEvent(eventidOnValueChanged,EVENT_PARAM(VTS_I4), nValue);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch- und Ereignis-IDs
public:
	enum {
	//{{AFX_DISP_ID(CKnobCtrl)
	dispidMaxValue = 1L,
	dispidValue = 2L,
	eventidOnValueChanged = 1L,
	//}}AFX_DISP_ID
	};
private:
   int    ValueFromAngle (double angle);
   double AngleFromPos (const CPoint& point);
   void   Draw (CDC *pDC);
   void   DrawMark(CDC * pDC, int percent);

   CBitmap m_bitmap;
   CRect m_srcArea, m_tgtArea;
   CPoint m_pos;
   CSize m_size;
   COLORREF m_backColor, m_foreColor;
   bool m_bCapture;
   long m_nMaxValue;
   long m_nValue;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_KNOBCTL_H__21D56985_2604_11D2_B59C_006097A8F69A__INCLUDED)
