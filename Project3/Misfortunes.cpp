#include "Resources.h"
#include "Distance.h"
#include "Players.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

bool ifMisfortune(){
    int num=(rand()%5+1);
    if(num==1||num==2){
        return true;
        num=0;
    }else{
        return false;
        num=0;
    }
}

bool probRaider(Distance distance){
    int num=(rand()%(50+5));
    int distanceTraveled=distance.getMT();
    int raiderAttack=0;
    raiderAttack=(((((distanceTraveled/100)-4)+72)/(((distanceTraveled/100)-4)+12))-1)/.1;
    if(num<=raiderAttack){
        return true;
    }else{
        return false; 
    }
}

bool puzzle(){
    int choice;
    int numTries=0; 
    int randNum=(rand()%10+1);
    cout<<"I have in my head a number from 1 to 10 in order to solve this puzzle you must guess what number I am thinking of in no more than 3 attempts:"<<endl;
    do{
        cin>>choice;
        if(choice<1||choice>10){
            cout<<"Please guess a number between 1 and 10, that guess will not be counted against you"<<endl;
            cout<<"Guess again:"<<endl;
            cin>>choice;
        }else{
            if(choice!=randNum){
                numTries++;
                if(numTries==3){
                    cout<<"You were not able to solve the puzzle! Better luck next time"<<endl;
                    return false;
                }else{
                    cout<<"So close but that is not correct you have "<<(3-numTries)<<" tries left"<<endl;
                    cout<<"Guess again:"<<endl;
                }
            }
            if(choice==randNum){
                cout<<"You are correct! Congratulations you have solved the puzzle"<<endl;
                return true;
            }
        }
    }while(numTries!=3);
    return 0; 
}

void raiderAttack(Resources resource){
    int choice=0;
    cout<<"Riders ahead! They look hostile!"<<endl;
    cout<<"You have 3 choices"<<endl<<"1)Run"<<endl<<"2)Attack"<<endl<<"3)Surrender"<<endl;
    cin>>choice;
    int oxen=(resource.getOxen()-1);
    int food=(resource.getFood()-10);
    int wp=(resource.getParts()-1);
    switch(choice){
        case 1:
            cout<<"You are able to escpae with your lives but you lost 1 ox, 10 lbs. of food, and 1 wagon part"<<endl;
            resource.setOxen(oxen);
            resource.setFood(food);
            resource.setParts(wp);
            if(oxen==0){
                cout<<"You have run out of oxen. Your journey is over"<<endl;
                //game over function
            }else if(food==0){
                cout<<"You have run out of food. Your journey is over"<<endl;
                //game over function
            }else if(wp==0){
                cout<<"You have run out of food. Your journey is over"<<endl;
            }
            break;
        case 2:
            cout<<"In order to win the battle you must pass this puzzle."<<endl;
            if(puzzle()==true){
                cout<<"Congrats you have defeated the raiders you have gained 50 lbs. of food, and 50 bullets"<<endl;
                resource.setBullets((resource.getBullets()+50));
                resource.setFood((resource.getFood())+50);
            }else{
                cout<<"The raiders have defeted you and have taken a quarter of your cash and 50 bullets"<<endl; 
                resource.setCash(resource.getCash()-(resource.getCash()*.25));
                resource.setBullets(resource.getBullets()-50);
            }
            break;
        case 3:
            cout<<"In the terms of your surrender you escape with your lives but give the raiders a quarter of your cash"<<endl;
            resource.setCash(resource.getCash()-(resource.getCash()*.25));
            break; 
    }
}

void illness(Players players[], Resources resource){//take in array of Players
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

void misfortune(Distance distance, Resources resource, Players players[]){
    if(probRaider(distance)==true){
        raiderAttack(resource);
    }else{
        int num=(rand()%3+1);
        switch(num){
            case 1:
                illness(players,resource);
                break;
            case 2:
                deadOxen(resource);
                break;
            case 3:
                brokenWagon(resource);
                break;
        }
    }
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
    if(ifMisfortune()==true){
        misfortune(distance, resources, players);
    }else{
        cout<<"No misfortune"<<endl;
        //continue game 
    }
}