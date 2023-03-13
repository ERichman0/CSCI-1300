// CS1300 Fall 2020
// Author: Ethan Richman 
// Recitation: 213 – Julia Romero
// Homework 8 - Problem #2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int>shuffle(vector<int> v1, vector<int> v2){
    int v1Size=v1.size();
    int v2Size=v2.size();
    vector<int>v3;

    if(v1Size==0&&v2Size==0){
        return v3;
    }
    if(v1Size==v2Size){
        for(int i=0; i<v1Size; i++){
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
        return v3;
    }
    if(v1Size>v2Size){
        for(int j=0; j<v2Size; j++){
            v3.push_back(v1[j]);
            v3.push_back(v2[j]);
        }
        for(int i=v2Size; i<v1Size; i++){
            v3.push_back(v1[i]);
        }
        return v3;
    }
    if(v2Size>v1Size){
        for(int j=0;j<v1Size;j++){
            v3.push_back(v2[j]);
            v3.push_back(v1[j]);
        }
        for(int i=v1Size; i<v2Size; i++){
            v3.push_back(v2[i]);
        }
        return v3;
    }
    return v3;
}

int main(){
    //need to complie in terminal 
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] <<" ";
    }
}