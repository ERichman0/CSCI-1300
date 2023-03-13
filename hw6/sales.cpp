// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #2

/*this function reads a txt file and stores the name and sales in two separate arrays
The function then returns the number of employees stored and prints out the average monthly sales for each employee
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readSales(string fileName, string arr[], int arr2[][12], int size){
    int numEmployees=0;
    double avSales=0.0;
    int numSales=0;
    int employeeNumber;
    ifstream in_file;
    in_file.open(fileName);
    if(in_file.fail()){
        return -1;
    }else{
        int line_number=1;
        string line;
        while(getline(in_file,line)){
            int numElement=0;
            if(line_number%2==1){
                if(numEmployees>= size){
                    break;
                }
                arr[numEmployees]=line;
                numEmployees++;
            }else{
                for(int i=0; i<line.length(); i++){
                    if(line[i]==','){
                        string element=line.substr(0,i);
                        line=line.substr(i+1);
                        i=0;
                        arr2[employeeNumber][numElement]=stoi(element);
                        numElement++;
                    }
                }
                arr2[employeeNumber][numElement]=stoi(line);
                employeeNumber++;
            }
            line_number++;
        }
        for(int i=0;i<numEmployees;i++){
            cout<<arr[i]<<"; ";
            double totSales=0.0;
            for(int j=0; j<12; j++){
                totSales += double(arr2[i][j]);
            }
            double avSales=double(totSales/12);
            cout<<setprecision(1)<<fixed<<avSales<<endl;
        }
        return numEmployees;
    }
}

int main(){
    string fileName;
    string arr[100];
    int size=0;

    cout<<"Enter the file name: "<<endl;
    cin>>fileName;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;

    int arr2[10][12];
    readSales(fileName, arr, arr2, size);
}