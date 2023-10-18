#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "show_file.h"
#include <iomanip>
#include <climits>

using namespace std;

void maximum(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    double number = 0;
    int count = 0;
    double max = INT_MIN;
    string line;
    while(getline(in,line)){
        istringstream iss(line);
        while(iss>>number){
            count++;
            out << fixed << setprecision(3) << number << endl;
            if(number>max){
                max = number;
            }
        }
    }
    out << "count="<<count<<"/max="<< fixed << setprecision(3) << max;
}