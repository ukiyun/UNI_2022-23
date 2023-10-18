#include <iostream>

using namespace std;

int adigits(int a, int b, int c){
    int bigger;
    int smaller;
    int middle;
    if (a>b && a > c){
        bigger = a;
        if(b<c){
            smaller = b;
            middle = c;
        }else{
            smaller = c;
            middle = b;
        }
    }
    if (b>a && b > c){
        bigger = b;
        if(a<c){
            smaller = a;
            middle = c;
        }else{
            smaller = c;
            middle = a;
        }
    }
    if (c>b && c > a){
        bigger = c;
        if(b<a){
            smaller = b;
            middle = a;
        }else{
            smaller = a;
            middle = b;
        }
    }
    if (a==b){
        if (b<c){
            bigger = c;
            middle = a;
            smaller = b;
        }else{
            bigger = b;
            middle = a;
            smaller = c;
        }
    }
    if (a==c){
        if (c<b){
            bigger = b;
            middle = a;
            smaller = c;
        }else{
            bigger = c;
            middle = a;
            smaller = b;
        }
    }
    if (c==b){
        if (b<a){
            bigger = a;
            middle = c;
            smaller = b;
        }else{
            bigger = b;
            middle = c;
            smaller = a;
        }
    }

    return ((bigger*10+middle)*10 + smaller);

}