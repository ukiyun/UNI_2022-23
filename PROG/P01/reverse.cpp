#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int rev=0;
    while (n!=0){
        int digit;
        digit = n%10;
        rev = (rev + digit)*10;
        n= n/10;
    }
    rev = rev/10;
    cout << rev;
    return 0;
}