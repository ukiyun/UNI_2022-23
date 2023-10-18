#include <iostream>
#include "Date1.h"

Date::Date() {
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}



bool is_before(const Date& date1, const Date& date2) {
    //separate the date in years, months and days
    int date1year = date1.get_year();
    int date1month = date1.get_month();
    int date1day = date1.get_day();
    int date2year = date2.get_year();
    int date2month = date2.get_month();
    int date2day = date2.get_day();

    //comparing separate instances
    int yearsdiff = date1year-date2year;
    int monthsdiff = date1month - date2month;
    int daysdiff = date1day - date2day;

    if (yearsdiff > 0) {
        return false;
    } else if (yearsdiff < 0) {
        return true;
    } else {
        if (monthsdiff > 0) {
            return false;
        } else if (monthsdiff < 0) {
            return true;
        } else {
            if (daysdiff >= 0) {
                return false;
            } else {
                return true;
            }
        }
    }
}