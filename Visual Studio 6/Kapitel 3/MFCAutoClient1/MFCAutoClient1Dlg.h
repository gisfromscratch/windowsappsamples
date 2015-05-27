// MFCAutoClient1Dlg.h : Header-Datei
//

#if !defined(AFX_MFCAUTOCLIENT1DLG_H__4896966A_0A05_11D2_B530_006097A8F69A__INCLUDED_)
#define AFX_MFCAUTOCLIENT1DLG_H__4896966A_0A05_11D2_B530_006097A8F69A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "StockChartAuto.h"

class CMFCAutoClient1DlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CMFCAutoClient1Dlg Dialogfeld

class CMFCAutoClient1Dlg : public CDialog
{
	DECLARE_DYNAMIC(CMFCAutoClient1Dlg);
	friend class CMFCAutoClient1DlgAutoProxy;

// Konstruktion
public:
	CMFCAutoClient1Dlg(CWnd* pParent = NULL);	// Standard-Konstruktor
	virtual ~CMFCAutoClient1Dlg();

// Dialogfelddaten
	//{{AFX_DATA(CMFCAutoClient1Dlg)
	enum { IDD = IDD_MFCAUTOCLIENT1_DIALOG };
		// HINWEIS: der Klassenassistent fügt an dieser Stelle Datenelemente (Members) ein
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CMFCAutoClient1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	CMFCAutoClient1DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CMFCAutoClient1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
   afx_msg void OnDropFiles( HDROP hDropInfo );
	
   DECLARE_MESSAGE_MAP()

private:
   IStockChartAuto itfStockChart;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_MFCAUTOCLIENT1DLG_H__4896966A_0A05_11D2_B530_006097A8F69A__INCLUDED_)
