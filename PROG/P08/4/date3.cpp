#include <iostream>
#include <iomanip>
#include "Date3.h"
using namespace std;

#include <sstream>

Date::Date(){
  this ->yyyymmdd = "00010101";
}

int Date::num_days(int year, int month){
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
  std::ostringstream oss(this->yyyymmdd);
  if (year>=1 && year <=9999 && month >=1 && month<=12 && day>=1 && day<=num_days(year, month)){
    oss << std::setfill('0') << std::setw(4) << year << std::setw(2) << month << std::setw(2) << day;
    yyyymmdd = oss.str();
  }else{
    this->yyyymmdd="00000000";
  }
}

Date::Date(const std::string& year_month_day){
  std::istringstream iss(year_month_day);
  int year, month, day;
  char fslash1, fslash2;
  iss >> year >> fslash1 >> month >> fslash2 >> day;

  std::ostringstream oss(this->yyyymmdd);

  if (year>=1 && year <=9999 && month >=1 && month<=12 && day>=1 && day<=num_days(year, month) && fslash1 == '/' && fslash2 == '/'){
    oss << std::setfill('0') << std::setw(4) << year << std::setw(2) << month << std::setw(2) << day;
    yyyymmdd = oss.str();
  }else{
    this->yyyymmdd="00000000";
  }
}

bool Date::is_valid() const{
  if (yyyymmdd=="00000000"){
    return false;
  }else{
    return true;
  }
}

int Date::get_year() const{
  int year = std::stoi(yyyymmdd.substr(0,4));
  return year;
}
int Date::get_month() const{
  int month = std::stoi(yyyymmdd.substr(4,2));
  return month;
}
int Date::get_day() const{
  int day = std::stoi(yyyymmdd.substr(6,2));
  return day;
}