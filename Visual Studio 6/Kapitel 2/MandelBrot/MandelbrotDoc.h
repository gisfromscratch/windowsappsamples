// MandelbrotDoc.h : Schnittstelle der Klasse CMandelbrotDoc
//
/////////////////////////////////////////////////////////////////////////////


#pragma once

#include <afxmt.h>



class CMandelbrotDoc : public CDocument
{
protected: // Nur aus Serialisierung erzeugen
	CMandelbrotDoc();
	DECLARE_DYNCREATE(CMandelbrotDoc)

// Attribute
public:

// Operationen
public:

// Überladungen
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void OnCloseDocument();

// Implementierung
public:
   static UINT Calculate (LPVOID pParam);

	void StartCalculation (HWND hView);
	CBitmap * GetBitmap ();
	UINT Calculate (HWND hWnd);

	virtual ~CMandelbrotDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Message-Map-Funktionen
protected:
	DECLARE_MESSAGE_MAP()
private:
	CBitmap *m_pBitmap, *m_pBitmapCopy;
   CCriticalSection m_cs;
   CEvent m_killEvent;
   CWinThread *m_pThread;

   bool m_bWantExit;
};

/////////////////////////////////////////////////////////////////////////////
