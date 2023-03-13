#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

void rest(Resources resource, Date date, Players player[]){
    int num=(rand()%3+1);
    cout<<"You have chosen to rest. You will rest for "<<num<<" days";
    int numPlayers=0;
    for(int i=0; i<4; i++){
        if(player[i].getStatus()==true){
            numPlayers++;
        }
    }
    resource.setFood(resource.getFood()-((numPlayers*3)*num));
    date.setDay(date.getDay()+num);
}

int main(){
    Resources resources=Resources(794,29,927,3,2,4);
    Players players[5];
    players[0].setName("Ethan");
    players[0].setStatus(true);
    players[0].setLeader(true);
    players[1].setName("Robert");
    players[1].setStatus(true);
    players[1].setLeader(true);
    players[2].setName("Kristin");
    players[2].setStatus(true);
    players[2].setLeader(true);
    players[3].setName("Becca");
    players[3].setStatus(true);
    players[3].setLeader(true);
    players[4].setName("Katie");
    players[4].setStatus(true);
    players[4].setLeader(true);
    Date date=Date(31,7,1847,123);
    rest(resources,date,players);
}