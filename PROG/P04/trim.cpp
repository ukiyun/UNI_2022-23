#include <iostream>

using namespace std;
int sizeofarray(char s[]){
    int len=0;
    while(s[len]!='\0'){
        len++;
    }
    return len;
}
void trim(char s[]){
   int len = sizeofarray(s); // size of array
   int numberofspace = 0;
   int f= 0;
   while(s[f]!='\0'){
       if(s[f]== ' '){
           numberofspace++;
       }
       f++;
   }
   if (len==0){
       s[0]='\0';
   }else if(len==numberofspace){
       s[0]='\0';
   }else{
       int end = 0;  // number of trailing zeros;
       int i = len;
       while (s[i-1]==' '){
           i--;
           end++;
       }
      s[len-end]='\0';
      int len2 = sizeofarray(s);
      int j = 0;
      while(s[j]!='\0'){
          if(s[j]==' '){
              for(int k=0; k<len2; k++){
                  s[k]=s[k+1];
              }
              len2--;
          }else{
              break;
          }
      }
   }
}