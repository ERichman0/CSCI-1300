// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #5

//This functions takes an array of book objects and prints the Title by the Author 

#include "Book.h"
#include <iostream>
#include <string>

void printAllBooks(Book books[], int numBooks){
    if(numBooks<=0){
        cout<<"No books are stored"<<endl;
    }else{
        cout<<"Here is a list of books"<<endl;
        for(int i=0; i<numBooks; i++){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }
}