#ifndef __drawfunc__
#define __drawfunc__

class CDC;
class CStockChartXDoc;

void Draw(CDC* pDC, CStockChartXDoc* pDoc, long nSize=10000);

#endif