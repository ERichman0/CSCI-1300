// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 3 - Problem #6

#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    int personalized;//intialize variable to hold how personalized the ad is 
    string answer;//initialze variable to hold scenario 1 answer becuase cannot initialize string in switch statement 
    cout<<"How personalized should the ad be? (1-3)"<<endl;//prompt user to enter a value 
    cin>>personalized;//assign value 
    if(personalized<0||personalized>3){//check to see if input was valid 
        cout<<"Invalid option."<<endl;
    }
    switch(personalized){//start switch statement 
        //scenario 1 
        case 1://if 1 entered 
            cout<<"Do you own a dog?"<<endl;//prompt user to enter string 
            cin>>answer;//assign valye
            if (answer=="Yes"||answer=="yes"){//if value equals one of these 
                cout<<"Meat's the need of dogs like yours!"<<endl;//print this 
            }else{
                cout<<"Dirty mouth? Clean it up with new Orbit Raspberry Mint."<<endl;//else print this 
            }
            break;//end scenario 1 
        //scenario 2 
        case 2://if 2 entered 
            int fbFriends;//initialize variable 
            cout<<"How many Facebook friends do you have?"<<endl;//prompt user to enter number
            cin>>fbFriends;//assign variable 
            if(fbFriends>=500){//if greater than or equal to 500
                cout<<"Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service."<<endl;//print this 
            }else{
                cout<<"Who doesn't need another cat? Adopt a shelter pet right meow."<<endl;//else print this 
            }
            break;//end scenario 2 
        //scenario 3
        case 3://if 3 entered 
            int zipCode;//initialize variable
            int age;//initialize variable 
            cout<<"What is your zip code?"<<endl;//prompt user to enter zip code
            cin>>zipCode;//assign value 
            cout<<"What is your age?"<<endl;//prompt user to enter age 
            cin>>age;//assign value 
            if(zipCode>=80301&&zipCode<=80310){//if zip code is a Boulder zip code 
                if(age>=25){// check age if greater than or equal to 25 
                    cout<<"You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike."<<endl;//print this 
                }else{
                    cout<<"Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen."<<endl;//else print this 
                }
            }else{//if not a Boulder zip code 
                cout<<"Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO"<<endl;//print this 
            }
            break;//end scenario 3 
    }
}