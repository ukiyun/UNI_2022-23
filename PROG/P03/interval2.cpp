#include <iostream>
#include "interval.h"
using namespace std;

bool is_equal(interval a, interval b){
    bool value = false;
    if(a.end.h==b.start.h){
        if(a.end.m==b.start.m){
            value = true;
        }
    }
    
    return value;
}
bool is_a_bigger_b (time_of_day a, time_of_day b){
    bool value = false;
    if(a.h>b.h){
        value = true;
    }else if(a.h==b.h){
        if(a.m>b.m){
            value = true;
        }
    }
    return value;
}


interval intersection(interval a, interval b){
    interval final;
    if (is_a_bigger_b(b.start,a.end)==true || is_a_bigger_b(a.start,b.end) || is_equal(a,b)){
        final.start={0,0};
        final.end={0,0};
    }else{
        if(is_a_bigger_b(a.start,b.start)){
            final.start=a.start;
        }else{
            final.start=b.start;
        }

        if(is_a_bigger_b(a.end, b.end)){
            final.end = b.end;
        }else{
            final.end=a.end;
        }
        
    }
    return final;
}


int main(){
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 31 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 14, 30 }, { 15, 59 } },
                        { { 11, 30 }, { 14, 31 } } ) << '\n';
    cout << intersection( { {  4, 30 }, {  7, 59 } },
                        { {  4,  0 }, {  7, 29 } } ) << '\n';
    cout << intersection( { { 23,  0 }, { 23, 58 } },
                        { { 22, 45 }, { 23, 59 } } ) << '\n';

    return 0;
}
