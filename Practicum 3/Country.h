#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

class Country{
    public:
        Country();
        int LoadCountry(string filename);
        int SearchForCountry(string country);
        string GetCapital(string country);

    private:
        string countries[50];
        string capitals[50];
};
#endif