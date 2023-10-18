#include <iostream>
#include "interval.h"

using namespace std;

bool is_in_interval(time_of_day t, const interval a){
    bool isn = false;
    if(t.h == a.start.h){
        if(t.m >= a.start.m){
            isn = true;
        }
    }
    if(t.h>a.start.h && t.h <a.end.h){
        isn = true;
    }
    if(t.h == a.end.h){
        if(t.m < a.end.m){
            isn = true;
        }
    }


    return isn;
}

bool is_a_before_b(time_of_day a, time_of_day b){
    bool isn = false;
    if(a.h<b.h){
        isn = true;
    }
    if(a.h==b.h){
        if(a.m<b.m){
            isn=true;
        }
    }
    return isn;
}

bool is_a_after_b(time_of_day a, time_of_day b){
    bool isn = false;
    if(a.h>b.h){
        isn = true;
    }
    if(a.h==b.h){
        if(a.m>b.m){
            isn=true;
        }
    }
    return isn;
}

int minutes_betweeen_interval(time_of_day a, time_of_day b){
    int minutes_to_next_hour = 60-a.m;
    a.h = a.h + 1;
    int minutes_b = b.m + minutes_to_next_hour;
    int hours = b.h-a.h;
    int hourstomin = hours*60;
    return minutes_b+hourstomin;
}


int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    u.start = {24,0};
    u.end = {0,0};
    bool flag = true;
    for(int i = 0; i<n; i++){
        if(is_in_interval(t,a[i])){
            flag = false;
            if(is_a_after_b(a[i].end,u.end)){
                u.end = a[i].end;
            }
            if(is_a_before_b(a[i].start, u.start)){
                u.start = a[i].start;
            }
        }
    }
    int minutes;
    if(flag){
        u.start = t;
        u.end = t;
        minutes = 0;
    }else{
        minutes = minutes_betweeen_interval(u.start,u.end);
    }
    return minutes;  
}