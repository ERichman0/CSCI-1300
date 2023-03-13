#include <iostream>
#include <iomanip>
using namespace std; 

int CountUpper(string s){
    int numUpper=0;
    if(s==""){
        return -1;
    }
    string sub1=s.substr(0,s.length());
    for(int i=0; i<s.length(); i++){
        if(isupper(sub1[i])){
            numUpper++;
        }
    }
    if(numUpper==0){
        return -2;
    }
    return numUpper;
}

int main(){
    string s;
    cin>>s;
    cout<<CountUpper(s);
}