#include <iostream.h>

class CBottle
{
public:
   void Open ()
   {
      cout << "\nopen";
   }

   void Close ()
   {
      cout << "\nclose";
   }

   void PourIntoGlass ()
   { 
      cout << "\npour";
   }   
};


class CBottleAccess
{
   CBottle *m_pBottle;

public:
   CBottleAccess (CBottle *pBottle) 
   {
      m_pBottle = pBottle;
      m_pBottle->Open ();
   }

   ~CBottleAccess ()
   {
      m_pBottle->Close ();
   }
   
   CBottle* operator->()
   { 
      cout << "\nlog: Zugriff auf den Zeiger";
      return m_pBottle;
   }
};


int main () 
{
   CBottle bottle;
   CBottleAccess bottleAccess (&bottle);

   bottleAccess->PourIntoGlass ();
   //Drink ();
   return 0;
}