// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #4

//filters the books in the book array and returns the number of books that are the same genre as the inputed genre 

#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

//finds the number of books in the array of a certain genre 
int countGenre(string genre, Book books [], int NumbooksStored){
    int i=0;
    int count=0;
    for ( i = 0; i < NumbooksStored; i++){
     if (books[i].getGenre().compare(genre)==0){
         count++;
        }
     }
    return count;
}

//main function to test countGenre function
int main(){
    Book books[50];
    int numUsersStored = 0;
    int booksArrSize = 50;
    books[0].setAuthor("Danny Davis");
    books[0].setTitle("Book Title");
    books[0].setGenre("science fiction");
    books[1].setAuthor("Author Z");
    books[1].setTitle("Book N");
    books[1].setGenre("Genre B");
    cout<<countGenre("science fiction", books, 2)<<endl;
    cout<<countGenre("fantasy", books, 2);
}