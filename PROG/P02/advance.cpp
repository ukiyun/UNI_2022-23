#include <iostream>

using namespace std;

bool is_leapyear(int& y){
    if(y%400==0) return true;
    if(y%100==0) return false;
    return (y%4==0);
}


void advance(int delta, int& d, int& m, int& y){
    if(delta ==0){
        d = d;
        m = m;
        y = y;
    }else{
        int daysPerMonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for (int i=0; i<delta; i++){
            d++;
            if(d>daysPerMonth[m-1] || (m==2 && d == 29 && !is_leapyear(y))){
               d = 1;
               m++;
               if(m==13){
                    m = 1;
                    y++;
               } 
            }

        }
    }
}
