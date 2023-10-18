#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <string>
#include <stdexcept>

namespace prog
{
  class Image
  {
  private:
    int w_; //width
    int h_;  //height
    std::vector<std::vector<Color>> pixels_; //2D array of Color objects
  public:
    Image(int w, int h, const Color &fill = {255, 255, 255}); // constructor
    ~Image(); //destructor
    int width() const; //accessor for width
    int height() const;   //accessor for height
    Color &at(int x, int y); //accessor for pixel
    const Color &at(int x, int y) const; //accessor for pixel
    void invert(); //invert the image colors
    void to_gray_scale(); //convert the image to gray scale
    void replace(const Color& c1, const Color& c2); //replace all pixels of color c1 with color c2
    void fill(int x, int y, int w, int h, const Color& c); //fill the rectangle with the given color
    void h_mirror(); //mirror the image horizontally
    void v_mirror(); //mirror the image vertically
    void add(const Image& img,const Color& neutral, int x, int y); //add an image to the image at the given position
    void crop(int x, int y, int w, int h); //crop the image
    void rotate_left(); //rotate the image 90 degrees left
    void rotate_right(); //rotate the image 90 degrees right
    void median_filter(int ws); //apply a median filter to the image
  };
}
#endif
