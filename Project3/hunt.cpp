#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include "Distance.h"
#include <iostream>
#include <string>
#include <fstream>

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

Resources hunt(Resources resource, Date date, Players player[]){
    int choice=0;
    cout<<"While you are hunting be on the lookout for animals such as rabbit, fox, deer, bear and moose"<<endl;
    //Hunting a rabbit 
    int rabbit=(rand()%2+1);
    if(rabbit==1){
        cout<<"You have encountered a rabbit! Do you want to hunt?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either a 1 or a 2 based on what you would like to do"<<endl;
            cin>>choice;
        }
        if(choice==1){
            if(resource.getBullets()<=10){
                cout<<"You do not have enough bullets to hunt"<<endl;
            }else if(resource.getBullets()>10){
                cout<<"To succsessfully hunt the animal you must solve a puzzle"<<endl;
                if(puzzle()==true){
                    cout<<"Congrats you have sucessfully completed the hunt. You have gained 5 lbs. of food but lost 10 bullets"<<endl;
                    resource.setFood(resource.getFood()+5);
                    resource.setBullets(resource.getBullets()-10);
                }else{
                    cout<<"You failed the hunt"<<endl;
                }
            }
        }else{
            cout<<"You choose to not hunt the animal"<<endl;
        }
    }
    //Hunt a fox
    int fox=(rand()%4+1);
    if(fox==1){
        cout<<"You have encountered a fox! Do you want to hunt?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either a 1 or a 2 based on what you would like to do"<<endl;
            cin>>choice;
        }       
        if(choice==1){
            if(resource.getBullets()<=10){
                cout<<"You do not have enough bullets to hunt"<<endl;
            }else if(resource.getBullets()>10){
                cout<<"To succsessfully hunt the animal you must solve a puzzle"<<endl;
                if(puzzle()==true){
                    cout<<"Congrats you have sucessfully completed the hunt. You have gained 10 lbs. of food but lost 8 bullets"<<endl;
                    resource.setFood(resource.getFood()+10);
                    resource.setBullets(resource.getBullets()-8);
                }else{
                    cout<<"You failed the hunt"<<endl;
                }
            }
        }else{
            cout<<"You choose to not hunt the animal"<<endl;
        }
    }
    //Hunt a Deer
    int deer=(rand()%20+1);
    if(deer<=3){
        cout<<"You have encountered a deer! Do you want to hunt?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either a 1 or a 2 based on what you would like to do"<<endl;
            cin>>choice;
        }
        if(choice==1){
            if(resource.getBullets()<=10){
                cout<<"You do not have enough bullets to hunt"<<endl;
            }else if(resource.getBullets()>10){
                cout<<"To succsessfully hunt the animal you must solve a puzzle"<<endl;
                if(puzzle()==true){
                    cout<<"Congrats you have sucessfully completed the hunt. You have gained 60 lbs. of food but lost 5 bullets"<<endl;
                    resource.setFood(resource.getFood()+60);
                    resource.setBullets(resource.getBullets()-5);
                }else{
                    cout<<"You failed the hunt"<<endl;
                }
            }
        }else{
            cout<<"You choose to not hunt the animal"<<endl;
        }
    }
    //Hunt a bear 
    int bear=(rand()%100+1);
    if(bear<=7){
        cout<<"You have encountered a bear! Do you want to hunt?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either a 1 or a 2 based on what you would like to do"<<endl;
            cin>>choice;
        }
        if(choice==1){
            if(resource.getBullets()<=10){
                cout<<"You do not have enough bullets to hunt"<<endl;
            }else if(resource.getBullets()>10){
                cout<<"To succsessfully hunt the animal you must solve a puzzle"<<endl;
                if(puzzle()==true){
                    cout<<"Congrats you have sucessfully completed the hunt. You have gained 200 lbs. of food but lost 10 bullets"<<endl;
                    resource.setFood(resource.getFood()+200);
                    resource.setBullets(resource.getBullets()-10);
                }else{
                    cout<<"You failed the hunt"<<endl;
                }
            }
        }else{
            cout<<"You choose to not hunt the animal"<<endl;
        }
    }
    //Hunt a Moose
    int moose=(rand()%100+1);
    if(moose<=5){
        cout<<"You have encountered a moose! Do you want to hunt?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
        cin>>choice;
        if(choice!=1&&choice!=2){
            cout<<"Please enter either a 1 or a 2 based on what you would like to do"<<endl;
            cin>>choice;
        }
        if(choice==1){
            if(resource.getBullets()<=10){
                cout<<"You do not have enough bullets to hunt"<<endl;
            }else if(resource.getBullets()>10){
                cout<<"To succsessfully hunt the animal you must solve a puzzle"<<endl;
                if(puzzle()==true){
                    cout<<"Congrats you have sucessfully completed the hunt. You have gained 500 lbs. of food but lost 12 bullets"<<endl;
                    resource.setFood(resource.getFood()+500);
                    resource.setBullets(resource.getBullets()-12);
                }else{
                    cout<<"You failed the hunt"<<endl;
                }
            }
        }else{
            cout<<"You choose to not hunt the animal"<<endl;
        }
    }
    //Found no animals 
    if(rabbit!=1&&fox!=1&&deer>3&&bear>7&&moose>5){
        cout<<"Unfortunantly you did not find an animal while you were hunting"<<endl;
    }
    //How well they want to eat 
    cout<<"Your day of hunting is complete now it is time to decide how well you want to eat"<<endl;
    cout<<"1)Poorly(2 lbs. per person)"<<endl<<"2)Moderatly(3 lbs. per person)"<<endl<<"3)Well(5 lbs. per person"<<endl;
    cin>>choice;
    if(choice!=1&&choice!=2&&choice!=3){
        cout<<"Please enter either a 1,2 or 3"<<endl;
        cin>>choice;
    }else{
        int numPlayers=0;
            for(int i=0; i<4; i++){
                if(player[i].getStatus()==true){
                    numPlayers++;
                }
            }
        switch(choice){
            case 1:
                resource.setFood(resource.getFood()-(numPlayers*2));
                break; 
            case 2: 
                resource.setFood(resource.getFood()-(numPlayers*3));
                break;
            case 3:
                resource.setFood(resource.getFood()-(numPlayers*5));
                break;
        }
        if(resource.getFood()<=0){
            cout<<"You have run out of food and your journey has come to an end"<<endl;
            //gameover function
        }
        if(resource.getFood()>1000){
            int leftOvers=(resource.getFood()-1000);
            resource.setFood(resource.getFood()-leftOvers);
            cout<<"Unfortunantly you had to leave "<<leftOvers<<" lbs. of food behind because you could not fit it in your wagon"<<endl; 
        }
    }
    date.setDay(date.getDay()+1);
    return resource;
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
    hunt(resources,date,players);
    hunt(resources,date,players);
}