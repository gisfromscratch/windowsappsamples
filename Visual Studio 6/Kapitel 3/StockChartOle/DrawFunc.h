#ifndef __drawfunc__
#define __drawfunc__

class CDC;
class CStockChartOleDoc;

void Draw(CDC* pDC, CStockChartOleDoc* pDoc, long nSize=10000);

#endif