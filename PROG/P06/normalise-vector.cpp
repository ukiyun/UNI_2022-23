#include <iostream>
#include <vector>
#include "print_vector.h"
using namespace std;

template <typename T>
T minim(T a, T b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

template <typename T>
T maxim(T a, T b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}


template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    int size = v.size();
    for(int i = 0; i<size; i++){
        if(minim(v[i],min)==v[i]){
            v[i] = min;
        }
        if(maxim(v[i],max)==v[i]){
            v[i] = max;
        }
    }
}
