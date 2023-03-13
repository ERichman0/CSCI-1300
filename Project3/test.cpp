//try to get a random number between 70 and 140

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    for(int i=0;i<10;i++){
        cout<<rand()%(140-70+1)+70<<endl;
    }
}