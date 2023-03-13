#include "Time.h"

        Time::Time(){
            hours=0;
            minutes-0;
            seconds=0;
        }
        Time::Time(int h, int m, int s){
            hours=h;
            minutes=m;
            seconds=s;
        }
        //getters
        int Time::getHours(){
            return hours;
        }
        int Time::getMinutes(){
            return minutes;
        }
        int Time::getSeconds(){
            return seconds;
        }
        //setters
        void Time::setHours(int h){
            hours=h;
        }
        void Time::setMinutes(int m){
            minutes=m;
        }
        void Time::setSeconds(int s){
            seconds=s;
        }

        int Time::timeInSeconds(){
            int inSeconds=(((hours*3600)+(minutes*60))+seconds);
            return inSeconds;
        }