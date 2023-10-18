#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "wc.h"


wcresult wc(const string& filename){
    ifstream in(filename); // opens file
    wcresult resolution = {0,0,0};
    string line;
    while(getline(in,line)){
      resolution.lines += 1;
      resolution.bytes += line.length()+1;
      string x;
      istringstream iss(line);
      while (iss >> x){
        resolution.words += 1;
      }
    }

    return resolution;
}