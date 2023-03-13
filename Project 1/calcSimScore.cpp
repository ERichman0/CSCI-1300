#include <iostream>
#include <iomanip>
using namespace std; 

double calcSimScore(string sequence1, string sequence2);//declare variable 

int main(){
    string sequence1;//initialize string variable
    cin>>sequence1;//assign variable
    string sequence2;//initialize string variable
    cin>>sequence2;//assign variable 
    cout<<calcSimScore(sequence1,sequence2)<<endl;//print the output of the function 
}
double calcSimScore(string sequence1, string sequence2){//declare variable
    double length1=sequence1.length();//initialize variable to hold the length value of sequence 1 
    double length2=sequence2.length();//initialize variable to hold the length value of sequence 2 
    double hamming_distance;//initialize variable to hold the hamming distance 
    if(length1!=length2||sequence1==""||sequence2==""){//check to see if the lengths are different or one of the paramaters was empty
        return 0.0;//return 0
    }else{//if both statements are false
        length1=length2;//set length1 to length2 
    }
    for(int i=0; i<length1; i++){//for loop that acts while i is less than the length of the sequence 
        if(sequence1[i]!=sequence2[i]){//add 1 to the hamming distance if the values of the string at value i is not the same 
            hamming_distance++;
        }
    }
    double similarity_score=(length1-hamming_distance)/length1;//calculate similarity score 
    return similarity_score;//return similarity score 
}