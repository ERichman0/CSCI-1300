// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #9

//This function takes an already existing user array and adds to the end of it a new user whos rated each book in the array a 0 

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

//function to add a new user to an array
int addUser(string userName, User users[], int numRatings, int numUsersStored, int usersArrSize){
    if(numUsersStored>=usersArrSize){
        return -2;
    }else{
        for(int i=0; i<numUsersStored; i++){
            string userValue=users[i].getUsername();
            if(userName==userValue||userName==""){
                return -1;
            }
        }
        users[numUsersStored].setUsername(userName);
        users[numUsersStored].setNumRatings(0);
        numUsersStored++;
        return numUsersStored;
    }
}  

//main function to test the addUser function
int main(){
    User users[10];
    int usersArrSize = 10;
    int numRatings = 5;
    users[0].setUsername("Knuth");
    users[1].setUsername("Richie");
    // Add 5 ratings
    for(int i=0; i<numRatings; i++) {
        users[0].setRatingAt(i, i);
        users[1].setRatingAt(i, 5-i);
    }

    int numUsersStored = 2;
    int val = addUser("Ninja", users, numRatings,numUsersStored, usersArrSize);
    cout<<"Total number of users in the array: "<<val<<endl;
}