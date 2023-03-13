#include "Distance.h"
#include <iostream>
#include <string>
#include <fstream> 

Distance mileStone(Distance distance){
    int milesTraveld=distance.getMT();
    ifstream file;
    file.open("milestones.txt");
    int MileStone=0;
    int toMileStone=0;
    string line;
    string milestoneName;
    int lineNum=1;
    while(getline(file,line)){
        if(lineNum%2==0){
            MileStone=stoi(line);
            
        }else{
            milestoneName=line;
        }
        lineNum++;
        if(milesTraveld<MileStone){
            toMileStone=MileStone-milesTraveld;
            cout<<"You have "<<toMileStone<<" until the next mile stone"<<endl;
            distance.setDtMS(toMileStone);
            cout<<"The name of the next milestone is"<<milestoneName<<endl;
            distance.setName(milestoneName);
            return distance;
        }else{
            lineNum++;
        }
    }
    return distance;
}

int main(){
    Distance distance=Distance();
    distance.setMT(50);
}