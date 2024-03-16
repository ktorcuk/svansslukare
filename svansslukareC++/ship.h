#ifndef SHIPCLASSES_SHIPS_H
#define SHIPCLASSES_SHIPS_H

#include <iostream>
#include "events.h"
#include "randomizerKod.h"

static constexpr float RSexapeX{1.5};
static constexpr float HSexapeX{0.5};
static constexpr float RSdamageX{1.5};
static constexpr float HSdamageX{0.5};
static constexpr int FuelDecrementor{33};



class MainShip : public events{
public:
    int fuel;
    int hp;
    int money;
    float damageX;
    float escapeX;

public:
    MainShip(){
        fuel = 99;
        hp = 100;
        money = 0;
        damageX =1;
        escapeX =1;
        std::cout << "constructor of MS" << "\n";
    }

    inline virtual void incrementMoney() = 0;
    inline virtual void decrementMoney(int DMvalue) = 0;
    inline virtual void decrementFuel() = 0;
    inline virtual void decrementHp(int DHvalue) = 0;


};



class NormalShip : public MainShip{

public:
    NormalShip() : MainShip(){}

public:

    void incrementMoney() override{
        money = money+10;
    }

    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel-FuelDecrementor;
    }
    void decrementHp(int DHvalue) override{
        hp = hp - (DHvalue*damageX);
    }



};



class RapidShip : public MainShip{

public:
    RapidShip() : MainShip(){
        escapeX = escapeX*RSexapeX;
        damageX = damageX*RSdamageX;
        std::cout << "constructor of RS" << "\n";
    }
    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel-FuelDecrementor;
    }
    void decrementHp(int DHvalue) override{
        hp = hp - (DHvalue*damageX);
    }

};


class HeavyShip : public MainShip{
public:
    HeavyShip() : MainShip(){
        escapeX = escapeX*HSexapeX;
        damageX = damageX*HSdamageX;
        std::cout << "constructor of RS" << "\n";
    }

    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel-FuelDecrementor;
    }
    void decrementHp(int DHvalue) override{
        hp = hp - (DHvalue*damageX);
    }

};




#endif //SHIPCLASSES_SHIPS_H