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

fraction summing(fraction a, fraction b){
    fraction result;
    if(b.den==a.den){
        result.den=a.den;
        result.num=a.num+b.num;
    }else{
        result.den = a.den * b.den;
        result.num = (a.num*b.den)+(b.num*a.den);
    }

    return result;
}


fraction sum(const fraction fa[], int n){
    if(n==0){
        return {0,0};
    }
    fraction result = fa[0];
    for(int i=1; i<n; i++){
        result = summing(result, fa[i]);
    }
    int greatdiv = gcd(result.num, result.den);
    result.den = result.den / greatdiv;
    result.num = result.num / greatdiv;
    return result;
}