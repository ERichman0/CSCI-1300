// CS1300 Fall 2020
// Author: Ethan Richman & KC Yenza
// Recitation: 213 – Julia Romero
// Project 2 - Problem #10

//This program iterates through a array of User objects and looks for a user with the correspoding name of the inputed user name value
//it then prints the total number of books that user rated and their average rating 

#include "User.h"
#include <iomanip>
#include <iostream>
#include <string>

//Function that takes a users name and prints the number of books they have rated and their average rating 
using namespace std;
int getUserStats(string username, User users [], int numUsers, int numBooks){
    int numRatings=0;
    double avgRatings=0;
    double average=0;
    for (int i = 0; i < numUsers; i++){
        if (username==users[i].getUsername()){
            numRatings=users[i].getNumRatings();
            if (numRatings>0){
                for (int j = 0; j< users[i].getNumRatings(); j++){
                    if (users[i].getRatingAt(j)!=0){
                        avgRatings=avgRatings + users[i].getRatingAt(j);
                        }else{
                            numRatings --;
                            }
                        }
                        average=avgRatings/numRatings;
                        cout<<username<< " rated "<<numRatings<< " books"<<endl;
                        cout<<username<<"'s average rating was "<< setprecision(2)<<fixed<<average<<endl;
                        return 1;
                        }                
                        else if (users[i].getNumRatings()==0){
                            cout<<username<< " has not rated any books." <<endl;
                            return 0;
                        }   
                    }                
                }
            cout<< username<< " does not exist."<< endl;
            return-3;  
}

//main function to test the getUserStats function
int main(){
    //Creating 3 users
    User users[3];
    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    //Setting username and ratings for User2
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);
    //Setting username and ratings for User3
    users[2].setUsername("User3");
    users[2].setNumRatings(3);
    users[2].setRatingAt(0,0);
    users[2].setRatingAt(1,0);
    users[2].setRatingAt(2,0);

    getUserStats("User1", users, 3, 3);
}