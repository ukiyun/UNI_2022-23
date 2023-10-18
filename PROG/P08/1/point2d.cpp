#include <iostream>
#include "Point2d.h"
#include <math.h>

double Point2d::distance_to(const Point2d& p) const{
    float x_dist = get_x() - p.get_x();
    float y_dist = get_y() - p.get_y();
    return sqrt(x_dist*x_dist + y_dist*y_dist);
}

void Point2d::translate(const Point2d& t){
    set_x(get_x() + t.get_x());
    set_y(get_y() + t.get_y());
}