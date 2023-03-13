// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #1 

#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    double score1;//initialize variable to hold practicum score 1
    double score2;//initialize variable to hold practicum score 2
    double score3;//initialize variable to hold practicum score 3
    cout<<"Enter practicum 1 score:"<<endl;//prompt user to enter their practicum 1 score
    cin>>score1;//assign user input to correspoding variable
    cout<<"Enter practicum 2 score:"<<endl;//prompt user to enter their practicum 2 score
    cin>>score2;//assign user input to correspoding variable
    cout<<"Enter practicum 3 score:"<<endl;//prompt user to enter their practicum 3 score
    cin>>score3;//assign user input to correspoding variable
    double ave;//initialize variable to compute the practicum average 
    ave=(score1+score2+score3)/3;//calculate the average 
    cout<<fixed<<setprecision(2)<<"Practicum average: "<<ave<<endl;//print the average but make sure it only shows two decimal values 
    if (ave<67)//If-else statment declaring if the average is bellow 67 print 
    {
        cout<<"You can retake practicums during the final"<<endl;//this and if it is 67 or above 
    }else
    {
        cout<<"You have a passing practicum average";//print this 
    }  
}