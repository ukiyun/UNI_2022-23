#include "Point.h"
#include <iostream>
#include <math.h>
using namespace std;

Point::Point(int x, int y){
    x_=x;
    y_=y;
}

Point::Point(){
    x_=0;
    y_=0;
}

int Point::get_x() const{
    return x_;
}

int Point::get_y() const{
    return y_;
}

void Point::show(){
    cout << "("<< x_ <<","<< y_<< ")";
}

float Point::get_distance(const Point& p){
    float distance =0;
    float xs = pow(p.get_x() - x_,2);
    float ys = pow(p.get_y() - y_,2);
    distance = sqrt(xs+ys);
    return distance;
}