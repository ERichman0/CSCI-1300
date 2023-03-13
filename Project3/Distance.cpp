#include "Distance.h"
    Distance::Distance(){
        milesTraveled=0;
        toMilestone=0;
        name="";
    }
    Distance::Distance(int m, int t, string n){
        milesTraveled=m;
        toMilestone=t;
        name=n;
    }
    int Distance::getMT(){
        return milesTraveled;
    }
    int Distance::getDtMS(){
        return toMilestone;
    }
    string Distance::getName(){
        return name;
    }
    void Distance::setMT(int m){
        milesTraveled=m;
    }
    void Distance::setDtMS(int t){
        toMilestone=t;
    }
    void Distance::setName(string n){
        name=n;
    }