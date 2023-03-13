// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 8 - Problem #3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decimalToBinaryIterative(int num){
   string s="0";
   int binary[32];
   int count=0;
   while(num>0){
      binary[count]=num%2;
      num=num/2;
      count++;
   }
   for(int i=count-1; i>=0; i--){
      s+=to_string(binary[i]);
   }
   return s;
}

int main(){
    cout<<decimalToBinaryIterative(0)<<endl;
    cout<<decimalToBinaryIterative(5)<<endl; 
    cout<<decimalToBinaryIterative(8)<<endl;
}