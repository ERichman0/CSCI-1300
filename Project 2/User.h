// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #6

//This is the header file for defining the User file 

#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User{
    public: 
        User();
        User(string u, int r[], int n);
        string getUsername();
        void setUsername(string u);
        int getRatingAt(int index);
        bool setRatingAt(int index, int value);
        int getNumRatings();
        void setNumRatings(int n);
        int getSize();

    private:
        string username;
        int ratings[50];
        int numRatings;
        static const int size=50;
};
#endif