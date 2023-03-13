#ifndef DISTANCE_H
#define DISTANCE_H
#include <string>
using namespace std;

class Distance{
    public:
        Distance();
        Distance(int m, int t, string n);
        //getters 
        int getMT();
        int getDtMS();
        string getName();
        //setters
        void setMT(int m);
        void setDtMS(int t);
        void setName(string n);
    private:
        int milesTraveled;
        int toMilestone;
        string name;

};
#endif