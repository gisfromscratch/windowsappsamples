// WinControlView.cpp : Implementierung der Klasse CWinControlView
//

#include "stdafx.h"
#include "WinControl.h"

#include "WinControlDoc.h"
#include "WinControlView.h"

#include "ControlDlg1.h"
#include "ControlDlg2.h"
#include "ControlDlg3.h"

#include "PropertyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinControlView

IMPLEMENT_DYNCREATE(CWinControlView, CView)

BEGIN_MESSAGE_MAP(CWinControlView, CView)
	ON_COMMAND(ID_CONTROLS_PART1, OnControlsPart1)
	ON_COMMAND(ID_CONTROLS_PART2, OnControlsPart2)
	ON_COMMAND(ID_CONTROLS_PART3, OnControlsPart3)
	ON_COMMAND(ID_CONTROLS_PROPERTY, OnControlsProperty)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinControlView Konstruktion/Destruktion

CWinControlView::CWinControlView()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen,

}

CWinControlView::~CWinControlView()
{
}

BOOL CWinControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// ZU ERLEDIGEN: Ändern Sie hier die Fensterklasse oder das Erscheinungsbild, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWinControlView Zeichnen

void CWinControlView::OnDraw(CDC* pDC)
{
	CWinControlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// ZU ERLEDIGEN: Hier Code zum Zeichnen der ursprünglichen Daten hinzufügen
}

/////////////////////////////////////////////////////////////////////////////
// CWinControlView Diagnose

#ifdef _DEBUG
void CWinControlView::AssertValid() const
{
	CView::AssertValid();
}

void CWinControlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinControlDoc* CWinControlView::GetDocument() // Die endgültige (nicht zur Fehlersuche kompilierte) Version ist Inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinControlDoc)));
	return (CWinControlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinControlView Nachrichten-Handler

void CWinControlView::OnControlsPart1() 
{
   CControlDlg1 dlg;
   
   // DDX-Variablen zuweisen
   dlg.m_strEdit   = "Gute Reise";  // Eingabefeld
   dlg.m_bCheck    = TRUE;          // Kontrollkästchen
   dlg.m_nRadio    = 1;             // Optionsfeld
   dlg.m_strCombo  = "Deutschland"; // Kombinationsfeld
   dlg.m_strStatic = "¡Vamos a la playa!"; // statischer Text
   
   dlg.DoModal ();  
   
   // Jetzt können alle Austauschvariablen gelesen werden.
   // ... = dlg.m_strEdit;
   // ... = dlg.m_bCheck;
   // ... = dlg.m_nRadio;
   // ... = dlg.m_strList;
   // ... = dlg.m_nScroll;
   // ... = dlg.m_nCombo;
}

void CWinControlView::OnControlsPart2() 
{
	CControlDlg2 dlg;

   dlg.m_nProgress = 30;  // Statusanzeige
   dlg.m_nSlider = 50;    // Regler

   dlg.DoModal ();

   // Jetzt können alle Austauschvariablen gelesen werden.
   // ... = dlg.m_nSlider;
   // ... = dlg.m_strList;
   // ... = dlg.m_strTree;
   // ... = dlg.m_strRichEdit;
}


void CWinControlView::OnControlsPart3() 
{
	CControlDlg3 dlg;

   // Kalendersteuerelement und Datumsauswahl
   // auf 11.11.1999 11 Uhr 11 und 11 Sekunden
   // setzen.
   dlg.m_DateTimePicker = CTime (1999,11,11,11,11,11);
   dlg.m_MonthCal = CTime (1999,11,11,11,11,11);

   // IP Steuerelement auf 192.168.0.1 setzen.
   dlg.m_nIPf1 = 192;
   dlg.m_nIPf2 = 168;
   dlg.m_nIPf3 = 0;
   dlg.m_nIPf4 = 1;

   dlg.DoModal ();

   // Jetzt können die Austauschvariablen gelesen werden.
   // ... = dlg.m_DateTimePicker;
   // ... = dlg.m_MonthCal;
   // ... = dlg.m_nComboEx;
   // ... = dlg.m_nIPf1;
   // ... = dlg.m_nIPf2;
   // ... = dlg.m_nIPf3;
   // ... = dlg.m_nIPf4;
}

void CWinControlView::OnControlsProperty() 
{
   CPropertyDialog dlg("Eigenschaftsdialog");
   
   dlg.DoModal ();	
}
