#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include <iostream> 
#include <string>

using namespace std;

/*void rest(Resources resource, Date date, Players player[]){
    int num=(rand()%3+1);
    cout<<"You have chosen to rest. You will rest for "<<num<<" days";
    int numPlayers=0;
    for(int i=0; i<4; i++){
        if(player[i].getStatus()==true){
            numPlayers++;
        }
    }
    resource.setFood(resource.getFood()-((numPlayers*3)*num));
}*/ 

void illness(Players players[], Resources resource, Date date){//take in array of Players
    string disease="";
    int num=(rand()%6+1);
    //determine disease
    switch(num){
        case 1:
            disease="typhoid";
            break;
        case 2:
            disease="cholera";
            break;
        case 3:
            disease="diarrhea";
            break;
        case 4:
            disease="measles";
            break;
        case 5:
            disease="dysentery";
            break;
        case 6:
            disease="fever";
            break;
    }
    //determine person
    string name="";
    bool leader=players[num].getLeader();
    int num2=(rand()%5);
    switch(num2){
        case 0:
            name=players[0].getName();
            break;
        case 1:
            name=players[1].getName();
            break;
        case 2:
            name=players[2].getName();
            break;
        case 3:
            name=players[3].getName();
            break;
        case 4:
            name=players[4].getName();
            break;
    }
    cout<<"Oh no "<<name<<" has "<<disease<<endl; 
    //What happens 
    int medKits=resource.getMed();
    if(medKits>=1){
        int dead=(rand()%2+1);
        if(dead==1){
            players[num].setStatus(false);
            cout<<"Despite using a medkit "<<name<<" has died from "<<disease<<endl;
        }else{
            players[num].setStatus(true);
            cout<<"The medkit helped "<<name<<" recover from "<<disease<<" and is now healthy"<<endl;
        }
        medKits--;
    }else{
        int choice;
        cout<<"You have no medkits would you like to"<<endl;
        cout<<"1)REST"<<endl<<"OR"<<endl<<"2)PRESS ON";
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either 1 or 2";
            cout<<"1)REST"<<endl<<"OR"<<endl<<"2)PRESS ON";
            cin>>choice;
        }
        if(choice==1){
            int dead=(rand()%3+1);
            int numPlayers=0;
                for(int i=0; i<4; i++){
                    if(players[i].getStatus()==true){
                        numPlayers++;
                    }
                }
            resource.setFood(resource.getFood()-((numPlayers*3)*num));
            if(dead==1){
                players[num].setStatus(false);
                cout<<"Despite resting for 3 days"<<name<<" has died from "<<disease<<endl;
            }else{
                players[num].setStatus(true);
                cout<<"Resting helped "<<name<<" recover from "<<disease<<" and is now healthy"<<endl;
            }
        }else if(choice==2){
            int dead=(rand()%10+1);
            if(dead<=7){
                players[num].setStatus(false);
                cout<<"Pressing on caused "<<name<<"'s condition to worsen resulting in them dying from "<<disease<<endl;
            }else{
                players[num].setStatus(true);
                cout<<"Pressing on has paid off becuase "<<name<<" has recovered from "<<disease<<" and is now healthy";
            }
        }
    }
    //check to see if the leader has died 
    if(leader==true){
        if(players[num].getStatus()==false){
            cout<<"Unfortunantly you have died of "<<disease<<endl;
            //print final stats 
        }
    }
}

int main(){
    Players players[4];
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

    Resources resource=Resources(794,29,927,3,0,4);

    Date date=Date(29,7,1847,123);

    illness(players,resource,date);
    illness(players,resource,date);
}