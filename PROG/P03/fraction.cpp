#include <iostream>
#include "fraction.h"
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

fraction add(fraction a, fraction b){
    fraction c;
    if(a.den==b.den){
        c.den=a.den;
        c.num = a.num + b.num;
    }else{
        c.den=a.den*b.den;
        c.num= (a.num*b.den)+(b.num*a.den);
    }
    int gc = gcd(c.num,c.den);
    c.num = c.num/gc;
    c.den = c.den/gc;
    if(c.den<0){
        c.den = -c.den;
        c.num = -c.num;
    }
    return c;
}

fraction mul(fraction a, fraction b){
    fraction c;
    c.num = a.num*b.num;
    c.den = a.den*b.den;
    int gc = gcd(c.num, c.den);
    c.num = c.num/gc;
    c.den = c.den/gc;
        if(c.den<0){
        c.den = -c.den;
        c.num = -c.num;
    }
    return c;
}





