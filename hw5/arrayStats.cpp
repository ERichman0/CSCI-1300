#include <iostream>
#include <iomanip>
using namespace std; 

void stats(double arr[], int numElements);

int main(){
    
}
void stats(double arr[], int numElements){
    double min=arr[0];
    double max=arr[0];
    double avg=0;
    double sum=0;
    for(int i=0; i<numElements; i++){
        if(arr[i]<min){
            min=arr[i];
        }else if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=0;i<numElements; i++){
        sum=sum+arr[i];
    }
    avg=sum/numElements;
    cout<<"Min: "<<fixed<<setprecision(2)<<min<<endl;
    cout<<"Max: "<<fixed<<setprecision(2)<<max<<endl;
    cout<<"Avg: "<<fixed<<setprecision(2)<<avg<<endl;
}