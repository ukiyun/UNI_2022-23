#include <iostream>

using namespace std;


unsigned long pell(unsigned long n){
    unsigned long pell[n+1] = {0};
    if(n<2){
        return n;
    }
    pell[0]=0;
    pell[1]=1;
    for (unsigned long i=2; i<=n; i++){
        pell[i]=2*pell[i-1] + pell[i-2];
    }

    return pell[n];
}
