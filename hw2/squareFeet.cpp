#include <iostream>
#include <iomanip>

using namespace std; 

int main(){
    double sideA;
    cout<<"Enter the length of side a in inches:"<<endl;
    cin>>sideA;
    double sideB;
    cout<<"Enter the length of side b in inches:"<<endl;
    cin>>sideB;

    //Inches to feet
    float feetA=sideA/12;
    double feetB=sideB/12;

    double area=feetA*feetB;

    cout<<"The are of the rectagular field is "<<fixed<<showpoint<<setprecision(2)<<area<<" square feet"<<endl;
}