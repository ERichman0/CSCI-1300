// CS1300 Fall 2020
// Author: Ethan Richman & KC Yenza
// Recitation: 213 – Julia Romero
// Project 3

#include "Players.h"
#include "Resources.h"
#include "Date.h"
#include "Distance.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Puzzle function
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

//Gameover function
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

//Satus Update function 
void statusUpdate(Resources resource , Date date, Distance distance){
    cout<<date.getMonth()<<"/"<<date.getDay()<<"/"<<date.getYear()<<endl;
    cout<<"You have traveled "<<distance.getMT()<<" miles."<<endl;
    cout<<"You have "<<distance.getDtMS()<<" miles left till the next milestone."<<endl;
    cout<<"You currently have "<<resource.getFood()<<" lbs. of food left."<<endl;
    cout<<"You currently have "<<resource.getBullets()<<" bullets left."<<endl;
    cout<<"And you currently have a balance of "<<resource.getCash()<<" $."<<endl;
}

//Store Functions
void oxenCount(double yokes, double oxenTotal, Resources resource)

{
    Resources cash;
    Resources oxen;

  if (resource.getCash()-(yokes*40)>resource.getCash())
  {
      cout<<"You don't have suffiecient funds to purchase this item"<<endl;
  }
  

    else if (yokes<3||yokes>5)
    {
        cout<<"You must purchase between 3-5 yokes of oxen"<<endl;
    }

    
    
    else
    {
        oxenTotal=yokes*40;
        
      cout<<"You have "<<resource.getCash()-oxenTotal<<" $ left."<<endl; 
    
}

}

void foodCount(double foodPounds, double foodTotal, Resources resource)

{
    Resources cash;
    Resources food;
    double currentFood;

    if (resource.getCash()-foodTotal>resource.getCash())
    {
        cout<<"You don't have suffiecient funds to purchase this item"<<endl;
    }

    else 
    {
    foodTotal= .5*foodPounds;
    resource.setFood(resource.getFood()+foodPounds);
    currentFood=food.getFood();
    cash.setCash(resource.getCash()-foodTotal);
    cout<< "You have "<<resource.getCash()-foodTotal<<" $ left."<<endl;

    }
    
}

void Bullets( double bulletBoxes, double bulletTotal, Resources resource)

{
    Resources cash;
    Resources bullets;
    double currentCash;
    double currentBullets;

if (resource.getCash()-bulletTotal>resource.getCash())
{
    cout<<"You don't have suffiecient funds to purchase this item"<<endl;
}
else
{
    bulletTotal=bulletBoxes*2;

    resource.setBullets(resource.getBullets()+(bulletBoxes*20));
    currentBullets=bullets.getBullets();
    resource.setCash(resource.getCash()-bulletTotal);
    cout<<"You have "<<(resource.getCash()-bulletTotal)<<" $ left."<<endl;
    
}

}

void countMisc(double medKits, double totalParts, double total, Resources resource)
 {
    Resources cash;
    Resources med;
    Resources parts;
    double currentCash;
    double currentMed;
    double currentParts;

if (resource.getCash()-total>resource.getCash())
{
    cout<<"You don't have suffiecient funds to purchase this item"<<endl;
}
   
 else
    
 {

    total=(medKits*25)+(totalParts*20);

    resource.setMed(resource.getMed()+medKits);
    resource.setParts(resource.getParts()+totalParts);
    resource.setCash(resource.getCash()-total);
      cout<< "You have "<<resource.getCash()-total<<" $ left."<<endl;
      
}


 }

//Turn function
Resources rest(Resources resource, Date date, Players player[]){
    int num=(rand()%3+1);
    cout<<"You have chosen to rest. You will rest for "<<num<<" days";
    int numPlayers=0;
    for(int i=0; i<4; i++){
        if(player[i].getStatus()==true){
            numPlayers++;
        }
    }
    resource.setFood(resource.getFood()-((numPlayers*3)*num));
    date.setDay(date.getDay()+num);
    return resource;
}

