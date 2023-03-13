// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #5

#include <iostream>
using namespace std; 

int main(){
    int year;//initialize year variable 
    int month;//initialize month variable 
    cout<<"Enter a year:"<<endl;//prompt user to enter value 
    cin>>year;//assign value 
    cout<<"Enter a month:"<<endl;//prompt user to enter value 
    cin>>month;//assign value 
    if (month<=0||month>12){//if statement to make sure month is a valid month 
        cout<<"Invalid month"<<endl;
    }
    
    switch (month){//start switch statement 
        case 1://if user enters on of these months 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            cout<<"31 days"<<endl;//prints this 
            break;
        case 2://if user enters month 2 
            if (year%4==0){//checks to see if year is a leap year
                if (year%100!=0||year%400==0){//if it is 
                    cout<<"29 days"<<endl;//print this 
                    }else{
                    cout<<"28 days"<<endl;//else print this 
                        }           
                    }else{
                        cout<<"28 days"<<endl;//or this 
                    }
                    
            break;
        case 4://if user enters on of these month values 
        case 6:
        case 9:
        case 11:
            cout<<"30 days"<<endl;//print this 
            break; 
    }    
}
