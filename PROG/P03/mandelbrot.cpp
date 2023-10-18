#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r){
    r.x = (a.x*b.x) - (a.y*b.y);
    r.y = (a.x*b.y) + (a.y*b.x);
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    if (n==0){
        z_n.x=0;
        z_n.y=0;
    }else{
        z_n.x=0;
        z_n.y=0;
        for(unsigned int i=1; i<=n;i++){
            complex a;
            mul(z_n,z_n,a);
            complex b;
            add(a,c,b);
            z_n = b;
        }
    }
}

