//This is the driver file to test all of the functions in the header and .cpp file for the User class

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    //Create paramaters for the User object
    string username="Ethan";
    int ratings[5]={1,2,3,4,5};
    int numRatings=5;

    User u1=User(username,ratings,numRatings);//Call paramaterized constructor 
    //Call getters 
    cout<<u1.getUsername()<<endl;
    cout<<u1.getRatingAt(1)<<endl;
    cout<<u1.getNumRatings()<<endl;
    cout<<u1.getSize()<<endl;

    User u2=User();//Call unparamaterized constructors 
    //Call setters
    u2.setUsername("Richman");
    u2.setRatingAt(1,3);
    u2.setNumRatings(3);
    //Call getters 
    cout<<u2.getUsername()<<endl;
    cout<<u2.getRatingAt(1)<<endl;
    cout<<u2.getNumRatings()<<endl;
    cout<<u2.getSize()<<endl;
}