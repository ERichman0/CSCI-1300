#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include "Distance.h"
#include <iostream>
#include <string>

using namespace std;

void initialConditions(){
    Players player[5];
    string leaderName="";
    cout<<"So you have decided to lead a journey across the Oregon Trail please enter your name brave adventurer:"<<endl;
    cin>>leaderName;
    player[0].setName(leaderName);
    player[0].setStatus(true);
    player[0].setLeader(true);
    string playerName="";
    cout<<"Now please enter the names of the 4 others that will be traveling with you"<<endl;
    for(int i=0;i<4;i++){
        cin>>playerName;
        player[i+1].setName(playerName);
        player[i+1].setStatus(true);
        player[i+1].setLeader(false);
    }
    cout<<"You party starts with $1600 and a wagon, you can spend your money at the store and at forts along the trail"<<endl;
    Resources resource=Resources(0,0,1600,0,0,0);
    Distance distance=Distance(0,102,"Kansas River Crossing");
    Date date=Date();
    int choice=0;
    cout<<"Would you like to start your journey on 03/28/1847?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
    cin>>choice;
    if(choice!=1&&choice!=2){
        cout<<"Please enter either a 1 or 2"<<endl;
        cin>>choice;
    }else{
        if(choice==1){
            cout<<"Great! Prepare to embark on your journey 03/28/1847"<<endl;
            date.setMonth(3);
            date.setDay(28);
            date.setYear(1847);
        }else{
            int month=0;
            int day=0;
            cout<<"Please enter a month between 3 and 5"<<endl;
            cin>>month;
            if(month<3||month>5){
                cout<<"Please choose a starting month between 3 and 5"<<endl;
                cin>>month;
            }else{
                date.setMonth(month);
            }
            cout<<"Please enter a day between 1 and 31"<<endl;
            cin>>day;
            if(day<1||day>31){
                cout<<"Please enter a day between 1 and 31"<<endl;
                cin>>day;
            }else{
                date.setDay(day);
            }
            cout<<"You have decided to start your journey on "<<month<<"/"<<day<<"/1847"<<endl;
        }
    }
}

int main(){
    initialConditions();
}