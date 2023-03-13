// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #6

//This file gives a user an option to chose from running either filling an array of Book objects
//Or printing an array of book objects using a menu input system

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

void printAllBooks(Book books[], int numBooks){
    if(numBooks>0){
        cout<<"Here is a list of books"<<endl;
        for(int i=0; i<numBooks; i++){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }else{
        cout<<"No books are stored"<<endl;
        }
    }


int main(){
    int input;
    while(input!=3){
        cout<<"======Main Menu====="<<endl<<"1. Read books"<<endl<<"2. Print all books"<<endl<<"3. Quit"<<endl;
        cin>>input;
        if(input>4||input<=0){
            cout<<"Invalid input."<<endl; 
        }
        string fileName;
        Book books[50];
        int numBooksStored;
        int booksArrSize=50;
        int numBooks;
        switch (input)
        {
        case 1:
            cout<<"Enter a book file name: "<<endl;
            cin>>fileName;
            if(readBooks(fileName,books,numBooksStored,booksArrSize)==-1){
                cout<<"No books saved to the database."<<endl;
            }else if(readBooks(fileName,books,numBooksStored,booksArrSize)==-2){
                cout<<"Database is already full. No books were added."<<endl;
            }else{
                cout<<"Total books in the database: "<<readBooks(fileName,books,numBooksStored,booksArrSize)<<endl;
            }
            break;
        
        case 2:
            printAllBooks(books,numBooks);
            break;
        
        case 3:
            cout<<"Good bye!"<<endl;
            break;
        }
    }
}

