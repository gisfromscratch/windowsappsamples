//
//
//  CKnob.h
//  Knopfklasse
//
//

#ifndef __cknob__
#define __cknob__

class CKnob
{
public:
   CKnob (const CSize& size);
   ~CKnob ();

   void OnDraw (CDC *pDC, const COLORREF foreColor, const COLORREF backColor);
   void OnMouseDown (CWnd *pWnd);
   void OnMouseUp ();
   void OnMouseMove (const CPoint& pos, CWnd *pWnd);

   void SetValue (const int nValue);
   int  GetValue ();
   void SetMinValue (const int nMinValue);
   void SetMaxValue (const int nMaxValue);
   void SetPos (const CPoint& pos);

private:

   int nValue, nMinValue, nMaxValue;
};

#endif