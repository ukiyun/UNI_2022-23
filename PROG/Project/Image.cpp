#include "Image.hpp"
#include <cassert>
namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    assert(w > 0 && h > 0); //make sure the image has positive dimensions
    w_ = w; //set the width
    h_ = h;   //set the height
    pixels_.resize(w_, std::vector<Color>(h_,fill)); //resize the vector of vectors of Color objects to the width
  }

  Image::~Image()
  {
  }
  int Image::width() const
  {
    return w_; //return the width
  }
  int Image::height() const
  {
    return h_; //return the height
  }

  Color& Image::at(int x, int y)
  {
   return pixels_[x][y]; //return the pixel at the given coordinates
  }

  const Color& Image::at(int x, int y) const
  {
    return pixels_[x][y]; //return the pixel at the given coordinates
  }

  void Image::invert(){
    for (int i = 0; i < width(); i++) //for each row
    {
      for (int j = 0; j < height(); j++) //for each column
      {
        pixels_[i][j].invert(); //invert the color of the pixel
      }
    }
  }

  void Image::to_gray_scale(){
    for (int i = 0; i < width(); i++)  //for each row
    {
      for (int j = 0; j < height(); j++) //for each column
      {
        pixels_[i][j].to_gray_scale(); //convert the color of the pixel to gray scale
      }
    }
  }

  void Image::replace(const Color& c1, const Color& c2){
    for (int i = 0; i < w_; i++) //for each row
    {
      for (int j = 0; j < h_; j++) //for each column
      {
        if (pixels_[i][j] == c1) //if the pixel is the same color as c1
        {
          pixels_[i][j] = c2; //replace it with c2
        }
      }
    } 
  }

  void Image::fill(int x, int y, int w, int h, const Color& c){
    for(int i=0; i<w_; i++){ //for each row
      for(int j=0; j<h_; j++){ //for each column
        if(i>=x && i<(x+w)){  //if the pixel is inside the rectangle (width)
          if(j>=y && j<(y+h)){ //if the pixel is inside the rectangle (height)
            pixels_[i][j] = c; //fill the pixel with the given color
          }
        }
      }
    }
  }

  void Image::add(const Image& img, const Color& neutral, int x, int y) {
        for(int i=0; i<img.width();++i){
            for(int j=0;j<img.height();++j){
                if(neutral!=img.pixels_[i][j]){
                    pixels_[i+x][j+y]=img.pixels_[i][j];
                }

            }
        }
    }


  void Image::h_mirror(){
    for(int i=0; i<w_/2; i++){ //for each row until the middle
      for(int j=0; j<h_; j++){ //for each column
        std::swap(pixels_[i][j], pixels_[w_-i-1][j]); //swap the pixels of the left and right side of the image
      }
    }
  }

  void Image::v_mirror(){
    for(int i=0; i<w_; i++){ //for each row
      for(int j=0; j<h_/2; j++){ //for each column until the middle
        std::swap(pixels_[i][j], pixels_[i][h_-j-1]); //swap the pixels of the top and bottom side of the image
      }
    }
  }

  void Image::crop(int x, int y, int w, int h) {
      std::vector<std::vector<Color>> pixels_2 = pixels_; // Create a copy of the image pixels

      std::vector<std::vector<Color>> newPixels(w, std::vector<Color>(h, Color::WHITE)); // Create a new image with the new width and height and fill it with white pixels

      for (int i = x, i2 = 0; i < w_ && i2 < w; i++, i2++) { // For each row of the original image until the width of the new image is reached
          for (int j = y, j2 = 0; j < h_ && j2 < h; j++, j2++) { // For each column of the original image until the height of the new image is reached
              newPixels[i2][j2] = pixels_2[i][j]; // Copy the pixels of the original image to the new image
          }
      }

      pixels_ = newPixels; // Update the pixels of the image

      w_ = w; // Update the width of the image
      h_ = h; // Update the height of the image
  }

  void Image::rotate_left(){
    int newWidth = h_; //the new width of the image is the height of the original image
    int newHeight = w_; //the new height of the image is the width of the original image

    std::vector<std::vector<Color>> rotatedPixels(newWidth, std::vector<Color>(newHeight, Color::WHITE)); //create a new image with the new width and height and fill it with white pixels

    for(int i=0; i<w_; i++){ //for each row of the original image
      for(int j=0; j<h_; j++){ //for each column of the original image
        rotatedPixels[j][w_ - i - 1] = pixels_[i][j]; //rotate the pixels of the image
      }
    }

    pixels_ = rotatedPixels; //update the pixels of the image

    w_ = newWidth; //update the width of the image
    h_ = newHeight; //update the height of the image
  }

  void Image::rotate_right(){
      int newWidth = h_; //the new width of the image is the height of the original image
      int newHeight = w_; //the new height of the image is the width of the original image

      std::vector<std::vector<Color>> rotatedPixels(newWidth, std::vector<Color>(newHeight, Color::WHITE)); //create a new image with the new width and height and fill it with white pixels

      for(int i=0; i<w_; i++){ //for each row of the original image
        for(int j=0; j<h_; j++){ //for each column of the original image
          rotatedPixels[h_ - j - 1][i] = pixels_[i][j]; //rotate the pixels of the image
        }
      }

      pixels_ = rotatedPixels; //update the pixels of the image

      w_ = newWidth; //update the width of the image
      h_ = newHeight; //update the height of the image
  }

