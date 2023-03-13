#include <iostream>
#include <iomanip>
using namespace std; 
//declare neccesary functions 
double calcSimScore(string sequence1, string sequence2);
double findBestSimScore(string genome, string sequence);
void findMatchedGenome(string genome1, string genome2, string genome3, string sequence);

int main(){
    //declare variables 
    int input;
    string sequence1;
    string sequence2;
    string genome;
    string sequence;
    string genome1;
    string genome2;
    string genome3;
    string sequence3;

    while(input!=4){//while the input does not equal 4
    //print menu
    cout<<"Select a numerical option:"<<endl<<"=== menu ==="<<endl<<"1. Find similarity score"<<endl<<"2. Find the best similarity score"<<endl<<"3. Analyze the genome sequences"<<endl<<"4. Quit"<<endl;
    cin>>input;//assign user input 
    if(input<0||input>4||input==0){//check to see if the value is in bounds
        cout<<"Invalid option."<<endl;//if not print invalid options
        //print menu again
        cout<<"Select a numerical option:"<<endl<<"=== menu ==="<<endl<<"1. Find similarity score"<<endl<<"2. Find the best similarity score"<<endl<<"3. Analyze the genome sequences"<<endl<<"4. Quit"<<endl;
        cin>>input;//assing user input
    }
        switch(input){//switch statment using the value of the input
            case 1://if 1 is equal to input 
                cout<<"Enter sequence 1:"<<endl;//prompt user to enter value
                cin>>sequence1;//assign value
                cout<<"Enter sequence 2:"<<endl;//prompt user to enter value 
                cin>>sequence2;//assign value
                cout<<"Similarity score: "<<calcSimScore(sequence1,sequence2)<<endl;//print output of the function
                break;

            case 2://if 2 is equal to input 
                cout<<"Enter genome:"<<endl;//prompt user
                cin>>genome;//assign value
                cout<<"Enter sequence:"<<endl;//prompt user
                cin>>sequence;//assign value
                cout<<"Best similarity score: "<<findBestSimScore(genome, sequence)<<endl;//print out put of the statement 
                break;
            
            case 3:
                cout<<"Enter genome 1:"<<endl;//prompt user
                cin>>genome1;//assign value
                cout<<"Enter genome 2:"<<endl;//prompt user
                cin>>genome2;//assign value
                cout<<"Enter genome 3:"<<endl;//prompt user
                cin>>genome3;//assign value
                cout<<"Enter sequence:"<<endl;//prompt user
                cin>>sequence3;//assign value
                findMatchedGenome(genome1,genome2,genome3,sequence3);//call function 
                break; 
        }
    }
    if(input==4){//if the input equals 4
        cout<<"Good bye!"<<endl;//print goodbye 
    }
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
    for(int i=0; i<genomeLength-2; i++){//for loop while i is less than the length of the genome minus 2 
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