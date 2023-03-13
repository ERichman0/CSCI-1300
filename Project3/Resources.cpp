#include "Resources.h"

    Resources::Resources(){
        food=0;
        bullets=0;
        cash=0;
        oxen=0;
        med=0;
        parts=0;
    }
    Resources::Resources(int f, int b, int c, int o, int m, int p){
        food=f;
        bullets=b;
        cash=c;
        oxen=o;
        med=m;
        parts=p;       
    }
    int Resources::getFood(){
        return food;
    }
    int Resources::getBullets(){
        return bullets;
    }
    int Resources::getCash(){
        return cash;
    }
    int Resources::getOxen(){
        return oxen;
    }
    int Resources::getMed(){
        return med;
    }
    int Resources::getParts(){
        return parts;
    }
    void Resources::setFood(int f){
        food=f;
    }
    void Resources::setBullets(int b){
        bullets=b;
    }
    void Resources::setCash(int c){
        cash=c;
    }
    void Resources::setOxen(int o){
        oxen=o;
    }
    void Resources::setMed(int m){
        med=m;
    }
    void Resources::setParts(int p){
        parts=p;
    }
