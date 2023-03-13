#include <iostream>
#include <iomanip>
using namespace std; 

double findBestSimScore(string genome, string sequence);//declare function

int main(){
    string genome;//initialize string
    cin>>genome;//assign value
    string sequence;//initialize string
    cin>>sequence;//assign value
    cout<<fixed<<setprecision(2)<<findBestSimScore(genome, sequence)<<endl;//print out put of the function to a value of 2
}
double findBestSimScore(string genome, string sequence){//declare variable 
    double genomeLength=genome.length();//initalize variable to hold the length of the genome
    double sequenceLength=sequence.length();//initialize variable to hold the length of the sequence 
    double hamming_distance;//initialize variable to hole hamming distance 
    double similarity_score=0;//initialize similarity score variable
    double finalSimScore=0;//initialize the final similarity score variable to return
    if(genomeLength<sequenceLength){//if the genome is longer than the sequence return 0
        return 0;
    }
    if(genomeLength==sequenceLength){//if the genome length equals the sequence length 
        for(int i=0; i<=genomeLength-1; i++){//for loop while i is less than or equal to the length of the genome minus 1 
            string s1=genome.substr(0,sequenceLength);//initialize the substring to hold the part of the genome you are compating 
            if(sequence[i]!=s1[i]){//check to see if the char values are equal if not 
                hamming_distance++;//add 1 to hamming distance 
            }
            similarity_score=(sequenceLength-hamming_distance)/sequenceLength;//calculate similarity score 
        }
        return similarity_score;//return the similarity score
    }
    for(int i=0; i<genomeLength-((genomeLength-sequence)+1); i++){//for loop while i is less than the length of the genome minus 2 
        string s1=genome.substr(i,sequenceLength);//initialize substring 
        for(int j=0; j<=sequenceLength; j++){//for loop to compare the substring values to the genome value
            if(sequence[j]!=s1[j]){//if they are not equal 
                hamming_distance++;//add 1 to hamming distance 
            }
        }
        similarity_score=(sequenceLength-hamming_distance)/sequenceLength;//calculate similarity score
        hamming_distance=0;//set the hamming distance equal to 0
        if(similarity_score>finalSimScore){//if the similarity score of the recently calcualted similarity score is greater than the previous largest 
            finalSimScore=similarity_score;//set it equal to the final sim score
        }
    }
    return finalSimScore; //return final similarity score 
}
