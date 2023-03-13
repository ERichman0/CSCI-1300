#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date{
    private:
    double day =0;
    string month;
    int year =0;
    double NumdaysTraveled =0;
    public: 
    Date();
    Date(double d, string m, int y, double ndt);
    double getDay();
    void setDay(double d);
    string getMonth();
    void setMonth (string m);
    int getYear();
    void setYear(int y);
    double getNumdaysTraveled();
    void setNumdaysTraveled(double ndt);
};
#endif


