#include <iostream>
#include <iomanip>
using namespace std; 

void reverse(string s);//initizalize function 

int main(){
    string input="";//initialize string variable
    cin>>input;//assign variable
    cout<<input<<endl;//print input
    reverse(input);//call reverse function with paramater 
}
    void reverse(string s){
        int length = s.length();//declare variable that holds the length of the paramter 
        for(int i=length-1; i>=0; i--){//for the length of the string after every turn decrease 1
            cout<<s[i];//print the new string 
        }
    }
