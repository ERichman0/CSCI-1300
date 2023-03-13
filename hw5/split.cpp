#include <iostream>
#include <iomanip>
using namespace std; 

int split(string s1, char separator,string arr[],int numPieces);

int main(){
    
}
int split(string s1, char separator,string arr[],int numPieces){
    string s2=s1.substr(0,s1.length());
    for(int i=0; i<s2.length(); i++){
        if(s2[i]==separator){
            arr[i]=s2[0,i];
            numPieces++;
        }
    }
    return numPieces;
}