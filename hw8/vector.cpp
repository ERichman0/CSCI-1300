// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 8 - Problem #1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int>num;
    int input=0;
    while(input!=-1){
        cout<<"Please enter a number:"<<endl;
        cin>>input;
        if(input==0||input<-1){
            cout<<"The number should be a positive integer or -1."<<endl;
        }else{
            if(input==-1){
                if(num.size()==0){
                    cout<<"The vector is empty."<<endl;
                }else{
                    cout<<"The elements in the vector are: ";
                    for(unsigned int i=0; i<num.size();i++){
                        cout<<num[i]<<" ";
                    }
                    cout<<endl;
                //find max and min vlaues 
                int min=num[0];
                int max=num[0];
                for(unsigned int i=0; i<num.size(); i++){
                    if(num[i]>=max){
                        max=num[i];
                    }
                    if(num[i]<=min){
                        min=num[i];
                    }
                }
                cout<<"Min = "<<min<<endl;
                cout<<"Max = "<<max<<endl;
                return 0;  
                }
            }else{
                if(num.size()==0){
                    num.push_back(input);
                }else{
                    if(input%5==0&&input%3==0){
                        num.push_back(input);
                    }
                    if(input%5==0){
                        num.erase(num.begin());
                        }
                    if(input%3==0){
                        num.pop_back();
                        }
                    if(num.size()!=0&&input%5!=0&&input%3!=0){
                        num.push_back(input);
                        }
                    }
                } 
            }
        }
    }