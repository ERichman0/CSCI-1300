#include <iostream>
#include <iomanip>
using namespace std; 

void printNormalHeartRates(string names[], int hr[], int numElements){
    for(int i=0; i<numElements; i++){
        if(hr[i]>=70&&hr[i]<=190){
            cout<<names[i]<<" "<<hr[i]<<endl;
        }
    }
}