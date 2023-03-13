#include "Date.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


Date::Date(){
    day=0;
    month="";
    year=0;
    NumdaysTraveled=0;
}

Date::Date(double d, string m, int y, double ndt){
    day=d;
    month=m;
    year=y;
    NumdaysTraveled=ndt;
}

double Date::getDay(){
    return day;
}

string Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

double Date::getNumdaysTraveled(){
    return NumdaysTraveled;
}


void Date::setDay(double d){
    day=d;
}

void Date::setMonth(string m){
    month=m;
}

void Date::setYear(int y)
{
    year=y;
}

void Date::setNumdaysTraveled(double ndt)
{
    NumdaysTraveled=ndt;
}
