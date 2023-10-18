#include <iostream>
#include <utility>
#include <map>
#include <string>
using namespace std;

unsigned roman_to_arab(const string& roman){
    string roman_numbers = "";
    int arab_numbers = 0;
    string processed ="";
    map<char, unsigned> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };
    int prev = 0;
    for(char c: roman){
        int curr = roman_to_int.at(c);
        arab_numbers += curr;
        if (prev < curr){
            arab_numbers -= 2*prev;
        }
        prev = curr;
    }

    return arab_numbers;
    
}




int main(){
    string r = "CMLXIV";
    cout << roman_to_arab(r) << '\n'; 
    return 0;
}