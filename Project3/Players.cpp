#include "Players.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Players::Players ()
{
    name="";
    status=0;
    leader=0;

}

Players::Players(string n, bool s, bool l)
{
     name=n;
     status=s;
     leader=l;

}

string Players::getName()
{
    return name;
}



bool Players::getStatus()
{
    return status;
    
}

bool Players::getLeader()
{
    return leader;
}


void Players::setName(string n)
{
    name=n;
}


void Players::setStatus(bool s)
{
    status=s;
}

void Players::setLeader(bool l)
{
    leader=l;
}
