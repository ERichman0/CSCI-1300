// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #2 

#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    double numHours;//initialize variable to hold number of hours worked a week
    double hourlyPay;//initialize variable to hold hourly pay rate
    cout<<"Enter the number of hours worked"<<endl;//prompt user to enter the number of hours they worked that week
    cin>>numHours;//assign user input to coresponding variable 
    cout<<"Enter an hourly pay rate"<<endl;//prompt user to enter their hourly pay rate 
    cin>>hourlyPay;//assign user input to variable 
    double overTime=0;//create new variable called overTime which holds the number of overtime hours the worker worked that week
    if (numHours>40){//if the worker worked overtime seperate the regular hours from the overtime hours 
        overTime=numHours-40;//subtract the number of hours from 40 to deterimne the number of overtime hours worked 
        numHours=40;//set numHours to the base of 40
    }
    double regularPay=numHours*hourlyPay;//deterimine how much they earn from working 40 or less hours
    double otPay=overTime*(1.5*hourlyPay);//determine how much overtime pay they recive
    double total=regularPay+otPay;//determine final paycheck 
    if (numHours<0||hourlyPay<0){//if else statement saying if either numHour or houlryPay input is less than 0
        cout<<"Invalid input"<<endl;//print this
    }else{
       cout<<fixed<<setprecision(2)<<"Paycheck: "<<total<<endl; //else print this 
    }  
}