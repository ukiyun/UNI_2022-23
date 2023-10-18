#include <iostream>

using namespace std;

unsigned long mersenne(unsigned long n){
    unsigned long res = 1;
    for (unsigned long i= 0; i<n;i++){
        res = res*2;
    }
    return res-1;
}

unsigned long next_mersenne(unsigned long n){
    unsigned long res=0;
    unsigned long i=0;
    while(true){
        unsigned long temp = mersenne(i);
        if(temp<n){
            i++;
            continue;
        }else if(temp>=n){
            res = temp;
            break;
        }
    }

    return res;
}
