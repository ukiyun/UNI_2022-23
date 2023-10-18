#ifndef __prog_XPM2_hpp__
#define __prog_XPM2_hpp__

#include <string>
#include "Image.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include "PNG.hpp"

namespace prog {
    Image* loadFromXPM2(const std::string &file);

    void saveToXPM2(const std::string& file, const Image* img);
}
#endif
