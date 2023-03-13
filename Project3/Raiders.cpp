#include "Resources.h"
#include "Distance.h"
#include <iostream> 
#include <string>

using namespace std; 

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


int main(){
    Distance distance=Distance(623, 77, "Chimney Rock");
    Resources resource=Resources(794,29,927,3,2,4);
    cout<<probRaider(distance)<<endl;
    raiderAttack(resource);
}