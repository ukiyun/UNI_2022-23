#include <iostream>
#include <iomanip>
#include <sstream>
#include "Date2.h"
using namespace std;


Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}


int days_in_month (int year, int month){ //determine if date has the right ammount of days for each month
    int days;
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if(year == 2 || (year%4==0 && (year%100!=0 || year%400 == 0))){
                days = 29;    
            }else{
                days = 28;
            }
            break;
    }

    return days;
}


Date::Date(int year, int month, int day){
    if (year >=1 && year <=9999){
        this->year=year;
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }
    if (month >=1 && month<=12){
        this->month=month;
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }
    if (day >=1 && day<=days_in_month(year, month)){
        this->day=day;    
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }

}

Date::Date(const std::string& year_month_day){
    istringstream pog(year_month_day);
    int year,month,day;
    char fslash1, fslash2;
    pog >> year >> fslash1 >> month >> fslash2 >> day;
    if (year >=1 && year <=9999 && fslash1 == '/' && fslash2 == '/'){
        this->year=year;
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }
    if (month >=1 && month<=12 && fslash1 == '/' && fslash2 == '/'){
        this->month=month;
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }
    if (day >=1 && day<=days_in_month(year, month) && fslash1 == '/' && fslash2 == '/'){
        this->day=day;    
    }else{
        this->year=0;
        this->month=0;
        this->day=0;
        return;
    }
}

bool Date::is_valid() const{
    if (year == 0 || month == 0 || day == 0){
        return false;
    }
    return true;
}
