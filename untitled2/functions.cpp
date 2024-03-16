//
// Created by user on 16.03.2024.
//
#include "functions.h"
#include "GameFunction.h"

inline void LowerCase(std::string &ToLower){

    std::transform(ToLower.begin(), ToLower.end(), ToLower.begin(), ::tolower);
}


void ShipChoosing(const std::vector<std::string>& ShipTypes, std::string ChosenType){

    LowerCase(ChosenType);


    for(const std::string &ShipType : ShipTypes){
        if(ChosenType == ShipType){
            puts("gecerli bir tur girdiniz");
            break;
        }
        else if(ShipType == ShipTypes.back()){
            puts("gecerli bir sonuc girmedin bitch");
        }
    }


}

void SetPointer(RapidShip &RShip, HeavyShip &HShip, NormalShip &NShip, MainShip* GameObject, const std::vector<std::string>& ShipTypes, const std::string& ChosenType){

    if(ChosenType == ShipTypes.at(0)){
        GameObject = &RShip;
        puts("hizli gemi olusturuldu");
        GameFunction(GameObject);


    }
    else if(ChosenType == ShipTypes.at(1)){
        GameObject = &HShip;
        puts("guclu gemi olusturuldu");
        GameFunction(GameObject);

    }
    else if(ChosenType == ShipTypes.at(2)){
        GameObject = &NShip;
        puts("Normal gemi olusturuldu");
        GameFunction(GameObject);

    }

}

