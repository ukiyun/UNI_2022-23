#include "Color.hpp"
namespace prog {
    Color::Color() {   //set the default color to black
        r_=0; 
        g_=0;
        b_=0;
    }
    Color::Color(const Color& other) { 
        r_ = other.r_; 
        g_ = other.g_;
        b_ = other.b_;
    }
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        r_ = red; 
        g_ = green;
        b_ = blue;
    }
    rgb_value Color::red() const {
        return r_; 
    }
    rgb_value Color::green() const {
        return g_; 
    }
    rgb_value Color::blue() const {
        return b_;
    }



    rgb_value& Color::red()  {
        return r_;
    }
    rgb_value& Color::green()  {
      return g_;
    }
    rgb_value& Color::blue()  {
      return b_;
    }

    const Color Color::RED(255,0,0);
    const Color Color::GREEN(0,255,0);
    const Color Color::BLUE(0,0,255);
    const Color Color::WHITE(255,255,255);
    const Color Color::BLACK(0,0,0);

    Color& Color::operator=(const Color& c) {
        r_ = c.r_;  //set the color to the color of the other color
        g_ = c.g_;
        b_ = c.b_;
        return *this;
    }

    Color& Color::operator+=(const Color& c) {
        r_ = std::min(255, r_ + c.r_);  //if the sum of the two colors is greater than 255, set the color to 255, otherwise set it to the sum
        g_ = std::min(255, g_ + c.g_);  
        b_ = std::min(255, b_ + c.b_);  
        return *this;  //return the color
    }

    bool Color::operator==(const Color& c) const {
        if(r_==c.r_){ //if the red, green, and blue values are the same, return true
            if(g_==c.g_){
                if(b_==c.b_){
                    return true;
                }
            }
        }
        return false; //otherwise return false
    }

    bool Color::operator!=(const Color& c) const {
        if(r_==c.r_){ //if the red, green, and blue values are the same, return false
            if(g_==c.g_){
                if(b_==c.b_){
                    return false;
                }
            }
        }
        return true; //otherwise return true
    }

    void Color::invert() {
        r_=255-r_; //invert the color by subtracting the color from 255
        g_=255-g_;
        b_=255-b_;
    }

    void Color::to_gray_scale() {
        rgb_value gray = (r_+g_+b_)/3; //set the color to the average of the red, green, and blue values
        r_=gray;
        g_=gray;
        b_=gray;
    }

    int Color::rgb_to_hex(){
        int hex = (r_ << 16) + (g_ << 8) + b_; //convert the rgb values to hex
        return hex;
    }

}
