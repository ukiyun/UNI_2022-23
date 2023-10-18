#include <iostream>
#include <string>
#include <vector>
#include "print_string.h"
using namespace std;


void split(const string& s, vector<string>& v){
    int size = s.size();
    if (size==0){
        v = {};
    }else{
        string temp = "";
        for(int i = 0; i<size; i++){
            if(s[i]==' '){
                if(temp != ""){
                 v.push_back(temp);
                temp = "";   
                }
                
            }else{
                temp.push_back(s[i]);
            }
        }
        if(temp!=""){
          v.push_back(temp);  
        }
        
    }
}