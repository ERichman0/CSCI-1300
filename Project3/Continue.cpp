#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include "Distance.h"
#include <iostream>
#include <string>

using namespace std;

void Continue(Resources resource, Date date, Players player[],Distance distance){
    cout<<"You have decided to continue on your journey. You will travel for 2 weeks."<<endl;
    //set the new date after they travel
    date.setDay(date.getDay()+14);
    //calculate amount of food eaten 
    int numPlayers=0;
    for(int i=0; i<4; i++){
        if(player[i].getStatus()==true){
            numPlayers++;
        }
    }
    resource.setFood(resource.getFood()-((numPlayers*3)*14));
    //check to see if the food is gone
    if(resource.getFood()<=0){
        cout<<"While you were traveling you ran out of food and your journey is over"<<endl;
        //game over function
    }
    //find how many miles you traveled 
    int milesTraveled=(rand()%(140-70+1)+70);
    //add to total miles
    distance.setMT(distance.getMT()+milesTraveled);
    //check to see if a milestone is going to be passed
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
    Distance distance=Distance(623, 77, "Chimney Rock");

    Continue(resources, date, players, distance);
}