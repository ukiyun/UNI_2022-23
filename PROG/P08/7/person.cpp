#include <iostream>
#include <vector>
#include "Person.h"
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


Person::Person(const string& name, const string& address, const string& phone) {
    name_ = name;
    address_ = address;
    phone_ = phone;
}

string Person::get_name() const {
    return name_;
}

string Person::get_address() const {
    return address_;
}

string Person::get_phone() const {
    return phone_;
}

void read_persons_data(const string& filename, vector<Person>& persons) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string name, address, phone;
        iss >> name >> address >> phone;
        persons.push_back(Person(name, address, phone));
    }
}

void sort_persons_by_name(vector<Person>& persons) {
    sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2) {
        return p1.get_name() < p2.get_name();
    });
}