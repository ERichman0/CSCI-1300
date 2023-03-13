#include <iostream>
#include <cstdlib>

using namespace std;

bool ifMisfortune(){
    int num=(rand()%5+1);
    if(num==1||num==2){
        return true;
        num=0;
    }else{
        return false;
        num=0;
    }
}

int main(){
    //cout<<ifMisfortune()<<endl;
    ifMisfortune();
}