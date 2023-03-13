#include <iostream>
#include <iomanip>
using namespace std; 

int insert(int arr[], int numElements, int size, int newElement);

int main(){
    
}
int insert(int arr[], int numElements, int size, int newElement){
    int pos;
    if(size<=numElements){
        return numElements;
    }
    for(int i=0; i<numElements; i++){
        if(arr[i]>newElement){
           pos=i; 
           cout<<pos<<endl;
        }
    }
    for(int i=numElements; i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=newElement;
    return numElements; 
}