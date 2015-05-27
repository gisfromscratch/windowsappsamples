// LowerAndTrim.c

#include <stdio.h>
#include "lat_inc.h"

int main (void) 
{
   char str[100];

   printf ("\nBitte einen String eingeben: ");
   gets (str);

   LowerAndTrim (str);

   printf ("\nUnd hier ist das Ergebnis: %s", str);
    
   return 0;
} 