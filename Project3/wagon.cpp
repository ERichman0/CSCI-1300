#include "Resources.h"
#include <iostream> 
#include <string>

using namespace std;

void brokenWagon(Resources resource){
    int wp=resource.getParts();
    if(wp>=1){
        cout<<"Oh no! Your wagon has broken!"<<endl; 
        resource.setParts(wp-1);
        cout<<"You fixed it by using one of your spare parts you now have "<<resource.getParts()<<" wagon parts left"<<endl;
    }else if(wp==0){
        cout<<"Oh no! Your wagon has broken! You have no more wagon parts left unfortunantly your jounrey is over"<<endl; 
        resource.setParts(0);
        //Game over function
    }
}

int main(){
    Resources resource=Resources(794,29,927,1,0,0);
    brokenWagon(resource);
}