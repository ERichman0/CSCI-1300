#ifndef RACETRACK_H
#define RACETRACK_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class RaceTrack{
    public:
        RaceTrack();
        RaceTrack(string n);
        bool addCar(double t, string m);
        double calcAvgSpeed();
        int countAvailable(double min);
        int countAvailableModels(string m); 

    private:
        string name;
        vector<string>models;
        vector<double>speeds;
};
#endif