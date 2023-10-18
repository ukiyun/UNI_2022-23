#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int letters = 0;
    int numbers = 0;
    int special = 0;
    for (int i=1; i<=n; i++){
        char t;
        cin >> t;
        if (t >= '0' && t<='9'){
            numbers +=1;
        }else if((t>='a' && t<='z')||(t>='A' && t<='Z')){
            letters += 1;
        }else{
            special +=1;
        }
    }
    cout << letters << " " << numbers << " " << special;
    return 0;
}