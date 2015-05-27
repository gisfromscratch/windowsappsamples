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


// Überschreibungen
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:

	DECLARE_MESSAGE_MAP()
};

