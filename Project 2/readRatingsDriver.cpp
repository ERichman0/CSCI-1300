// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #7

//This function reads through a file and seperates the names of each user and assigns them to a index in a user array
//it then gets the rating that each user gave to a certain book and assigns that to the correspoding rating value to the user


#include "User.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function to split a string into seperate parts based on a common seperator value 
int split(string line, char seperator, string myLine[], int size){
    int i=0;
    int j=0;
    string temp="";

    if(line == ""){
        return 0;
    }

    line=line+seperator;
    int lineSize=line.length();
    for(i=0; i<lineSize;i++){
        if(line[i] != seperator){
            temp += line[i];
        }else{
            myLine[j]=temp;
            j++; 
            temp="";
        }
    }
    return j;
}

//function that reads a file and outputs the users in the file and their ratings 
int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol){
    string line="";
    string arr[101];
    //open file input
    ifstream in;
    //open file 
    in.open(filename);
    //if statement if cannot open file 
    if(numUsersStored>=usersArrSize){
        return -2;
    }else if(in.fail()){
      return -1;
    }else{
        while(getline(in,line)){
            int index=0;
            index=split(line,',', arr, maxCol+1);
            if(line.length()!=0){
                users[numUsersStored].setUsername(arr[0]);
                for(int i=1; i<index; i++){
                    string value=arr[i];
                    users[numUsersStored].setRatingAt(i-1,stoi(value));
                }
                numUsersStored++;
            }
            if(numUsersStored==usersArrSize){
                return numUsersStored;
            }
        }
    }
    return numUsersStored;
}

//main function to call readRatings function 
int main(){
    User users[10];
    int numUsersStored= 0;
    int usersArrSize = 10;
    readRatings("ratings.txt", users, numUsersStored,usersArrSize, 50);

    // Code to print the Username
    cout<<users[0].getUsername()<<endl;
    cout<<users[1].getUsername()<<endl;
    cout<<users[2].getUsername()<<endl;
    cout<<users[3].getUsername()<<endl;

    // Code to print the ratings
    cout<<users[0].getRatingAt(0)<<endl;
    cout<<users[0].getRatingAt(1)<<endl;
    cout<<users[0].getRatingAt(2)<<endl;
    cout<<users[0].getRatingAt(3)<<endl;
    cout<<users[0].getRatingAt(4)<<endl;

    cout<<users[2].getRatingAt(0)<<endl;
    cout<<users[2].getRatingAt(1)<<endl;
    cout<<users[2].getRatingAt(2)<<endl;
    cout<<users[2].getRatingAt(3)<<endl;
    cout<<users[2].getRatingAt(4)<<endl;
}