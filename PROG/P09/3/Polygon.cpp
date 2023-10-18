#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon(vector<Point> vertices){
    vertices_=vertices;
}

Polygon::Polygon(){
    vector<Point> vertices;
    vertices_ = vertices;
}

bool Polygon::get_vertex(int position, Point& p){
    int size= vertices_.size();
    if (position>size || position<1){
        return false;
    }else{
        p = vertices_[position-1];
        return true;
    }
}

void Polygon::add_vertex(int pos, Point& p){
    vertices_.insert(vertices_.begin()+pos-1, p);
}

float Polygon::perimeter() const{
    float perimeter = 0;
    for(size_t i = 0; i<vertices_.size()-1; i++){
        Point p = vertices_[i];
        perimeter += p.get_distance(vertices_[i+1]);
    }
    Point last = vertices_[vertices_.size()-1]; 
    perimeter += last.get_distance(vertices_[0]);
    return perimeter;
}

void Polygon::show(){
    cout << "{";
    for (size_t i= 0; i< vertices_.size(); i++){
        vertices_[i].show();
    }
    cout << "}";
}