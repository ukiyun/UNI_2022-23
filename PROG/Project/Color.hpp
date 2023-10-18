#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__
#include <algorithm>
#include <vector>
namespace prog
{
  typedef unsigned char rgb_value;
  class Color
  {
    private:
      rgb_value r_; //red
      rgb_value g_; //green
      rgb_value b_; //blue
    public:
      Color(); //default constructor
      Color(const Color& c); //copy constructor
      Color(rgb_value r, rgb_value g, rgb_value b); //constructor
      rgb_value red() const; //accessor for red (non mutable)
      rgb_value& red(); //accessor for red
      rgb_value green() const; //accessor for green (non mutable)
      rgb_value& green(); //accessor for green
      rgb_value blue() const; //accessor for blue (non mutable)
      rgb_value& blue(); //accessor for blue

      //defining static const colors
      static const Color  RED; 
      static const Color  GREEN;
      static const Color  BLUE;
      static const Color  WHITE;
      static const Color  BLACK;

      // operator overloading
      Color& operator=(const Color& c); //assignment operator overloading of setting one color to another
      bool operator==(const Color& c) const;  //equality operator overloading
      bool operator!=(const Color& c) const; //inequality operator overloading
      Color& operator+=(const Color& other); //addition operator overloading

      //color functions
      void invert(); //invert the color of the image
      void to_gray_scale(); //convert the color to gray scale
   //   Color median_pixel(std::vector<Color> window); //apply a median filter to a windows of pixels
      int rgb_to_hex(); //convert the rgb values to hex
  };
}
#endif
