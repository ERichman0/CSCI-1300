// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #4

//This function fills an array of Book objects with title, author, and genre


#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 


int split(string split, char sep, string array[], int size){
    int parts=0;
    int position=0;
    split=split+sep;

    if(split.length()==0){
        return parts;
    }

    for(int i=0; i<split.length(); i++){
        if(split[i]==sep){
            array[parts]=split.substr(position,(i-position));
            parts++;
            position=i+1;
        }
        if(parts>size){
            parts =-1;
        }
    }
    return parts; 
}


int readBooks(string fileName, Book books[], int numBooksStored, int booksArrSize){
    string line="";
    string arr[50];

    if(numBooksStored==booksArrSize){
        return -2;
    }
    //open file input
    ifstream in;
    //open file 
    in.open(fileName);
    //if statement if cannot open file 
    if(in.fail()){
      return -1;
    }
    while(getline(in,line)&&numBooksStored<booksArrSize){ 
            if(line != ""){
                split(line, ',', arr, 50);
                books[numBooksStored].setAuthor(arr[0]);
                books[numBooksStored].setTitle(arr[1]);
                books[numBooksStored].setGenre(arr[2]);
                numBooksStored++;
            }
        
    }
    return numBooksStored; 
    in.close();
}