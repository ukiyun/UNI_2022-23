#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "print.h"

using namespace std; 

string uppercase(string in){
    for(char &c: in){c=toupper(c);}
    return in;
}

void normalise(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line, word;
    while(getline(in,line)){
        istringstream iss(line);
        if(iss>>word){
            line = uppercase(line.substr(line.find_first_not_of(' '), line.length()));
            line = line.substr(0,line.find_last_not_of(' ')+1);
            out << line << endl;
        }
    }
}