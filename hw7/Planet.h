// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 7 - Problem #1

// this file acts as a header file defining the Planet class and its functions


//Header file
#ifndef PLANET_H
#define PLANET_H
#include <string>
using namespace std;

class Planet{
    public:
        Planet();   //defult constuctor 
        Planet(string s, double r);     //paramaterized constructor 
        //getters
        string getName();
        double getRadius();
        //setters 
        void setName(string s);
        void setRadius(double r);

        double getVolume();

    private:
        string planetName;
        double planetRadius;
};
#endif