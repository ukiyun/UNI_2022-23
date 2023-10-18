//solve equation

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    int discriminant;
    int r;
    discriminant = pow(b,2) - (4*a*c);
    if (discriminant < 0){
        r = 0;
        x1 = NAN;
        x2 = NAN;
    }else if (discriminant == 0){
        r = 1;
        x1 = double (-b)/(2*a);
        x2 = NAN;
    }else{
        r = 2;
        x1 = double (-b-sqrt(discriminant))/(2*a);
        x2 = double (-b+sqrt(discriminant))/(2*a);
    }

    return r;
}