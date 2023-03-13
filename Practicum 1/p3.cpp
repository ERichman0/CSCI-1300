#include <iostream>
using namespace std; 

int main(){
    double num1;
    double num2;
    double num3;
    cout<<"Enter first number:"<<endl;
    cin>>num1;
    cout<<"Enter second number:"<<endl;
    cin>>num2;
    cout<<"Enter third number:"<<endl;
    cin>>num3;
    if (num1>num2){
        if(num1>num3){
            cout<<"The largest number is "<<num1<<endl;
        }else{
            cout<<"The largest number is "<<num3<<endl;
        }    
    }else{
        if(num2>num3){
            cout<<"The largest number is "<<num2<<endl;
        }else{
            cout<<"The largest number is "<<num3<<endl;
        }
    }
}