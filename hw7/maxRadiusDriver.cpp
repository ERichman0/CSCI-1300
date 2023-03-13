// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #2

//this function takes in a array of planet objects and returns the index of the planet with the largest raidus 

#include <iostream>
#include <fstream>
#include <string>
#include "Planet.h"
using namespace std;

int maxRadius(Planet arr[], int numElements){
    if(numElements==0){
        return -1;
    }else{
        int index=0;
        double radius=0.0;
        for(int i=0; i<numElements;i++){
            if(arr[i].getRadius()>radius){
                radius=arr[i].getRadius();
                index=i;
            }
        }
        return index;
    }
}

int main(){
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet",1234);
    planets[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets, 2);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
}
