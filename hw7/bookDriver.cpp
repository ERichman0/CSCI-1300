#include "Book.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string title = "Harry Potter";
    string author= "J.K Rowling";
    string genre = "Magical";

    Book b1= Book(title, author, genre);
    cout<<"Title: "<<b1.getTitle()<<endl;
    cout<<"Author: "<<b1.getAuthor()<<endl;
    cout<<"Genre: "<<b1.getGenre()<<endl;
    
    b1.setAuthor("Ethan Richman");
    b1.setTitle("Ethan's world");
    b1.setGenre("Sports");
    cout<<"Title: "<<b1.getTitle()<<endl;
    cout<<"Author: "<<b1.getAuthor()<<endl;
    cout<<"Genre: "<<b1.getGenre()<<endl;

    Book books[2];
    books[0].setAuthor("Author Z");
    books[0].setTitle("Book N");
    books[0].setGenre("Genre B");
    readBooks("fileName.txt", books, 1, 2);
}

int readBooks(string fileName, Book books[], int numBooksStored, int booksArrSize){
    int numBook=0;
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
    while(getline(in,line)){ 
        for(int i=0; i<=numBooksStored; i++){
            if(line != ""){
                split(line, ',', arr, 50);
                books[numBook].setAuthor(arr[0]);
                books[numBook].setTitle(arr[1]);
                books[numBook].setGenre(arr[2]);
                numBook++;
            }
        }
    }
    return numBook; 
    in.close();
}