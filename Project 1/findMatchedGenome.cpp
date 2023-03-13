#include <iostream>
#include <iomanip>
using namespace std; 

void findMatchedGenome(string genome1, string genome2, string genome3, string sequence);//declare function 

int main(){
    string genome1;//initialize string variable
    cin>>genome1;//assign variable
    string genome2;//initialize string variable
    cin>>genome2;//assign variable
    string genome3;//initialize string variable
    cin>>genome3;//assign variable
    string sequence;//initialize string variable
    cin>>sequence;//assign variable
    findMatchedGenome(genome1,genome2,genome3,sequence);//call function 
}
void findMatchedGenome(string genome1, string genome2, string genome3, string sequence){//declare variable 
    //initalze variables 
    double g1Length=genome1.length();
    double g2Length=genome2.length();
    double g3Length=genome3.length();
    double g1SimScore;
    double g1FinalSimScore;
    double g2SimScore;
    double g2FinalSimScore;
    double g3SimScore;
    double g3FinalSimScore;
    double hamming_distance;
    double sequenceLength=sequence.length();
    if(genome1==""||genome2==""||genome3==""||sequence==""){//check to see if any of the strings are empty
        cout<<"Genomes or sequence is empty."<<endl;
        return;
    }
    if(g1Length!=g2Length||g1Length!=g3Length||g2Length!=g3Length){//check to see if any of the string lengths are not equal
        cout<<"Lengths of genomes are different."<<endl;
        return;
    }
    for(int i=0; i<g1Length-1; i++){//calculate sim score for genome1
        string s1=genome1.substr(i,sequenceLength);//initalize substring 
        for(int j=0; j<=sequenceLength; j++){//check to see if values of genome1 and the sequence are equal 
            if(sequence[j]!=s1[j]){//if not
                hamming_distance++;//add 1 to hammin distance 
            }
        } 
        g1SimScore=(sequenceLength-hamming_distance)/sequenceLength; //calculate sim score 
        hamming_distance=0;//set hamming distance value equal to 0
        if(g1SimScore>g1FinalSimScore){//check to see if the sim score is greater than the previous largest sim score
            g1FinalSimScore=g1SimScore;//if so set it equal to the final score 
        }
    }
    

    for(int i=0; i<g2Length-1; i++){//calculate sim score for genome2 using the same process as genome1 
        string s1=genome2.substr(i,sequenceLength);
        for(int j=0; j<=sequenceLength; j++){
            if(sequence[j]!=s1[j]){
                hamming_distance++;
            }
        }
        g2SimScore=(sequenceLength-hamming_distance)/sequenceLength; 
        hamming_distance=0;
        if(g2SimScore>g2FinalSimScore){
            g2FinalSimScore=g2SimScore;
        }
    }


     for(int i=0; i<g3Length-1; i++){//calculate sim score for genome3 using the same proccess as genome 1 and 2 
        string s1=genome3.substr(i,sequenceLength);
        for(int j=0; j<=sequenceLength; j++){
            if(sequence[j]!=s1[j]){
                hamming_distance++;
            }
        } 
        g3SimScore=(sequenceLength-hamming_distance)/sequenceLength; 
        hamming_distance=0;
        if(g3SimScore>g3FinalSimScore){
            g3FinalSimScore=g3SimScore;
        }  
    }
    //check to see which genome was the best 
    if(g1FinalSimScore>g2FinalSimScore&&g1FinalSimScore>g3FinalSimScore){
        cout<<"Genome 1 is the best match."<<endl;
    }
    if(g2FinalSimScore>g1FinalSimScore&&g2FinalSimScore>g3FinalSimScore){
        cout<<"Genome 2 is the best match."<<endl;
    }
    if(g3FinalSimScore>g1FinalSimScore&&g3FinalSimScore>g2FinalSimScore){
        cout<<"Genome 3 is the best match."<<endl;
    }
    if(g1FinalSimScore>g3FinalSimScore&&g1FinalSimScore==g2FinalSimScore){
        cout<<"Genome 1 is the best match."<<endl<<"Genome 2 is the best match.";
    }
    if(g2FinalSimScore>g1FinalSimScore&&g2FinalSimScore==g3FinalSimScore){
       cout<<"Genome 2 is the best match."<<endl<<"Genome 3 is the best match."; 
    }
    if(g1FinalSimScore>g2FinalSimScore&&g1FinalSimScore==g3FinalSimScore){
        cout<<"Genome 1 is the best match."<<endl<<"Genome 3 is the best match.";
    }
    if(g1FinalSimScore==g2FinalSimScore&&g2FinalSimScore==g3FinalSimScore){
        cout<<"Genome 1 is the best match."<<endl<<"Genome 2 is the best match."<<endl<<"Genome 3 is the best match.";
    }
}