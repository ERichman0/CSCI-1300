#include <iostream>
using namespace std; 

int main(){
    int suit;
    cout<<"Enter Suit:"<<endl;
    cin>>suit;
    switch(suit){
    case -2:
        cout<<"Suit "<<suit<<": Invalid"<<endl;
        break;
    case 0:
        cout<<"Suit 0: Clubs"<<endl;
        break;
    case 1:
        cout<<"Suit 1: Diamonds"<<endl;
        break;
    case 2:
        cout<<"Suit 2: Spades"<<endl;
        break;
    case 3: 
        cout<<"Suit 3: Hearts"<<endl;
        break;
    }
}