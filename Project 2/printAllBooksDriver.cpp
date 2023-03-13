// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #3

//This functions takes an array of book objects and prints the Title by the Author 

#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

//function to print the title of a book and its author 
void printAllBooks(Book books[], int numBooks){
    if(numBooks<=0){
        cout<<"No books are stored"<<endl;
    }else{
        cout<<"Here is a list of books"<<endl;
        for(int i=0; i<numBooks; i++){
            cout << books[i].getTitle();
            cout<<" by ";
            cout << books[i].getAuthor() << endl;
        }
    }
}

//main function to test printAllBooks function
int main(){
    Book books[2];
    books[0].setAuthor("Author Z");
    books[0].setTitle("Book N");
    books[0].setGenre("Genre B");
    printAllBooks(books,2);
}