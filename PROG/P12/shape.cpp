#include <cmath>
#include <iostream>
#include <iomanip>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
    private:
        double radius_;
    public:
        Circle(const point& centro , double raio) : Shape(centro),radius_(raio){}
        double area() const{
            return M_PI * radius_*radius_;
        }
        double perimeter() const{return M_PI * 2 * radius_;}
        bool contains (const point& p) const {
            point centro = get_center();
            return sqrt(pow((p.x-centro.x),2) + pow((p.y-centro.y),2)) <= radius_;
        }
};
class Rectangle : public Shape {
    private:
        double width_;
        double height_;
    public:
        Rectangle(const point& centro , double largura , double altura) : Shape(centro) , width_(largura) , height_(altura){}
        double area() const{
            return width_*height_;
        }
        double perimeter() const  {return 2 * width_ + 2* height_;}
        bool contains  (const point& p) const {
            point centro = get_center();
            if (p.x < centro.x-width_/2) return false;
            if ( p.x > centro.x + width_/2) return false;
            if ( p.y < centro.y-height_/2) return false;
            if (p.y > centro.y + height_/2) return false;
            return true;
        }
};