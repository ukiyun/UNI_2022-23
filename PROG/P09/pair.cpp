#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;


template<typename T1, typename T2>
class Pair{
    public:
        Pair(const T1& first, const T2& second);
        T1 get_first() const;
        T2 get_second() const;
        void show();
    private:
        T1 first_;
        T2 second_;
};

template<typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second){
    first_=first;
    second_=second;
}

template<typename T1, typename T2>
T1 Pair<T1, T2>::get_first() const{
    return first_;
}

template<typename T1, typename T2>
T2 Pair<T1,T2>::get_second()  const{
    return second_;
}

template<typename T1, typename T2>
void Pair<T1,T2>::show(){
    cout << "{" << first_ << ',' << second_ << "}";
}


void sort_by_first(vector< Pair <string, int> > &v) {
    sort(v.begin(), v.end(), [](const Pair <string, int> &p1, const Pair <string, int> &p2) {
        return p1.get_first() < p2.get_first();
    });
}

void sort_by_second(vector< Pair <string, int> > &v) {
    sort(v.begin(), v.end(), [](const Pair <string, int> &p1, const Pair <string, int> &p2) {
        return p1.get_second() < p2.get_second();
    });
}

void show(vector<Pair<string, int>> v){
    cout << "{";
    for (size_t i= 0; i<v.size();i++){
        v[i].show();
    }
    cout << "}";
}