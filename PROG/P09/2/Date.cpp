#include "Date.h"

Date::Date(){
    year_ = 1;
    month_ = 1;
    day_ = 1;
}

Date::Date(int year, int month, int day){
    year_ = year;
    month_=month;
    day_=day;
}

bool Date::is_before(const Date& date) const{
    if (date.year_>year_){
        return true;
    }else if(date.year_ < year_){
        return false;
    }else{
        if(date.month_>month_){
            return true;
        }else if(date.month_<month_){
            return false;
        }else{
            if(date.day_>day_){
                return true;
            }else{
                return false;
            }
        }
    }
}

