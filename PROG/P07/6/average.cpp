#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

double average(const string& fname){
    ifstream in(fname);
    double num = 0;
    double count = 0;
    double averagesum = 0;
    while(!in.eof()){
        if(in>>num){
            averagesum += num;
            count++;
        }else{
            in.clear();
            in.ignore(1);
        }
    }

    return averagesum/count;
}