#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "show_file.h"
#include <iomanip>
#include <vector>

using namespace std;

void calc_medians(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    double num;
    string identifier;
    vector<double> u;
    while(getline(in,line)){
        istringstream iss(line);
        iss >> identifier;
        if(identifier[0]== '#'){continue;}
        while(iss>>num){
            u.push_back(num);
        }
        sort(u.begin(),u.end());
        if(u.size()%2!=0){
            out << fixed << setprecision(1) << identifier << ' ' << u[u.size()/2]<<endl;
        }else{
            out << fixed << setprecision(1) << identifier << ' ' << 0.5*(u[u.size()/2-1]+u[u.size()/2])<<endl;
        }
        u.clear();
    }
}