#include <iostream>
#include "Planet.h"
using namespace std;
int main() {    
    string name = "Earth";    
    double radius = 42;   
    Planet p6 = Planet(name, radius);    
    cout << "Planet Name: " << p6.getName() << endl;     
    cout << "Planet Radius: " << p6.getRadius() << endl;    
    cout << "Planet Volume: " << p6.getVolume() << endl;    
    double newRadius=24;
    p6.setName("Jupiter");    
    p6.setRadius(newRadius);    
    cout << "Planet Name: " << p6.getName() << endl;     
    cout << "Planet Radius: " << p6.getRadius() << endl;    
    cout << "Planet Volume: " << p6.getVolume() << endl;

    
}