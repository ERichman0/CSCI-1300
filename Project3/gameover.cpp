#include "Players.h"
#include "Resources.h"
#include "Distance.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool gameOver(Players player[],Resources resource, Distance distance){
    ofstream file("results.txt");
    string leaderName="";
    for(int i=0;i<4;i++){
        if(player[i].getLeader()==true){
            leaderName=player[i].getName();
        }
    }
    int finalMT=distance.getMT();
    int finalFood=resource.getFood();
    int finalCash=resource.getCash();
    file<<leaderName<<" lead you on a dangerous journey that has come to an end"<<endl;
    file<<"You ended the journey with: "<<endl;
    file<<finalMT<<" miles traveled"<<endl;
    file<<finalFood<<" lbs. of food left"<<endl;
    file<<"and "<<finalCash<<" dollars worth of cash left"<<endl;

    //sorting task
    cout<<"The Oregon trail is a dangerous game. Lets see who in your group was able to make it out alive."<<endl;
    for(int i=0;i<4;i++){
        if(player[i].getStatus()==true){
            cout<<player[i].getName()<<" was able to survive the journey"<<endl;
        }else{
            cout<<player[i].getName()<<" was not able to survive the journey"<<endl;
        }
    }
    return true; 
}

int main(){
    Distance distance=Distance(623, 77, "Chimney Rock");
    Resources resources=Resources(794,29,927,3,2,4);
    Players players[5];
    players[0].setName("Ethan");
    players[0].setStatus(true);
    players[0].setLeader(true);
    players[1].setName("Robert");
    players[1].setStatus(true);
    players[1].setLeader(false);
    players[2].setName("Kristin");
    players[2].setStatus(true);
    players[2].setLeader(false);
    players[3].setName("Becca");
    players[3].setStatus(true);
    players[3].setLeader(false);
    players[4].setName("Katie");
    players[4].setStatus(true);
    players[4].setLeader(false);

    gameOver(players, resources, distance);
}