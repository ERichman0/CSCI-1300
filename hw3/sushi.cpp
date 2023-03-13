// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #3 

#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    double numSushi;
    cout<<"Enter the number of sushi:"<<endl;
    cin>>numSushi;
    double finalCost;
    double discountCost;
    if (numSushi>0&&numSushi<10){
        finalCost=numSushi*1.99;
    }
    if (numSushi>9&&numSushi<20){
        discountCost=(numSushi*1.99)*.1;
        finalCost=(numSushi*1.99)-discountCost;
    }
    if (numSushi>19&&numSushi<50){
        discountCost=(numSushi*1.99)*.15;
        finalCost=(numSushi*1.99)-discountCost;
    }
    if (numSushi>49&&numSushi<99){
        discountCost=(numSushi*1.99)*.2;
        finalCost=(numSushi*1.99)-discountCost;
    }
    if (numSushi>=100){
        discountCost=(numSushi*1.99)*.25;
        finalCost=(numSushi*1.99)-discountCost;
    } 
    if (numSushi<=0){
        cout<<"Invalid input"<<endl;
    }else{
        cout<<fixed<<setprecision(2)<<"Total price: $"<<finalCost<<endl;
    }
}