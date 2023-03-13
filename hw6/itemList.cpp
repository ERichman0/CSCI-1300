// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #1

/*In the main function the code reads in a file of products and their prices 
it then finds the number of lines not including the empty ones and the most and least expensive product 
it then prints these values 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function to get the price of the item 
int getPrice(string line){
    int price;
        for(int i=0; i<line.length(); i++){
        //seperate at commas
        string sub=line.substr(0,line.length());
        if(sub[i]==','){
        sub=sub.substr(i+1,line.length());
        //store as a double
        price=stod(sub);
        }
    }
    return price; 
}

//function to get the name of the item  
string getName(string line){
    string name;
    for(int i=0; i<line.length(); i++){
    //seperate at commas
    string sub=line.substr(0,line.length());
    if(sub[i]==','){
    //store in subString 
    name=sub.substr(0,i);
        }
    } 
    return name;  
}

int main(){
    //open file input
    ifstream in;
    string fileName;
    //prompt user and assign value 
    cout<<"Enter the file name: "<<endl;
    cin>>fileName;
    //open file 
    in.open(fileName);
    //if statement if cannot open file 
    if(in.fail()){
      cout<<"Could not open file."<<endl;
    }
    else{
        //declare variables 
        int lineNum=0;
        string line;
        int numLines=0;
        string mostExpensive="";
        string leastExpensive="";
        int mostMoney=0;
        int leastMoney=99999999;
        //while loop to make sure there are still lines in the file 
        while(getline(in,line)){
            lineNum++;
            //find number of non-empty lines in the function
            if(line !=""){
                numLines++;
                //check to see if value is the most expensive 
                if(getPrice(line)>mostMoney){
                    //call getPrice function
                    mostMoney=getPrice(line);
                    //find name of the item 
                    mostExpensive=getName(line);
                }
                //check to see if value is least expensive 
                if(getPrice(line)<leastMoney){
                    //call getPrice function
                    leastMoney=getPrice(line);
                    //find name of the item 
                    leastExpensive=getName(line);
                }
            }
        }
        //print everything 
        cout<<"The number of lines: "<<numLines<<endl<<"The most expensive product: "<<mostExpensive<<endl<<"The least expensive product: "<<leastExpensive<<endl;
    }
}