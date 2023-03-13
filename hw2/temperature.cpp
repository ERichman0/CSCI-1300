#include <iostream> 
#include <iomanip>

using namespace std;

int main(){
    double fahrenheit;//initialize fahrenheit variable
    cout<<"Enter a temperature in Fahrenheit:"<<endl;//ask user to input a temperature 
    cin>>fahrenheit;//set user input equal to fahrenheit value 
    double celsius=(5.0/9.0)*(fahrenheit-32.0);//initialize celsius variable and set it equal to the formula
    cout<<"The temperature "<<fahrenheit<<" degrees Fahrenheit is ";//print output 
    cout<<fixed<<setprecision(2)<<celsius<<" degrees Celsius."<<endl;
    return 0;
}