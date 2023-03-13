#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date{
    public: 
    Date();
    Date(int d, int m, int y, int ndt);
    int getDay();
    void setDay(int d);
    int getMonth();
    void setMonth (int m);
    int getYear();
    void setYear(int y);
    int getNumdaysTraveled();
    void setNumdaysTraveled(int ndt);

    private:
    int day;
    int month;
    int year;
    int NumdaysTraveled;
};
#endif


