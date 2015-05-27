#pragma once

// StockProperty.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CStockProperty 

class CStockProperty : public CDialog
{
// Konstruktion
public:
	CStockProperty(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	enum { IDD = IDD_STOCKPROPERTY };
	CString	m_name;
	int		m_nID;
	CString	m_ticker;


// �berschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung

// Implementierung
protected:

	DECLARE_MESSAGE_MAP()
};

