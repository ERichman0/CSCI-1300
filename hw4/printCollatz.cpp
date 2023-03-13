#include <iostream> 
using namespace std; 

int main(){
    int num;
    cout<<"Enter a positive number:"<<endl;
    cin>>num;
    cout<<num<<endl;
    while(num>1){
        if(num%2==0){
            num=num/2;
            cout<<num<<endl;
        }else{
            num=(3*num)+1;
            cout<<num<<endl;
        }
    }
}