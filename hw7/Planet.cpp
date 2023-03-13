// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #1

//This file defines and intiazlies all of the functions in the Planet Class

#include <cmath>
#include "Planet.h"

    Planet::Planet(){
        planetName="";
        planetRadius=0;
    }
    Planet::Planet(string s, double r){
        planetName=s;
        planetRadius=r;
    }
    string Planet::getName(){
        return planetName;
    }
    void Planet::setName(string s){
        planetName=s;
    }
    double Planet::getRadius(){
        return planetRadius;
    }
    void Planet::setRadius(double r){
        planetRadius=r;
    }
    double Planet::getVolume(){
        double planetVolume=(4*M_PI*planetRadius*planetRadius*planetRadius)/3;
        return planetVolume;
    }