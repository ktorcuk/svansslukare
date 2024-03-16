//
// Created by user on 15.03.2024.
//

#ifndef UNTITLED2_SHIP_H
#define UNTITLED2_SHIP_H
#include "randomizer.h"
static constexpr float RSexapeX{1.5};
static constexpr float HSexapeX{0.5};
static constexpr float RSdamageX{1.5};
static constexpr float HSdamageX{0.5};
static constexpr int FuelDecrementor{33};

class MainShip : public Randomizer{
public:
    int fuel;
    float hp;
    int money;
    float damageX;
    float escapeX;

public:
    MainShip(){
        fuel = 99;
        hp = 100.0f;
        money = 0;
        damageX =1;
        escapeX =1;
        std::cout << "constructor of MainShip" << "\n";
    }

    inline virtual void incrementMoney(){}
    inline virtual void decrementMoney(int DMvalue){}
    inline virtual void decrementFuel(){}
    inline virtual void decrementHp(float DHvalue){}
    inline virtual void decrementHpAsteroid(){}

};

class NormalShip : public MainShip{
public:
    NormalShip() : MainShip(){
        std::cout << "constructor of NormalShip" << "\n";
    }

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
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};

class RapidShip : public MainShip{
public:
    RapidShip() : MainShip(){
        escapeX = escapeX * RSexapeX;
        damageX = damageX * RSdamageX;
        std::cout << "constructor of RapidShip" << "\n";
    }

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
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};

class HeavyShip : public MainShip{
public:
    HeavyShip() : MainShip(){
        escapeX = escapeX * HSexapeX;
        damageX = damageX * HSdamageX;
        std::cout << "constructor of HeavyShip: " << "\n";
    }

public:
    void incrementMoney() override{
        money = money+10;
    }
    void decrementMoney(int DMvalue) override{
        money = money - DMvalue;
    }
    void decrementFuel() override{
        fuel = fuel - FuelDecrementor;
    }
    void decrementHp(float DHvalue) override{
        hp = hp - (DHvalue * damageX);
    }
    void decrementHpAsteroid() override{
        hp = hp - 10;
    }
};
#endif //UNTITLED2_SHIP_H
