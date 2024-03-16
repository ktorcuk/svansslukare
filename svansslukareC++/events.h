//
// Created by user on 12.03.2024.
//

#ifndef SVANSSLUKAREC___EVENTS_H
#define SVANSSLUKAREC___EVENTS_H
#include "ship.h"
#include <iostream>

class events{
public:
    int x;

};


class AllEvents {
    int result = 0; // sonradan bunun yerine trash value atamasın diye initialize edildi
public:
    inline void EventAsteroidBelt(Eventfull* object) {
        result = object->AsteroidBelt();
        if(result == 0) {
            std::cout <<"Geminiz hasar almayacak!" <<"\n";
        }
        else {
            object->decrementHp(10);
            std::cout <<"Geminiz 10 hasar alacak" <<"\n";
        }

    }

    inline void EventAbandonedPlanet(Eventfull* object) {
        result = object->AbandonedPlanet();
        if(result == 0) {
            object->incrementMoney();
            std::cout <<"10 altın kazandınız\n";
        }
        else {
            std::cout <<"Korsanlar geliyor\n";
            object->PiratesChoices();

        }

    }

    friend class MainShip;
};

class Pirates : public AllEvents{

private:
    int resultEscape;
    int resultFight;
    int resultBargain;
    int resultBargainQuantity;
    bool BargainCondition;
    int PiratesChoiceNumber;
    bool PiratesChoiceNumberCorrectness;
public:

    bool PiratesEscapeKosul = 1; //pirate lerin senin kaçma durumunda yakalama durumu 1, kaçma durumu 0
    inline void EventPiratesEscape(Eventfull* object){
        std::cout<<"Korsanlardan kacmayi deniyorsunuz\n";
        while (PiratesEscapeKosul == 1){
            resultEscape = object->PiratesEscape();
            if (resultEscape == 0){
                std::cout<<"Korsanlardan kactiniz\n";
                PiratesEscapeKosul = 0; // burada korsanlardan kaçıyorsun
            }
            else {
                std::cout<<"Korsanlar sizi yakaladi.\n";
            }
        }
    }

    inline void EventPiratesFight(Eventfull* object){
        std::cout<<"Korsanlarla savasmayi sectiniz.\n";
        resultFight = object->PiratesFight();
        if (resultFight == 0){
            std::cout<<"kazandiniz\n";
        }
        else {
            object->decrementHp(30);
            std::cout<<"yenildiniz\n";
        }
    }

    inline void EventPiratesBargain(Eventfull* object){ // pazarlık edilecek miktar hesaplanır ve eğer eldeki miktar daha büyükse ödenir.
        resultBargain = object->PiratesBargain(); // daha en başında pazarlık edilip edilemeyeceği game fonksiyonunda incelenecek
        if (resultBargain == 1){
            resultBargainQuantity = 10;
        }
        else if (resultBargain == 2){
            resultBargainQuantity = 20;
        }
        else {
            resultBargainQuantity = 30;
        }
        if (object->money >= resultBargainQuantity){
            BargainCondition = 0;
            object->decrementMoney(resultBargainQuantity);
            std::cout<<"Pazarlik ettiniz ve "<<resultBargainQuantity<<" altin odediniz\n";
        }

    }

    inline void PiratesChoices(Eventfull* object){
        if (BargainCondition == 0){
            std::cout<<"Kac(1), savas(2), pazarlik et(3)(-"<<resultBargainQuantity<<"altin):";
            PiratesChoiceNumberCorrectness = false;
        }
        else {
            std::cout<<"Kac(1), savas(2), pazarlik et(3)(-"<<resultBargainQuantity<<"altin)(pazarlik edilemez, yeterli altinin yok):";
            while (PiratesChoiceNumberCorrectness == false){
                std::cin>>PiratesChoiceNumber;
                if (PiratesChoiceNumber == 1 || PiratesChoiceNumber == 2){
                    PiratesChoiceNumberCorrectness = true;
                }
                else {
                    std::cout<<"Lutfen gecerli bir sayi girin:";
                }
            }
        }
        if (PiratesChoiceNumber == 1){
            object->EventPiratesEscape(object);
        }
        else if (PiratesChoiceNumber == 2){
            object->EventPiratesFight(object);
        }
        else {
            object->EventPiratesBargain(object);
        }
    }

    friend class MainShip;
};


#endif //SVANSSLUKAREC___EVENTS_H
