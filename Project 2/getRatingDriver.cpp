// CS1300 Fall 2020
// Author: Ethan Richman & KC
// Recitation: 213 – Julia Romero
// Project 2 - Problem #8

//This code iterates through a user array and book array looking for an inputed username and book title 
//if both exist in their respective arrays then the function returns the value that the user rated the book 

#include "Book.h"
#include "User.h"
#include <string>
#include <iostream>

using namespace std;

//helper function to make a string all uppercase 
string toUpper(string s){
    string s1=s.substr(0,s.length());
    for(int i=0; i<s.length(); i++){
        s1[i]=toupper(s1[i]);
    }
    return s1;
}

//A function that takes a username and book title and returns the rating that the user gave that book
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks){
    int userIndex=-1;                   
    int bookIndex=-1;                   
    username=toUpper(username);         
    title=toUpper(title);              
    for(int i=0; i<numUsers;i++){       
        string userValue=toUpper(users[i].getUsername());
        if(userValue==username){        
            userIndex=i;                
        }
    }
    for(int i=0; i<numBooks;i++){
        string bookValue=toUpper(books[i].getTitle());
        if(bookValue==title){           
            bookIndex=i;          
        }
    }
    if(bookIndex==-1||userIndex==-1){   
        return -3;                     
    }else{    
        int rating=users[userIndex].getRatingAt(bookIndex);                        
        return rating;   
    }
}

//main function to test getRatings function
int main(){
    //Creating 3 books
    Book books[3];
    //Setting book title and author for book 1
    books[0].setTitle("Title1");
    books[0].setAuthor("Author1");
    //Setting book title and author for book 2
    books[1].setTitle("Title2");
    books[1].setAuthor("Author2");
    //Setting book title and author for book 3
    books[2].setTitle("Title3");
    books[2].setAuthor("Author3");

    //Creating 2 users
    User users[2];
    //Setting username and ratings for User1
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    //Setting username and ratings for User2
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);

    //Call function 
    cout<<getRating("User1", "Title2", users, books, 2, 3)<<endl;
}