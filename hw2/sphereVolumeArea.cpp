#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    double radius;
    cout<<"Enter a radius:"<<endl;
    cin>>radius;
    double surfaceArea=4.0*M_PI*(radius*radius);
    double volume=(4.0/3.0)*M_PI*(radius*radius*radius);
    cout<<"Volume: "<<volume<<endl;
    cout<<"Surface area: "<<surfaceArea<<endl;
    
}