void Image::median_filter(int ws)
{
  assert(ws >= 3 && ws % 2 == 1); // Check that the window size is valid and odd

  int halfWindowSize = ws / 2;

  Image tempImage(*this); // Create a temporary image to hold the filtered result

  for (int x = 0; x < width(); x++) // For each row
  {
    for (int y = 0; y < height(); y++) // For each column
    {
      std::vector<int> redValues; // Create a vector to hold the red values of the pixels in the window
      std::vector<int> greenValues; // Create a vector to hold the green values of the pixels in the window
      std::vector<int> blueValues; // Create a vector to hold the blue values of the pixels in the window

      for (int nx = std::max(0, x - halfWindowSize); nx <= std::min(width() - 1, x + halfWindowSize); nx++) // For each row in the window
      {
        for (int ny = std::max(0, y - halfWindowSize); ny <= std::min(height() - 1, y + halfWindowSize); ny++) // For each column in the window
        {
          const Color& pixel = tempImage.at(nx, ny); // Get the pixel at the current position
          redValues.push_back(pixel.red()); // Add the red value of the pixel to the red values vector
          greenValues.push_back(pixel.green()); // Add the green value of the pixel to the green values vector
          blueValues.push_back(pixel.blue()); // Add the blue value of the pixel to the blue values vector
        }
      }

      std::sort(redValues.begin(), redValues.end()); // Sort the red values vector
      std::sort(greenValues.begin(), greenValues.end()); // Sort the green values vector
      std::sort(blueValues.begin(), blueValues.end()); // Sort the blue values vector

      if(redValues.size()%2==0){ //if the number of pixels in the window is even
        int medianIndex = redValues.size() / 2; //the median index is the middle index
        int medianRed = (redValues[medianIndex]+redValues[medianIndex-1])/2; //the median red value is the average of the two middle values
        int medianGreen = (greenValues[medianIndex]+greenValues[medianIndex-1])/2; //the median green value is the average of the two middle values
        int medianBlue = (blueValues[medianIndex]+blueValues[medianIndex-1])/2; //the median blue value is the average of the two middle values

        Color& currentPixel = at(x, y); //get the current pixel
        currentPixel = Color(medianRed, medianGreen, medianBlue); //set the current pixel to the median color
      }
      else{ //if the number of pixels in the window is odd
        int medianIndex = redValues.size() / 2;  //the median index is the middle index
        int medianRed = redValues[medianIndex]; //the median red value is the middle value
        int medianGreen = greenValues[medianIndex]; //the median green value is the middle value
        int medianBlue = blueValues[medianIndex];  //the median blue value is the middle value

        Color& currentPixel = at(x, y); //get the current pixel
        currentPixel = Color(medianRed, medianGreen, medianBlue); //set the current pixel to the median color
      }
    }
  }
}



}