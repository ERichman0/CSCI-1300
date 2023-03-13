#include <iostream> 
using namespace std; 

int main(){
    int num;
    int total=0;
    cout<<"Enter a positive number:"<<endl;
    cin>>num;
    for(int i=0; i<=num; i++){
        if(i%2==0){
            total=total+i;
        } 
    }
    cout<<"Sum: "<<total<<endl; 
}