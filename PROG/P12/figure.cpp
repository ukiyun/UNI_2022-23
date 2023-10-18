#include <iostream>
#include <vector>
#include "Figure.h"
 
using namespace std;

class Circle : public Figure {
    private:
        double radius_;
    public:
        Circle(double x_center, double y_center, double raio) : Figure(x_center,y_center),radius_(raio){}
        void draw() const {
            cout << "C(" << x_center_ << ',' << y_center_ << ")(" << radius_ << ')'; 
        }
        ~Circle () {}
};
class Rectangle : public Figure {
    private:
        double width_;
        double height_;
    public:
        Rectangle(double x_center, double y_center, double largura , double altura) : Figure(x_center,y_center), width_(largura) , height_(altura){}
        void draw() const{
            cout << "R(" << x_center_ << ',' << y_center_ << ")(" << width_ << ','<<height_<< ')'; 
        }
        ~Rectangle () {}
};