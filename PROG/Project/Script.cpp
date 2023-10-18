#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"
#include "Image.hpp"

using namespace std;

namespace prog {
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }
    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            // XPM2 commands
            if (command == "xpm2_open"){
                // get the filename
                std::string filename;
                input >> filename;
                xpm2_open(filename);
            }
            if (command == "xpm2_save"){
                // get the filename
                std::string filename;
                input >> filename;
                xpm2_save(filename);
            }
            if (image == NULL){
                std::cout << "No image loaded! Stopping script." << std::endl;
                break;
            }
            // Other commands require an image to be previously loaded.
            if (command == "save") {
                save();
                continue;
            } 
            
            // Image changes

            if (command == "invert") {
                image->invert();
            }else if(command == "to_gray_scale"){
                image->to_gray_scale();
            }else if(command == "replace"){
                // get the two color values
                Color c1;
                Color c2;
                input >> c1 >> c2;
                image->replace(c1,c2);
            }else if(command == "fill"){
                // get the x, y, w, h, and color values
                int x;
                int y;
                int w;
                int h;
                input >> x >> y >> w >> h;
                Color c;
                input >>c;
                image->fill(x,y,w,h,c);
            }else if(command == "h_mirror"){
                image->h_mirror();
            }else if(command == "v_mirror"){
                image->v_mirror();
            }else if(command == "crop"){
                // get the x, y, w, h values
                int x;
                int y;
                int w;
                int h;
                input >> x >> y >> w >> h;
                image->crop(x,y,w,h);
            }else if(command == "rotate_left"){
                image->rotate_left(); 
            }else if(command == "rotate_right"){
                image->rotate_right();

            // Image additions
            }else if (command == "add"){
                // get the filename, color, x, and y values
                std::string filename;
                int x, y;
                Color neutral;
                input >> filename >> neutral >> x >> y;
                const Image* temp;
                temp = loadFromPNG(filename);
                image->add(*temp,neutral,x,y);
                delete temp; // fixes memory leaks
            
            // Median filter
            }else if (command == "median_filter"){
                // get the filename
                int ws;
                input >> ws;
                image->median_filter(ws);   

            }
        }
    }
    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }
    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }
    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    void Script::xpm2_open(const std::string &filename){
        // Replace current image (if any) with image read from XPM2 file.
        clear_image_if_any();
        image = loadFromXPM2(filename);
    }

    void Script::xpm2_save(const std::string& filename) {
        saveToXPM2(filename, image);
    }

}


