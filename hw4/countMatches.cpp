#include <iostream>
#include <iomanip>
using namespace std; 

int main(){
    string input="";
    cout<<"Enter the search string:"<<endl;
    cin>>input;
    string search="";
    cout<<"Enter the substring to be searched:"<<endl;
    cin>>search;
    int matches=0;
    int lengthInput=input.length();
    int lengthSearch=search.length();

    for(int i=0; i<lengthInput; i++){
        string chunk=input.substr(i, lengthSearch);
        if(chunk==search){
            matches++;
        }
    } 
    cout<<"Number of occurences: "<<matches<<endl;
}
