// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #5

//This function prints all the books of a certain genre where the author name starts with the given charecter 

#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored){
    int j=0;
    int index[50];
    for(int i=0; i<numBooksStored; i++){
        string author=books[i].getAuthor();
        if(books[i].getGenre()==genre && author[0]==authorFirstLetter){
            index[j]=i;
            j++;
        }
    }
    if(j==0){
        cout<<"No titles found for this genre-author pair."<<endl;
        return j;
    }else{
        cout<<"Here is a list of books that match this genre-author pair: "<<endl;
        for(int k=0; k<j; k++){
            cout<<books[index[k]].getTitle()<<" by ";
            cout<<books[index[k]].getAuthor()<<endl;
        }
    }
    return j;
}

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
    printAuthorGenre("science fiction", 'D', books,numUsersStored);
}