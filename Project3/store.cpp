#include "Resources.h"
#include "Distance.h"
#include "Players.h"
#include <string>
#include <cmath>
#include <iostream>
 
using namespace std;

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

int main()

{
    Resources resource;
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
    int option;

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
 
 break;
}

case 3:
{
cout<<"You'll need bullets for hunting along the way"<<endl;
cout<<"There are 20 bullets per box."<<endl;
cout<<"How many boxes would you like to purchase?"<<endl;
cin>>bulletBoxes;
    
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

}while (option!=5|| option>=1);

return 0;


}