Resources Continue(Resources resource, Date date, Players player[],Distance distance){
    cout<<"You have decided to continue on your journey. You will travel for 2 weeks."<<endl;
    //set the new date after they travel
    date.setDay(date.getDay()+14);
    //calculate amount of food eaten 
    int numPlayers=0;
    for(int i=0; i<4; i++){
        if(player[i].getStatus()==true){
            numPlayers++;
        }
    }
    resource.setFood(resource.getFood()-((numPlayers*3)*14));
    //check to see if the food is gone
    if(resource.getFood()<=0){
        cout<<"While you were traveling you ran out of food and your journey is over"<<endl;
        gameOver(player,resource,distance);
    }
    //find how many miles you traveled 
    int milesTraveled=(rand()%(140-70+1)+70);
    //add to total miles
    distance.setMT(distance.getMT()+milesTraveled);
    //check to see if a milestone is going to be passed
    return resource;
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

Resources turn(Resources resource, Date date, Players player[],Distance distance){
    //Status update function 
    int choice=0;
    cout<<"What would you like to do?"<<endl;
    cout<<"1)Rest"<<endl<<"2)Continue"<<endl<<"3)Hunt"<<endl<<"4)Quit"<<endl;
    cin>>choice;
    if(choice<1&&choice>4){
        cout<<"Please enter either a 1,2,3 or 4"<<endl;
        cin>>choice; 
    }else{
        switch(choice){
            case 1:
                rest(resource,date,player);
                break;
            case 2:
                Continue(resource,date,player,distance);
                break;
            case 3:
                hunt(resource,date,player); 
                break;
            case 4:
                cout<<"It's a shame you are cutting your journey short but the Oregon Trail is truly not meant for everyone."<<endl;
                gameOver(player,resource,distance);
                break; 
        }
    }
    return resource;
}

//Misfortune functions
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

Resources raiderAttack(Resources resource, Players player[], Distance distance){
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
                gameOver(player,resource,distance);
            }else if(food==0){
                cout<<"You have run out of food. Your journey is over"<<endl;
                gameOver(player,resource,distance);
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
    return resource;
}

void illness(Players players[], Resources resource, Distance distance){//take in array of Players
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
            gameOver(players,resource,distance);
        }
    }
}

Resources deadOxen(Resources resource,Players player[], Distance distance){
    int oxen=resource.getOxen();
    if(oxen>1){
        cout<<"Oh no! One of the oxen has died! You have "<<(oxen-1)<<" oxen left"<<endl; 
        resource.setOxen(oxen-1);
    }else if(oxen==1){
        cout<<"Oh no! One of the oxen has died! You have no oxen left unfortunantly your jounrey is over"<<endl; 
        resource.setOxen(0);
        gameOver(player,resource,distance);
    }
    return resource;
}

Resources brokenWagon(Resources resource,Players player[], Distance distance){
    int wp=resource.getParts();
    if(wp>=1){
        cout<<"Oh no! Your wagon has broken!"<<endl; 
        resource.setParts(wp-1);
        cout<<"You fixed it by using one of your spare parts you now have "<<resource.getParts()<<" wagon parts left"<<endl;
    }else if(wp==0){
        cout<<"Oh no! Your wagon has broken! You have no more wagon parts left unfortunantly your jounrey is over"<<endl; 
        resource.setParts(0);
        gameOver(player,resource,distance);
    }
    return resource;
}

Resources misfortune(Distance distance, Resources resource, Players players[]){
    if(probRaider(distance)==true){
        raiderAttack(resource,players,distance);
    }else{
        int num=(rand()%3+1);
        switch(num){
            case 1:
                illness(players,resource,distance);
                break;
            case 2:
                deadOxen(resource,players,distance);
                break;
            case 3:
                brokenWagon(resource,players,distance);
                break;
        }
    }
    return resource;
}

