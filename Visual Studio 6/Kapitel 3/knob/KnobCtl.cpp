// KnobCtl.cpp: Implementierung der CKnobCtrl-ActiveX-Steuerelementklasse.

#include "stdafx.h"
#include "knob.h"
#include "KnobCtl.h"
#include "KnobPpg.h"

#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CKnobCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Nachrichtenzuordnungstabelle

BEGIN_MESSAGE_MAP(CKnobCtrl, COleControl)
	//{{AFX_MSG_MAP(CKnobCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch-Tabelle

BEGIN_DISPATCH_MAP(CKnobCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CKnobCtrl)
	DISP_PROPERTY_EX(CKnobCtrl, "MaxValue", GetMaxValue, SetMaxValue, VT_I4)
	DISP_PROPERTY_EX(CKnobCtrl, "Value", GetValue, SetValue, VT_I4)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CKnobCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Ereignistabelle

BEGIN_EVENT_MAP(CKnobCtrl, COleControl)
	//{{AFX_EVENT_MAP(CKnobCtrl)
	EVENT_CUSTOM("OnValueChanged", FireOnValueChanged, VTS_I4)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Eigenschaftenseiten

// ZU ERLEDIGEN: Fügen Sie mehr Eigenschaftenseiten ein, als erforderlich sind.  Denken Sie daran, den Zähler zu erhöhen!
BEGIN_PROPPAGEIDS(CKnobCtrl, 2)
	PROPPAGEID(CKnobPropPage::guid)
   PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CKnobCtrl)


/////////////////////////////////////////////////////////////////////////////
// Klassenerzeugung und GUID initialisieren

IMPLEMENT_OLECREATE_EX(CKnobCtrl, "KNOB.KnobCtrl.1",
	0x21d56977, 0x2604, 0x11d2, 0xb5, 0x9c, 0, 0x60, 0x97, 0xa8, 0xf6, 0x9a)


/////////////////////////////////////////////////////////////////////////////
// Typbibliothek-ID und Version

IMPLEMENT_OLETYPELIB(CKnobCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Schnittstellen-IDs

const IID BASED_CODE IID_DKnob =
		{ 0x21d56975, 0x2604, 0x11d2, { 0xb5, 0x9c, 0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };
const IID BASED_CODE IID_DKnobEvents =
		{ 0x21d56976, 0x2604, 0x11d2, { 0xb5, 0x9c, 0, 0x60, 0x97, 0xa8, 0xf6, 0x9a } };


/////////////////////////////////////////////////////////////////////////////
// Steuerelement-Typinformation

static const DWORD BASED_CODE _dwKnobOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CKnobCtrl, IDS_KNOB, _dwKnobOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::CKnobCtrlFactory::UpdateRegistry -
// Fügt Einträge der Systemregistrierung für CKnobCtrl hinzu oder entfernt diese

BOOL CKnobCtrl::CKnobCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// ZU ERLEDIGEN: Prüfen Sie, ob Ihr Steuerelement den Thread-Regeln nach dem "Apartment"-Modell entspricht.
	// Weitere Informationen finden Sie unter MFC TechNote 64.
	// Falls Ihr Steuerelement nicht den Regeln nach dem Apartment-Modell entspricht, so
	// müssen Sie den nachfolgenden Code ändern, indem Sie den 6. Parameter von
	// afxRegApartmentThreading auf 0 ändern.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_KNOB,
			IDB_KNOB,
			afxRegApartmentThreading,
			_dwKnobOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
static const double pi = 3.1415;
static const int nKnobSize = 50;


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::CKnobCtrl - Konstruktor

CKnobCtrl::CKnobCtrl()
   : m_bCapture(false)
{
	InitializeIIDs(&IID_DKnob, &IID_DKnobEvents);

   CDC memDC;

   memDC.CreateCompatibleDC (NULL);
   m_bitmap.CreateBitmap (nKnobSize,
                          nKnobSize,
                          1, memDC.GetDeviceCaps (BITSPIXEL), NULL);
   
   m_tgtArea.SetRect (0,0,nKnobSize,nKnobSize);
   m_size = CSize (nKnobSize, nKnobSize);                   
}


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::~CKnobCtrl - Destruktor

CKnobCtrl::~CKnobCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::OnDraw - Zeichenfunktion

void CKnobCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
   COLORREF backColor = TranslateColor (GetBackColor ());
   COLORREF foreColor = TranslateColor (GetForeColor ());
   CBrush backBrush (backColor);

   // Für später speichern:
   m_foreColor = foreColor;
   m_backColor = backColor;

   m_pos = CPoint (rcBounds.left + (rcBounds.right-rcBounds.left)/2,
                   rcBounds.top  + (rcBounds.bottom-rcBounds.top)/2);
   m_srcArea.SetRect (m_pos.x - m_size.cx/2,
                      m_pos.y - m_size.cy/2,
                      m_pos.x + m_size.cx/2,
                      m_pos.y + m_size.cy/2);


	pdc->FillRect(rcBounds, &backBrush);

   Draw (pdc);
}


void CKnobCtrl::Draw (CDC *pDC)
{
   CDC memDC;
   CBitmap *pOldBitmap;
   CPen pen (PS_SOLID,1,RGB(0,0,0)), *pOldPen;
   CBrush brush (m_foreColor), backBrush (m_backColor), *pOldBrush;

   // Speicher DC erzeugen:
   memDC.CreateCompatibleDC (pDC);

   // Bitmap hineinselektieren:
   pOldBitmap = memDC.SelectObject (&m_bitmap);

   // Hintergrund zeichnen:
   memDC.FillRect (m_tgtArea, &backBrush);

   // Knopf zeichnen:
   pOldPen   = memDC.SelectObject (&pen);
   pOldBrush = memDC.SelectObject (&brush);

   memDC.Ellipse (CRect (m_tgtArea.left+10,
                         m_tgtArea.top+10,
                         m_tgtArea.right-10,
                         m_tgtArea.bottom-10));

   memDC.SelectObject (pOldBrush);

   // Striche zeichnen:
   for (int i=0; i<= 100; i+=10) {
      DrawMark (&memDC, i);
   }
   
   // Positionsmarke zeichnen:
   double val = m_nValue / (double)m_nMaxValue;
   double angle = (val / 2.0 + 0.25) * 3 * pi;

   int x = (int) ((m_size.cx/2.0-17.0) * cos (angle) + m_size.cx/2);
   int y = (int) ((m_size.cy/2.0-17.0) * sin (angle) + m_size.cy/2);

   memDC.Ellipse (CRect (x-3,y-3,x+3,y+3));

   // Auf den Schirm!
   pDC->BitBlt (m_srcArea.left,
                m_srcArea.top,
                m_srcArea.right,
                m_srcArea.bottom, &memDC, 0, 0, SRCCOPY);

   // Und restaurieren:
   memDC.SelectObject (pOldBitmap);
   memDC.SelectObject (pOldPen);
}



void CKnobCtrl::DrawMark(CDC * pDC, int percent)
{
   int x1, y1, x2, y2;
   double angle, val;
   
   val = percent / 100.0;
   angle = (val / 2.0 + 0.25) * 3 * pi;

   x1  = (int) ((m_size.cx/2.0-6.0) * cos (angle) + m_size.cx/2);
   x2  = (int) ((m_size.cx/2.0-1.0) * cos (angle) + m_size.cx/2);
   y1  = (int) ((m_size.cy/2.0-6.0) * sin (angle) + m_size.cy/2);
   y2  = (int) ((m_size.cy/2.0-1.0) * sin (angle) + m_size.cy/2);

   pDC->MoveTo (x1,y1); 
   pDC->LineTo (x2,y2);
}

/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::DoPropExchange - Unterstützung dauerhafter Eigenschaften

void CKnobCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

   PX_Long (pPX, _T("Value"), m_nValue, 0);
   PX_Long (pPX, _T("MaxValue"), m_nMaxValue, 100);
}


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::OnResetState - Setzt das Steuerelement in den Standardzustand zurück

