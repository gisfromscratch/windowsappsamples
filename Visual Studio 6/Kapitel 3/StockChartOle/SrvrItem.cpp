// SrvrItem.cpp : Implementierung der Klasse CStockChartOleSrvrItem
//

#include "stdafx.h"
#include "StockChartOle.h"

#include "StockChartOleDoc.h"
#include "SrvrItem.h"

#include "DrawFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleSrvrItem Implementierung

IMPLEMENT_DYNAMIC(CStockChartOleSrvrItem, COleServerItem)

CStockChartOleSrvrItem::CStockChartOleSrvrItem(CStockChartOleDoc* pContainerDoc)
	: COleServerItem(pContainerDoc, TRUE)
{
	// ZU ERLEDIGEN: Hier Code für One-Time-Konstruktion einfügen
	//  (z.B. Hinzufügen von zusätzlichen Zwischenablageformaten zur Datenquelle des Elements)
}

CStockChartOleSrvrItem::~CStockChartOleSrvrItem()
{
	// ZU ERLEDIGEN: Hier Bereinigungscode hinzufügen
}

void CStockChartOleSrvrItem::Serialize(CArchive& ar)
{
	// CStockChartOleSrvrItem::Serialize wird automatisch aufgerufen, wenn
	//  das Element in die Zwischenablage kopiert wird. Dies kann automatisch 
	//  über die OLE-Rückruffunktion OnGetClipboardData geschehen. Ein Standardwert für
	//  das eingebundene Element dient einfach zur Delegierung der Serialisierungsfunktion des 
	//  Dokuments. Wenn Sie Verweise unterstützen, möchten Sie vielleicht nur einen Teil des
	//  Dokuments serialisieren.

	if (!IsLinkedItem())
	{
		CStockChartOleDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->Serialize(ar);
	}
}

BOOL CStockChartOleSrvrItem::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// Die meisten Anwendungen (wie auch diese) unterstützen als einzigen Aspekt das Zeichnen
	//  des Elementinhalts. Wollen Sie andere Aspekte unterstützen, wie z.B.
	//  DVASPECT_THUMBNAIL (durch Überladen von OnDrawEx), so sollte diese
	//  Implementierung von OnGetExtent dahingehend modifiziert werden, dass sie
	//  zusätzliche Aspekte verarbeiten kann.

	if (dwDrawAspect != DVASPECT_CONTENT)
		return COleServerItem::OnGetExtent(dwDrawAspect, rSize);

	// CStockChartOleSrvrItem::OnGetExtent wird aufgerufen, um das Extent in 
	//  HIMETRIC-Einheiten des gesamten Elements zu ermitteln. Die Standardimplementierung
	//  liefert hier einfach eine fest programmierte Einheitenanzahl zurück.

	rSize = CSize(5000,5000);   // 5000 x 5000 HIMETRIC Einheiten

	return TRUE;
}


BOOL CStockChartOleSrvrItem::OnDraw(CDC* pDC, CSize& rSize)
{
   // Entfernen Sie dies, wenn Sie rSize verwenden
	UNREFERENCED_PARAMETER(rSize);

	CStockChartOleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// ZU ERLEDIGEN: Setzen Sie Mapping-Modus und Extent
	//  (Das Extent stimmt üblicherweise mit der von OnGetExtent zurückgelieferten Größe überein)
	pDC->SetMapMode(MM_ANISOTROPIC); 

	pDC->SetWindowOrg (0,0);
   pDC->SetWindowExt (5000,5000);

   ::Draw (pDC, pDoc, 5000);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CStockChartOleSrvrItem Diagnose

#ifdef _DEBUG
void CStockChartOleSrvrItem::AssertValid() const
{
	COleServerItem::AssertValid();
}

void CStockChartOleSrvrItem::Dump(CDumpContext& dc) const
{
	COleServerItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////

