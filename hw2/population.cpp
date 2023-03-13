#include <iostream>

using namespace std; 

int main(){
    double birthRateS=1.0/8.0;//initalize double variable that holds amount of births per second
    double deathRateS=1.0/12.0;//initalize double variable that holds amount of deathes per second
    double immigrationRateS=1.0/27.0;//initalize double variable that holds amount of immagrints per second
    int birthRateY=birthRateS*(((60*60)*24)*365);//change unit of measurment from seconds to a year
    int deathRateY=deathRateS*(((60*60)*24)*365);//change unit of measurment from seconds to a year
    int immigrationRateY=immigrationRateS*(((60*60)*24)*365);//change unit of measurment from seconds to a year
    int currentPop;//initialize variable to hold user input 
    cout<<"Enter the current population: "<<endl;//user input 
    cin>>currentPop;//assign user input 
    int endPop=currentPop+birthRateY-deathRateY+immigrationRateY;//calculate future population using the units per year rate
    cout<<"The population in one year: "<<endPop<<endl;//print
}