void CKnobCtrl::OnResetState()
{
	COleControl::OnResetState();  // Setzt die Standards zurück, die in DoPropExchange gefunden wurden

	m_nValue = 0;
   m_nMaxValue = 100;
}


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl::AboutBox - Ein Dialogfeld "Info" für den Benutzer anzeigen

void CKnobCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_KNOB);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CKnobCtrl Behandlungsroutinen für Nachrichten 

void CKnobCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
   m_bCapture = true;
   // Maus 'einfangen':
   SetCapture ();
	
	COleControl::OnLButtonDown(nFlags, point);
}

void CKnobCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
   m_bCapture = false;
   // Maus freigeben:
   ::ReleaseCapture ();

   FireOnValueChanged (m_nValue);
	
	COleControl::OnLButtonUp(nFlags, point);
}

void CKnobCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
   if (m_bCapture) {
      CDC *pDC = GetDC ();

      m_nValue = ValueFromAngle (AngleFromPos (point - m_pos));
      Draw (pDC);

      ReleaseDC (pDC);
   }
	
	COleControl::OnMouseMove(nFlags, point);
}


int CKnobCtrl::ValueFromAngle (double angle)
{
   int value;

   if (angle <= pi/2.0)
      value = (int)(m_nMaxValue * 2.0 * (angle/(3.0*pi) + 5.0/12.0));
   else
      value = (int)(m_nMaxValue * 2.0 * (angle/(3.0*pi) - 0.25));
   
   if (value < 0)
      return 0;
   else if (value > m_nMaxValue)
      return m_nMaxValue;
   else
      return value;
}


double CKnobCtrl::AngleFromPos (const CPoint& pos)
{
   if (pos.y < 0)
      return atan2 (pos.y, pos.x) + 2 * pi;
   else
      return atan2 (pos.y, pos.x);
}


// Get- und Set-Methoden für Value und MaxValue
long CKnobCtrl::GetMaxValue() 
{
	return m_nMaxValue;
}


void CKnobCtrl::SetMaxValue(long nNewValue) 
{
   // Reglerwert anpassen
   m_nValue *= nNewValue / m_nMaxValue;
   
	m_nMaxValue = nNewValue;
   Invalidate ();

   // Reglerwert hat sich verändert!
   FireOnValueChanged (m_nValue);

	SetModifiedFlag();
}


long CKnobCtrl::GetValue() 
{
	return m_nValue;
}


void CKnobCtrl::SetValue(long nNewValue) 
{
   m_nValue = nNewValue;

   Invalidate ();

	SetModifiedFlag();
}
