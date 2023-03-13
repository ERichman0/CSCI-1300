#include <iostream>

using namespace std; 

int main(){
    int numSeconds;//initialize variable to hold user input
    cout<<"Enter a number of seconds: "<<endl;//prompt user to enter a value 
    cin>>numSeconds;//set input value to variable 
    int seconds;//initialize variable seconds 
    int minutes;//initialize variable minutes
    int hours; //initialize variable hours 
    int minutesandSeconds;//initialize variable minutesandSeconds
    hours=numSeconds/3600;//divide number of seconds by 3600 to determine how many hours can be made from the seconds
    minutesandSeconds=numSeconds%3600;//see how many seconds remain after determining the number of hours
    minutes=minutesandSeconds/60;//see how many minutes can be made from the remaining seconds 
    seconds=minutesandSeconds%60;//deterimine how many seconds remain 
    cout<<hours<<" hour(s) "<<minutes<<" minute(s) "<<seconds<<" second(s) ";//print statement
}