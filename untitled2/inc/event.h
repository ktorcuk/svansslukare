//
// Created by user on 15.03.2024.
//

#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
#include "ship.h"

static int result{0};
int resultEscape;
int PiratesChoiceNumber;
bool PiratesChoiceNumberCorrectness;
bool BargainCondition;

void EventAsteroidBelt(MainShip* object);
int EventAbandonedPlanet(MainShip* object);
void EventPiratesEscape(MainShip* object);
void PiratesChoices(MainShip* object);
void EventPiratesFight(MainShip* object);
void EventPiratesBargain(MainShip* object);
#endif //UNTITLED2_EVENT_H
