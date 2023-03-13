// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #4

#include <iostream>
using namespace std; 

int main(){
    int weight1;//initialize variables to hold boxer 1 weight
    int weight2;//initialize variables to hold boxer 2 weight
    int weight3;//initialize variables to hold boxer 3 weight
    cout<<"Enter boxers' weights"<<endl;//prompt user to enter boxers weights 
    cin>>weight1;//assign value 
    cin>>weight2;//assign value 
    cin>>weight3;//assign value 
    if(weight1<weight2){//if statement syaing that if weight 1 is less than weight 2 
        if (weight2<weight3){//check to see if weight 2 is also less than weight 3 
            cout<<"Ascending order"<<endl;//if true print 
        }else{
            cout<<"Neither"<<endl;//if false print 
        }    
    }
    if (weight1>weight2){//if statement saying that if weight 1 is greater than weight 2 
        if (weight2>weight3){//check to see if weight 2 is greater than weight 3 
            cout<<"Descending order"<<endl;//if true pring
        }else{
            cout<<"Neither"<<endl;//if false print
        }  
    }
    if(weight1==weight2||weight2==weight3){//check to see if any of the weights are equal to eachother 
        cout<<"Neither"<<endl;//if true print 
    }
}