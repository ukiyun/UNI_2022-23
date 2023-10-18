#ifndef __prog_Script_hpp__
#define __prog_Script_hpp__

#include <string>
#include <fstream>
#include "Image.hpp"
#include "XPM2.hpp"

namespace prog
{
  class Script
  {
  public: 
    Script(const std::string &filename);
    ~Script();
    void run();
  private:
    // Current image.
    Image *image;
    // Input stream for reading script commands.
    std::ifstream input;
    // Root directory for output files.
    std::string root;
  private:
    // Private functions
    void clear_image_if_any();
    void open();
    void blank();
    void save();
    void xpm2_save(const std::string &filename);
    void xpm2_open(const std::string &filename);
  };
}
#endif
