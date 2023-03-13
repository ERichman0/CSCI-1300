#include <iostream>
#include <iomanip>
using namespace std; 

void naturalDiagonal(int num){
  for(int i=1; i <= num ; i++){ 
     for (int j=1; j <= num; j++){
         if(i != j) 
         {
            cout << i;
         }
         else 
         {
            cout << "*";
         }
     }
     cout<<"\n"; 
  }
}

int main(){
    int num;
    cin>>num;
    naturalDiagonal(num);
}
