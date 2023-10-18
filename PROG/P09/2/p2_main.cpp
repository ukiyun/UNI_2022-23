#include "Person.h"
#include "Date.h"
#include <vector>
#include <iostream>
using namespace std;

void born_before(const vector<Person>& persons, const Date& date){
    date.show();
    cout << ": ";
    for (size_t i = 0; i<persons.size(); i++){
        Date temporaryBirthdate = persons[i].get_birth_date();
        if(temporaryBirthdate.is_before(date)==true){
            persons[i].show();
            cout << ' ';
        }
    }
}