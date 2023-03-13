// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #3

/* This code takes a file of prespective university students and their SAT GPA Intrest Level Highschool quality and 4 semesters worth
of grades and calculates a number and if that number is high enough the student should be let in, if the score is not high enough but 
the students are part of an outlier group they are also let in
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function to calculate the total admisions score
void calcScore(string line){
    for(int i=0; i<line.length(); i++){
        string sub=line.substr(0,line.length());
        if(sub[i]==','){
            string satString=sub.substr(i+1,4);
            string gpaString=sub.substr(i+1,3);
            string intrestString=sub.substr(i+1,2);
            string hsqString=sub.substr(i+1,1);
            string sem1String=sub.substr(i+1,2);
            string sem2String=sub.substr(i+1,2);
            string sem3String=sub.substr(i+1,2);
            string sem4String=sub.substr(i+1,2);
            cout<<satString<<endl<<gpaString<<endl<<intrestString<<endl<<hsqString<<endl<<sem1String<<endl<<sem2String<<endl<<sem3String<<endl<<sem4String<<endl;
        }
    }
}
//function to get the name of the student 
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
    cout<<name<<endl; 
    return name; 
}
int main(){
    //open file
    string fileName;
    cout<<"Enter the file name:"<<endl;
    cin>>fileName;
    ifstream in;
    in.open(fileName);
    //check to see if file opens
    if(in.fail()){
      cout<<"Could not open file."<<endl;
    }else{ 
        string line;
        while(getline(in,line)){
            calcScore(line);
            getName(line);
            //add in function call
        }
    }
}