// CS1300 Fall 2020
// Author: Ethan Richman & KC Yenza
// Recitation: 213 – Julia Romero
// Project 2 - Problem #11

//This function provides the user the chance to decide what they want to do using a menu 

#include "User.h"
#include "Book.h"
#include <iostream>
#include <string>
#include<fstream>

using namespace std;

int split(string line, char seperator, string myLine[], int size){//split function
    int i=0;
    int j=0;
    string temp="";

    if(line == ""){
        return 0;
    }

    line=line+seperator;
    int lineSize=line.length();
    for(i=0; i<lineSize;i++){
        if(line[i] != seperator){
            temp += line[i];
        }else{
            myLine[j]=temp;
            j++; 
            temp="";
        }
    }
    return j;
}

int readBooks(string fileName, Book books[], int numBooksStored, int booksArrSize){//read books 
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

void printAllBooks(Book books[], int numBooks){//print books function
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

int countGenre(string genre, Book books [], int NumbooksStored){//countGenre function
    int i=0;
    int count=0;
    for ( i = 0; i < NumbooksStored; i++){
     if (books[i].getGenre().compare(genre)==0){
        count++;
        }   
    }  
    return count;
}

int printAuthorGenre (string genre, char authorFirstLetter, Book books[],int numBooksStored){//printAuthorGenre function
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    for (int i = 0; i < numBooksStored; i++){
        if (genre==books[i].getGenre()&& authorFirstLetter==books[i].getAuthor()[0]){
            if (l==0){
                cout<<"Here is a list of books that match this genre-author pair:"<<endl;
                l++;
            }
            cout<<books[i].getTitle()<<" by ";
            cout<<books[i].getAuthor() <<endl;
            k++;
        }      
    }
    if (k==0){
        cout<<"No titles found for this genre-author pair." <<endl;
    }
return k;
}

int addUser(string userName, User users[], int numRatings, int numUsersStored, int usersArrSize){//Add user
    if(numUsersStored>=usersArrSize){
        return -2;
    }else{
        for(int i=0; i<numUsersStored; i++){
            string userValue=users[i].getUsername();
            if(userName==userValue||userName==""){
                return -1;
            }
        }
        users[numUsersStored].setUsername(userName);
        users[numUsersStored].setNumRatings(0);
        numUsersStored++;
        return numUsersStored;
    }
}

int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol){//Read ratings
    string line="";
    string arr[101];
    //open file input
    ifstream in;
    //open file 
    in.open(filename);
    //if statement if cannot open file 
    if(numUsersStored>=usersArrSize){
        return -2;
    }else if(in.fail()){
      return -1;
    }else{
        while(getline(in,line)){
            int index=0;
            index=split(line,',', arr, maxCol);
            if(line.length()!=0){
                users[numUsersStored].setUsername(arr[0]);
                for(int i=1; i<index; i++){
                    string value=arr[i];
                    users[numUsersStored].setRatingAt(i-1,stoi(value));
                }
                numUsersStored++;
            }
            if(numUsersStored==usersArrSize){
                return numUsersStored;
            }
        }
    }
    return numUsersStored;
}

string toUpper(string s){//helper function for the getRating function
    string s1=s.substr(0,s.length());
    for(int i=0; i<s.length(); i++){
        s1[i]=toupper(s1[i]);
    }
    return s1;
}

int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks){//Get Rating
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


int getUserStats(string username, User users [], int numUsers, int numBooks){//getUserStatsFunction
    int numRatings=0;
    double avgRatings=0;
    double average=0;
    for (int i = 0; i < numUsers; i++){
        if (username==users[i].getUsername()){
            numRatings=users[i].getNumRatings();
            if (numRatings>0){
                for (int j = 0; j< users[i].getNumRatings(); j++){
                    if (users[i].getRatingAt(j)!=0){
                        avgRatings=avgRatings + users[i].getRatingAt(j);
                        }else{
                            numRatings --;}
                        }
                    average=avgRatings/numRatings;
                    cout<<username<< " rated "<<numRatings<< " books"<<endl;
                    cout<<username<<"'s average rating was "<< setprecision(2)<<fixed<<average<<endl;
                    return 1;                

                    }else if (users[i].getNumRatings()==0){
                        cout<<username<< " has not rated any books." <<endl;
                        return 0;
                        }
                        
                        
                }   
            }
            cout<< username<< " does not exist."<< endl;
            return-3;  
}

//main function to give the user to choose what they want to do 
int main(){
    string fileName;
    Book books[50];
    int numBooksStored;
    int booksArrSize = 50;
    int numUsersStored;
    int total;
    string genre;
    string username;
    string title;
    User users[100];
    char authorFirstLetter;
    int numReturnedTitles;
    int numberOfUsers;
    int usersArrSize = 100;
    int maxCol = 50;
    int numberOfBooksInGenre;
    int rating;
    int addUserReturn;
    int numRatings;
    int option;

    do{
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books from file" << endl;
        cout << "2. Print all books" << endl;
        cout << "3. Book-count by genre" << endl;
        cout << "4. Filter books by genre, author" << endl;
        cout << "5. Add user" << endl;
        cout << "6. Read ratings" << endl;
        cout << "7. Get rating" << endl;
        cout << "8. Get user statistics" << endl;
        cout << "9. Quit" << endl;
        cin >> option;
        switch (option){
        case 1:
            cout << "Enter a book file name:" << endl;
            cin >> fileName;
            total = readBooks(fileName, books, total, booksArrSize);
            if(total == -1){
                cout << "No books saved to the database." << endl;
            }
            else if(total == -2){
                cout << "Database is already full. No books were added." << endl;
            }
            else if(total == booksArrSize){
                cout << "Database is full. Some books may have not been added." << endl;
            }else{
                cout << "Total books in the database: " << total << endl;
            }
            break;
       
        case 2:
            printAllBooks(books, total);
            break;
       
        case 3:
            cout << "Enter the genre:" << endl;
            getline(cin,genre);
            getline(cin,genre);
            numberOfBooksInGenre = countGenre(genre, books, 50);
            cout << "Total " << genre << " books in the database: " << numberOfBooksInGenre << endl;
            break;
       
        case 4:
            cout << "Enter the genre:" << endl;
            getline(cin,genre);
            getline(cin,genre);
            cout << "Enter first char of author name:" << endl;
            cin >> authorFirstLetter;
            numReturnedTitles = printAuthorGenre(genre, authorFirstLetter, books, 50);
            cout << "Number of titles found for this filter: " << numReturnedTitles << endl;
            break;
       
        case 5:
            cout << "Enter a user name:" << endl;
            getline(cin,username);
            getline(cin,username);
            addUserReturn = addUser(username, users, numRatings, numUsersStored, usersArrSize);
            if(addUserReturn == -1){
                cout << "User already exists, cannot be overwritten." << endl;
            }else if(addUserReturn == -2){
                cout << "Database is already full. User cannot be added." << endl;
            }else{
                cout << "Welcome, " << username << "!" << endl;
            }
            break;
       
        case 6:
            cout << "Enter the ratings file name:" << endl;
            cin >> fileName;
            numberOfUsers = readRatings(fileName, users, numUsersStored, usersArrSize, maxCol);
            if(numberOfUsers == -1){
                cout << "No ratings saved to the database." << endl;
            }else if(numberOfUsers == -2){
                cout << "Database is already full. No ratings were added." << endl;
            }else if(numberOfUsers == usersArrSize){
                cout << "Database is full. Some ratings may have not been added." << endl;
            }else{
                cout << "Total users in the database: " << numberOfUsers << endl;
            }
            break;
       
        case 7:
            cout << "Enter a user name:" << endl;
            getline(cin,username);
            getline(cin,username);
            cout << "Enter a book title:" << endl;
            getline(cin,title);
            rating = getRating(username, title, users, books, 100, 50);
            if(rating == -3){
                cout << username << " or " << title << " does not exist." << endl;
            }else{
                cout << username << " rated " << title << " with " << rating << endl;
            }
            break;
       
        case 8:
            cout << "Enter a user name:" << endl;
            getline(cin,username);
            getline(cin,username);
            getUserStats(username, users, numUsersStored, numBooksStored);
            break;

        case 9:
            cout << "Good bye!" << endl;
            break;

        default:
            cout << "Invalid input." << endl;
            break;
        }
    }while (option != 9);
}