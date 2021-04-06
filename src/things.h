#ifndef Things_h
#define Things_h
#include "backpack.h"
#include <iostream>
#include <string>

using namespace std;

const int maxHealNum = 5;
const int maxArmorNum = 4;
const int maxWeaponNum = 6;

struct Heal{
    const string name;
    const float fullness;
    const float healing;
};

struct Armor{
    const string name;
    const float defenseValue; // player's defense
};

struct Weapon{
    const string name;
    const float damage;      // multiplication of attack damage
    const float energyLose;     // consume of energy for each attack
    const float mpLose;         // consume of mp for each magic attack
};

const Heal heals[maxHealNum] = {{"monster meat", 25, -10},
                                {"bread", 30, 5},
                                {"poor healing", 0, 10},
                                {"medium healing", 0, 50},
                                {"high healing", 0, 100}};

const Armor armors[maxArmorNum] = {{"cloths", 2},
                                   {"wood chest", 5},
                                   {"leather chest", 10},
                                   {"silver chest", 15}};

const Weapon weapons[maxWeaponNum] = {{"hammer", 2.0, 30, 0},
                                      {"great sword", 1.5, 15, 0},
                                      {"long sword", 1.25, 5, 0},
                                      {"spear", 1.1, 10, 0},
                                      {"sword", 1.0, 0.5, 0},
                                      {"wand", 1.5, 0, 15}};

void generateThings( Item[maxSpace] );

#endif