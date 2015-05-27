// MFCAutoClient2Dlg.h : Header-Datei
//

#if !defined(AFX_MFCAUTOCLIENT2DLG_H__50CB2285_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
#define AFX_MFCAUTOCLIENT2DLG_H__50CB2285_0C37_11D2_B53C_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Typbibliothek importieren
#import "StockChartAuto.tlb" rename_namespace ("Server")

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient2Dlg Dialogfeld

class CMFCAutoClient2Dlg : public CDialog
{
// Konstruktion
public:
	CMFCAutoClient2Dlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CMFCAutoClient2Dlg)
	enum { IDD = IDD_MFCAUTOCLIENT2_DIALOG };
		// HINWEIS: der Klassenassistent fügt an dieser Stelle Datenelemente (Members) ein
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCAutoClient2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CMFCAutoClient2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
   afx_msg void OnDropFiles( HDROP hDropInfo );

	DECLARE_MESSAGE_MAP()


   // hier wird der Smart-Pointer deklariert
   Server::IStockChartAutoPtr m_itfStockChart;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_MFCAUTOCLIENT2DLG_H__50CB2285_0C37_11D2_B53C_006097A8F69A__INCLUDED_)
