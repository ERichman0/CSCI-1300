#include "Date.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


Date::Date(){
    day=0;
    month=0;
    year=0;
    NumdaysTraveled=0;
}

Date::Date(int d, int m, int y, int ndt){
    day=d;
    month=m;
    year=y;
    NumdaysTraveled=ndt;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

int Date::getNumdaysTraveled(){
    return NumdaysTraveled;
}


void Date::setDay(int d){
    day=d;
}

void Date::setMonth(int m){
    month=m;
}

void Date::setYear(int y)
{
    year=y;
}

void Date::setNumdaysTraveled(int ndt)
{
    NumdaysTraveled=ndt;
}
