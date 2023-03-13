// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #6

//This file defines and intiazlies all of the functions in the User Class

#include "User.h"
  
    User::User(){
        username="";
        numRatings=0;
        for(int i=0; i<50;i++){
            ratings[i]=0;
        }
    }
    User::User(string u, int r[], int n){
        username=u;
        for(int i=0; i<n;i++){
            ratings[i]=r[i];
        }
        numRatings=n;
    }
    string User::getUsername(){
        return username;
    }
    void User::setUsername(string u){
        username=u;
    }
    int User::getRatingAt(int index){
        if(index<size&&index>=0){
            int value=ratings[index];
            return value;
        }else{
            return -1;
        }
    }
    bool User::setRatingAt(int index, int value){
        if(index<size&&index>=0&&value>=0&&value<=5){
            ratings[index]=value;
            return true;
        }else{
            return false;
        }
    }
    int User::getNumRatings(){
        return numRatings;
    }
    void User::setNumRatings(int n){
        numRatings=n;
    }
    int User::getSize(){
        return size; 
    }