#include <iostream>
#include "Color.h"
#include "Color.cpp"



int main(){
    Color c (1, 2, 3);
    const Color& r = c;
    cout << (int) r.red() << ' '  
        << (int) r.green() << ' '  
        << (int) r.blue() << ' '
        << boolalpha << r.equal_to(r) << '\n';

    return 0;
}