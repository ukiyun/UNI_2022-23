#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>
using namespace std;

class Polygon{
    public:
        Polygon(vector<Point> vertices);
        Polygon();
        bool get_vertex(int position, Point& p);
        void add_vertex(int pos, Point& p);
        float perimeter() const;
        void show();

    private:
        vector<Point> vertices_;
};




#endif