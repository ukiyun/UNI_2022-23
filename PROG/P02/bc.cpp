#include <iostream>

using namespace std;

unsigned long factorial(unsigned long n){
    unsigned long fac = n;
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    }else{
        while (n!=1){
            fac = fac * (n-1);
            n = n-1;
        }
    }
    return fac;
}

unsigned long bc(unsigned long n, unsigned long k){
    unsigned long nfact = factorial(n);
    unsigned long kfact = factorial(k);
    unsigned long nkfact = factorial(n-k);
    return (nfact/(kfact*nkfact));
}