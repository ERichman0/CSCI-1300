#include <iostream>
#include <iomanip>
using namespace std; 

bool isVowel(char a);//declare function

int main(){
    char a;//initialize variable
    cin>>a;//assign variable
    cout<<isVowel(a)<<endl;//print out out of fucntion isVowel with paramater 'a'
}
bool isVowel(char a){//declare function
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){//if variable a equals any vowel upper or lower case
        return true;//return true
    }else{//any other letter
        return false;//return false 
    }
}