//Main function
int main(){
    //Setting the initial conditions 
    Players player[5];
    string leaderName="";
    cout<<"So you have decided to lead a journey across the Oregon Trail please enter your name brave adventurer:"<<endl;
    cin>>leaderName;
    player[0].setName(leaderName);
    player[0].setStatus(true);
    player[0].setLeader(true);
    string playerName="";
    cout<<"Now please enter the names of the 4 others that will be traveling with you"<<endl;
    for(int i=0;i<4;i++){
        cin>>playerName;
        player[i+1].setName(playerName);
        player[i+1].setStatus(true);
        player[i+1].setLeader(false);
    }
    cout<<"You party starts with $1600 and a wagon, you can spend your money at the store and at forts along the trail"<<endl;
    Resources resource=Resources(0,0,1600,0,0,0);
    Distance distance=Distance(0,102,"Kansas River Crossing");
    Date date=Date();
    int choice=0;
    cout<<"Would you like to start your journey on 03/28/1847?"<<endl<<"1)Yes"<<endl<<"2)No"<<endl;
    cin>>choice;
    if(choice!=1&&choice!=2){
        cout<<"Please enter either a 1 or 2"<<endl;
        cin>>choice;
    }else{
        if(choice==1){
            cout<<"Great! Prepare to embark on your journey 03/28/1847"<<endl;
            date.setMonth(3);
            date.setDay(28);
            date.setYear(1847);
        }else{
            int month=0;
            int day=0;
            cout<<"Please enter a month between 3 and 5"<<endl;
            cin>>month;
            if(month<3||month>5){
                cout<<"Please choose a starting month between 3 and 5"<<endl;
                cin>>month;
            }else{
                date.setMonth(month);
            }
            cout<<"Please enter a day between 1 and 31"<<endl;
            cin>>day;
            if(day<1||day>31){
                cout<<"Please enter a day between 1 and 31"<<endl;
                cin>>day;
            }else{
                date.setDay(day);
            }
            cout<<"You have decided to start your journey on "<<month<<"/"<<day<<"/1847"<<endl;
        }
    }

    //Call to store function
    double yokes=0;
    double oxenTotal=0;
    double foodPounds=0;
    double foodTotal=0;
    double bulletBoxes=0;
    double bulletTotal=0;
    double medKits=0;
    double parts=0;
    double total=0;
    double currentCash=0;
    double currentFood=0;
    double currentOxen=0;
    double currentMed=0;
    double currentParts=0;
    double currentBullets=0;
    int option=0;
    cout<<"YOU HAD SAVED $1600 TO SPEND FOR THE TRIP, AND YOU HAVE A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:"<<endl;
    cout<<"- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS. - FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK."<<endl;
    cout<<"- AMMUNITION. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD."<<endl;
    cout<<"- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS."<<endl;
    cout<<"YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD."<<endl;
    cout<< "Please select a numerical option to purchase items."<<endl;

    do{
    cout << "======Store=====" << endl;
    cout << "1. Oxen" << endl;
    cout << "2. Food" << endl;
    cout << "3. Ammunition" << endl;
    cout << "4. Miscellaneous Supplies (Wagon Parts and Med Kits" << endl;
    cout << "5. Leave" << endl;
    cin>>option;


    switch (option)
    {

    case 1:
    { 
        cout<<"You must spend between $100-$200 inclusively on oxen."<<endl;
        cout<<"There are 2 oxen in a yoke and the price of each yoke is $40."<<endl;
        cout<<"How many yokes would you like to purchase?"<<endl;
        cin>>yokes;

        if (resource.getCash()-oxenTotal>resource.getCash())
        {
            cout<<"You don't have suffiecient funds to purchase this item"<<endl;
        }

        else 
        resource.setOxen(resource.getOxen()+(yokes*2));
        {
        
        oxenCount(yokes,oxenTotal,resource);
    

    }
    break;
    }

    case 2:
    {
    cout<<"It's recommended that you purchase 200 lbs of food per person. Each pound of food costs .50$."<<endl;
    cout<<"How many pounds of food would you like to purchase today?"<<endl;
    cin>>foodPounds;
    foodCount(foodPounds, foodTotal, resource);
    resource.setFood(resource.getFood()+foodPounds);
    
    break;
    }

    case 3:
    {
    cout<<"You'll need bullets for hunting along the way"<<endl;
    cout<<"There are 20 bullets per box."<<endl;
    cout<<"How many boxes would you like to purchase?"<<endl;
    cin>>bulletBoxes;
    resource.setBullets(resource.getBullets()+(bulletBoxes*20));
    Bullets(bulletBoxes, bulletTotal, resource);
    break;
    }

    case 4:{

    cout<<"A wagon part (wheels, axles, tongues) costs $20. If the wagon breaks along the way, any wagon parts will be used to fix it."<<endl;
    cout<<"How many parts would you like to purchase?"<<endl;
    cin>>parts;
    cout<<"A med kit costs 25$"<<endl;
    cout<<"How many med kits would you like to purchase?"<<endl;
    cin>>medKits;
    resource.setMed(resource.getMed()+medKits);
    resource.setParts(resource.getParts()+parts);
    countMisc(medKits, parts, total, resource);

    break;
    }
    case 5:{

    cout<<"Thank you for your purchase! Good luck!"<<endl;

    break;
    }

    default:{
    cout << "Invalid input. Please select a numerical option to purchase item." << endl;
    break;
    }
    }

    }while (option<5&&option>=1);

    //Loop to keep turns going while the game is still going
    while(distance.getMT()<2040){
        //Call to status update function
        statusUpdate(resource,date,distance);
        //Call to turns function
        resource=turn(resource, date, player,distance);

        //See if a misfortune happens 
        if(ifMisfortune()==true){
            //Calls the misfortune function if it's true
            resource=misfortune(distance, resource, player);
        }
    }
}