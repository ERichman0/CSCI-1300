#include "Resources.h"
#include <iostream> 
#include <string>

using namespace std;

void deadOxen(Resources resource){
    int oxen=resource.getOxen();
    if(oxen>1){
        cout<<"Oh no! One of the oxen has died! You have "<<(oxen-1)<<" oxen left"<<endl; 
        resource.setOxen(oxen-1);
    }else if(oxen==1){
        cout<<"Oh no! One of the oxen has died! You have no oxen left unfortunantly your jounrey is over"<<endl; 
        resource.setOxen(0);
        //Game over function
    }
}

int main(){
    Resources resource=Resources(794,29,927,1,0,4);
    deadOxen(resource);
}