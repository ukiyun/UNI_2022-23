#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(const string& id) {
    id_ = id;
}

void Student::add(const course& c) {
    courses_.push_back(c);
}

string Student::get_id() const {
    return id_;
}

double Student::avg() const {
    double sum = 0;
    double dum = 0;
    int size = courses_.size();
    for (int i = 0; i < size; i++) {
        sum += courses_[i].grade*courses_[i].credits;
    }
    for (int j = 0; j < size; j++) {
        dum += courses_[j].credits;
    }

    if(size == 0){
        return 0;
    }
    return sum / dum;
}