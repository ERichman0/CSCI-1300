#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
#include <iostream>
using namespace std;

//Make Players class to keep track of the players in the game.
class Players{     
    private:
    string name;
    bool status;
    bool leader;

    public: 
    Players();
    Players(string n, bool status, bool leader);
    string getName();
    void setName(string n);
    bool getStatus();
    void setStatus( bool status);
    bool getLeader();
    void setLeader(bool leader);

};

#endif