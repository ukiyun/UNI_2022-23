#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int man =0;
    int x1;
    int y1;
    cin >> x1;
    cin >> y1;
    for (int i=1; i<n; i++){
        int x2;
        int y2;
        cin >> x2;
        cin >> y2;
        int xs = x1-x2;
        int ys = y1-y2;
        if (xs<0){
            xs = -xs;
        }
        if (ys<0){
            ys = -ys;
        }
        int manh = xs+ys;
        man = man + manh;
        x1 = x2;
        y1 = y2;
    }
    cout << man;
    return 0;
}