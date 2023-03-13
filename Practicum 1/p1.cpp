#include <iostream>
using namespace std; 

int main(){
    double distanceTraveled;
    double averageSpeed;
    double gasPrice;
    double totalCost;
    double milesPerGallon; 
    cout<<"Enter the distance travelled:"<<endl;
    cin>>distanceTraveled;
    cout<<"Enter the average speed:"<<endl;
    cin>>averageSpeed;
    cout<<"Enter the gas price:"<<endl;
    cin>>gasPrice;
    if(averageSpeed>62){
        milesPerGallon=26.0;
    }else{
        milesPerGallon=30.0;
    }
    totalCost=(distanceTraveled/milesPerGallon)*gasPrice;
    cout<<"The total cost of the trip is: "<<totalCost<<endl;
}