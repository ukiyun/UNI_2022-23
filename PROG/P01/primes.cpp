#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n<=1){
        return 0;
    }else{
        for (int i=2; i<=n; i++){
            int k=2;
            bool prime = true;
            while(k!=i){
                if (i%k==0){
                    prime = false;
                    break;
                }
                k++;
            }
            if(prime == true){
                cout << i << " ";
            }
        }

        return 0;
    }
}