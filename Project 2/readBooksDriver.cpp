// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #2

//This function fills an array of Book objects with title, author, and genre


#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

//function to split a string into seperate parts based on a common seperator 
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

//Function to fill an array of books with the title, genre and author 
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

//main function to test readBooks function
int main(){
    Book books[2];
    books[0].setAuthor("Author Z");
    books[0].setTitle("Book N");
    books[0].setGenre("Genre B");
    cout<<readBooks("fileName.txt", books, 1, 2)<<endl;
}