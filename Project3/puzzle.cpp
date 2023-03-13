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
