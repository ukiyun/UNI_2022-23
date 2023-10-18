#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    int k;
    int d;
    cin >> k;
    cin >> d;
    double x=0;
    for (int i=0; i<=k; i++){
        double numerador = pow(-1,i);
        double denominador = 2*i + 1;
        double div = numerador/denominador;
        x+=div;
    }
    x = 4*x;
    cout << fixed << setprecision(d) << x ;
    return 0;
}