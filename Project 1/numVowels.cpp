#include <iostream>
#include <iomanip>
using namespace std; 

int numVowels(string s);//delcare function

int main(){
    string s;//initialize string
    cin>>s;//assign value 
    cout<<numVowels(s)<<endl;//print out put of function numVowels
}
int numVowels(string s){//declare function
    int num;//initialize variable
    int length=s.length();//initialize variable 
    for(int i=0; i<length; i++){//for loop while i is less than the length of string s 
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){//if there is a vowel in the string
            num++;//add 1 to num 
        }
    }
    return num;//return num 
}