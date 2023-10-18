#ifndef POINT_H
#define POINT_H

class Point{
    public:
        Point(int x, int y);
        Point();
        int get_x() const;
        int get_y() const;
        void show();
        float get_distance(const Point& p);
    
    private:
        int x_;
        int y_;

};

#endif