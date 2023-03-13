// CS1300 Fall 2020
// Author: Ethan Richman & KC 
// Recitation: 213 – Julia Romero
// Project 2 - Problem #1

//This is a header file for defining the Book class

//Header file
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book{
    public:
        Book(); 
        Book(string t, string a, string g);
        string getTitle();
        void setTitle(string t);
        string getAuthor();
        void setAuthor(string a);
        string getGenre();
        void setGenre(string g);
    
    private:
        string title;
        string author;
        string genre; 
};
#endif