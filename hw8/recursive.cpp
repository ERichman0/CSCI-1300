// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 8 - Problem #4

#include <iostream>
#include <string>
#include <vector> 
#include <sstream>


using namespace std;

string decimalToBinaryRecursive(int num){
    string s="";
    int binary[32];
    char c;
    if(num==0||num==1){
        s+=to_string(num);
        return s;
    }else{
        c=('0'+num%2);
        return decimalToBinaryRecursive(num/2)+c;
    }
}

int main(){
    cout<<decimalToBinaryRecursive(0)<<endl;
    cout<<decimalToBinaryRecursive(5)<<endl;
    cout<<decimalToBinaryRecursive(8)<<endl;
}


  
