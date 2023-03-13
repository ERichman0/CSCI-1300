#include <iostream> 
using namespace std; 

int main(){
    int num;
    double agility; 
    double speed; 
    double strength;
    double hirescore; 
    while(num != 4){
        cout<<"Select a numerical option:"<<endl;
        cout<<"=== menu ==="<<endl<<"1. Fox"<<endl<<"2. Bunny"<<endl<<"3. Sloth"<<endl<<"4. Quit"<<endl;
        cin>>num;
        if(num>4||num<=0){
            cout<<"Invalid option"<<endl; 
        }
        switch(num){
            case 1:
                cout<<"Enter agility:"<<endl;
                cin>>agility;
                cout<<"Enter strength:"<<endl;
                cin>>strength;
                hirescore=(1.8*agility)+(2.16*strength);
                cout<<"Hire Score: "<<hirescore<<endl;
                break; 
            case 2:
                cout<<"Enter agility:"<<endl;
                cin>>agility;
                cout<<"Enter speed:"<<endl;
                cin>>speed;
                hirescore=(1.8*agility)+(3.24*speed);
                cout<<"Hire Score: "<<hirescore<<endl;
                break;
            case 3: 
                cout<<"Enter strength:"<<endl;
                cin>>strength;
                cout<<"Enter speed:"<<endl;
                cin>>speed;  
                hirescore=(2.16*strength)+(3.24*speed);
                cout<<"Hire Score: "<<hirescore<<endl;
                break;
            case 4:
                cout<<"Good bye!"<<endl; 
                break;
        }
    }
}