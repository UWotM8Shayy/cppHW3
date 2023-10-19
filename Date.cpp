#include "Date.h"
#include <iostream>


Date::Date() : day(1), month(1), year(2000) {}


Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}


void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}


void Date::printDate() const {
    std::cout << day << "/" << month << "/" << year << std::endl;
}
