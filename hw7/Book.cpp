// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 6 - Problem #3

//This file defines and intiazlies all of the functions in the Book Class

#include "Book.h"

    Book::Book(){
        title="";
        author="";
        genre="";
    } 
    Book::Book(string t, string a, string g){
        title=t;
        author=a;
        genre=g;
    }
    string Book::getTitle(){
        return title;
    }
    void  Book::setTitle(string t){
        title=t;
    }
    string Book::getAuthor(){
        return author;
    }
    void Book::setAuthor(string a){
        author=a;
    }
    string Book::getGenre(){
        return genre;
    }
    void Book::setGenre(string g){
        genre=g;
    }