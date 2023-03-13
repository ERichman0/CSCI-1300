#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
using namespace std;

class Time{
    public:
        Time();
        Time(int h, int m, int s);
        //getters
        int getHours();
        int getMinutes();
        int getSeconds();
        //setters
        void setHours(int h);
        void setMinutes(int m);
        void setSeconds(int s);

        int timeInSeconds();
    private:
        int hours;
        int minutes;
        int seconds;
};
#endif