// IpFrame.cpp : Implementierung der Klasse CInPlaceFrame
//

#include "stdafx.h"
#include "StockChartX.h"

#include "IpFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame

IMPLEMENT_DYNCREATE(CInPlaceFrame, COleDocIPFrameWnd)

BEGIN_MESSAGE_MAP(CInPlaceFrame, COleDocIPFrameWnd)
	//{{AFX_MSG_MAP(CInPlaceFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame Konstruktion/Destruktion

CInPlaceFrame::CInPlaceFrame()
{
}

CInPlaceFrame::~CInPlaceFrame()
{
}

int CInPlaceFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleDocIPFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// CResizeBar implementiert direkte Größenänderungen.
	if (!m_wndResizeBar.Create(this))
	{
		TRACE0("Failed to create resize bar\n");
		return -1;      // Fehler beim Erzeugen
	}

	// Allgemein ist es von Vorteil, ein Drop-Ziel zu registrieren, das
	//  keinerlei Auswirkung auf Ihr Rahmenfenster hat. Dies verhindert bei Drops ("Abwürfen")
	// ein "Durchfallen" zu einem Container, der Drag and Drop unterstützt.
	m_dropTarget.Register(this);

	return 0;
}

// OnCreateControlBars wird automatisch aufgerufen, um Steuerleisten im Fenster der
//  Container-Anwendung zu erstellen. pWndFrame ist das hierarchisch höchste Rahmenfenster des
//  Containers und ist immer ungleich NULL. pWndDoc ist das Rahmenfenster auf Dokumentebene
//  und ist gleich NULL, wenn der Container eine SDI-Anwendung ist. Eine Server
//  Anwendung kann MFC-Steuerelementleisten in jedes Fenster platzieren.
BOOL CInPlaceFrame::OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc)
{
	// Entfernen Sie dies, wenn Sie pWndDoc verwenden
	UNREFERENCED_PARAMETER(pWndDoc);

	// Dieses Fenster als Owner festlegen, damit Nachrichten an die richtige Anwendung gesendet werden
	m_wndToolBar.SetOwner(this);

	// Symbolleiste im Client-Fenster erzeugen
	if (!m_wndToolBar.Create(pWndFrame) ||
		!m_wndToolBar.LoadToolBar(IDR_STOCKCTYPE_SRVR_IP))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;
	}

	// ZU ERLEDIGEN: Entfernen, wenn Sie keine QuickInfos oder variable Symbolleiste wünschen
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// ZU ERLEDIGEN: Löschen Sie diese drei Zeilen, wenn Sie nicht wollen, dass die Symbolleiste
	//  andockbar ist.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
	pWndFrame->DockControlBar(&m_wndToolBar);

	return TRUE;
}

BOOL CInPlaceFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return COleDocIPFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame Diagnose

#ifdef _DEBUG
void CInPlaceFrame::AssertValid() const
{
	COleDocIPFrameWnd::AssertValid();
}

void CInPlaceFrame::Dump(CDumpContext& dc) const
{
	COleDocIPFrameWnd::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CInPlaceFrame-Befehle
