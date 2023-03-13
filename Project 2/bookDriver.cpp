//This is the driver file to test the Book class functions 

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
}

