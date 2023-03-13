#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
using namespace std;

class Resources{
    public: 
        Resources();
        Resources(int f, int b, int c, int o, int m, int p);
        //getters
        int getFood();
        int getBullets();
        int getCash();
        int getOxen();
        int getMed();
        int getParts();
        //setters
        void setFood(int f);
        void setBullets(int b);
        void setCash(int c);
        void setOxen(int o);
        void setMed(int m);
        void setParts(int p);
    private: 
        int food;
        int bullets;
        int cash;
        int oxen;
        int med;
        int parts;
};
#endif