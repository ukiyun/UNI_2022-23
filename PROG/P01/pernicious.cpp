#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_prime(int n){
    bool is_prime = true;
    if(n<=1){
        is_prime = false;
    }

    for (int i= 2; i<=n/2; i++){
        if (n%i==0){
            is_prime = false;
            break;
        }
    }

    return is_prime;
}

bool check_perenious(int n){
    bool is_perenious = false;
    int ones = __builtin_popcount(n);
    if(check_prime(ones)){
        is_perenious = true;
    }
    return is_perenious;
}


int main(){
    int a;
    int b;
    cin >> a;
    cin >> b;
    for (int i = a; i <=b; i++){
        if(check_prime(i)== true && check_perenious(i)==true){
            cout << i << " ";
        }
    }
    return 0;
}