#include <iostream>
#include <cmath>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]){
   int size=0;
   unsigned long integer;
   while(hstr[size] != '\0'){
      size++;
   }
   int i =0;
   while(hstr[i]!= '\0'){
      size--;
      unsigned long temp;
      if(hstr[i]>= '0' && hstr[i]<='9'){
         int t = hstr[i]-48;
         temp = t * pow(16,size);
      }else{
         const char t = toupper(hstr[i]);
         switch (t)
         {
         case 'A':
            temp = 10 * pow(16,size);
            break;
         case 'B':
            temp = 11 * pow(16,size);
            break;
         case 'C':
            temp = 12 * pow(16,size);
            break;
         case 'D':
            temp = 13 * pow(16,size);
            break;
         case 'E':
            temp = 14 * pow(16,size);
            break;
         case 'F':
            temp = 15 * pow(16,size);
            break;
         }
      }
      integer= integer + temp;
      i++;
   }

   return integer;

}