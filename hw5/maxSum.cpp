#include <iostream>
#include <iomanip>
using namespace std; 

int maxSum(int arr[][10], int numRows);

int main(){
    
}
int maxSum(int arr[][10], int numRows){
    int maxNum=arr[0][0];
    int maxSum=0;
    for(int i=0;i<numRows;i++){//iterate through rows
        for(int j=0;j<=10;j++){//iterate through coloumns 
            if(arr[i][j]>maxNum){
                maxNum=arr[i][j];
            }
        }
        maxSum=maxNum;
        maxNum=0;
    }
    return maxSum;
}