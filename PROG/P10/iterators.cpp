#include <vector>
#include <list>
#include <iostream>
#include <sstream>
 
using namespace std;
//write rest of templates functions
template <typename Itr> 
string to_string(Itr start, Itr end) { // 4
    ostringstream os;
    os << "[ ";
    while(start != end) {
        os << *start << " ";
        start++;
    }
    os << "]";
    return os.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b) { // 4
    int counter = 0;
    while(start != end) {
        if(*start == a) {
            *start = b;
            counter++;
        }
        start++;
    }
    return counter;
}