#include "XPM2.hpp"

namespace prog {
    Image* loadFromXPM2(const std::string& file) {
        Image* img = nullptr;
        std::ifstream ifs;
        ifs.open(file);
        std::vector<std::string> lines;
        std::string line;

        while(ifs >> line){
            lines.push_back(line);
        }
        
        int numberOfLines = lines.size();
        
        // Parse the XPM2 values section (w, h, n, c)
        std::istringstream valuesStream(lines[1]);
        int w, h, n, c;
        valuesStream >> w >> h >> n >> c;
        // Parse the XPM2 colors section
        std::unordered_map<char, Color> colorMap(n);
        for (int i = 2; i < numberOfLines; i++) {
            std::istringstream colorStream(lines[i]);
            std::string hexcode;
            Color color;
            char character;
            std::string cd;
            colorStream >> character >> cd >> hexcode;
            hexcode = hexcode.substr(1);
            color.red() = std::stoi(hexcode.substr(0, 2), nullptr, 16);
            color.green() = std::stoi(hexcode.substr(2, 2), nullptr, 16);
            color.blue() = std::stoi(hexcode.substr(4, 2), nullptr, 16);

            colorMap.insert({ character, color });
            
        }
        
        // Create the image and fill it with the XPM2 pixels
        img = new Image(w, h);
        for (int y = 0; y < h +2 +n; y++) {
            for (int x = 0; x < w; x++) {
                char pixel = lines[y + 2 + n][x];
                Color color = colorMap.at(pixel);
                img->at(x, y) = color;
            }
        }
        
        ifs.close();


        return img;
    }

    void saveToXPM2(const std::string& file, const Image* img) {
        if (img == nullptr) {
            std::cerr << "Cannot save null image!" << std::endl;
            return;
        }
        
        std::ofstream ofs(file);
        if (!ofs.is_open()) {
            std::cerr << "Unable to open file for writing: " << file << std::endl;
            return;
        }
        
        int w = img->width();
        int h = img->height();
        int n = 1; // Number of colors
        ofs << "/* XPM */" << std::endl;
        ofs << "static char* image[] = {" << std::endl;
        
        ofs << w << ' ' << h << ' ' << n << ' ' << 1  << ",\n"; // XPM2 values section
        
        // XPM2 colors section
        ofs << "c " << n << ",\n";
        ofs << "0 c #000000" << ",\n";
        
        // XPM2 pixels section
        ofs << '"';
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                Color color = img->at(y, x);
                if (color == Color::BLACK) {
                    ofs << '0';
                } else {
                    ofs << ' ';
                }
            }
            ofs << '"';
            if (y != h - 1) {
                ofs << ",";
            }
            ofs << std::endl;
        }
        ofs << "};" << std::endl;
        ofs.close();
    }

}
