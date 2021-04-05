#ifndef Things_h
#define Things_h
#include <iostream>
#include <string>
#include "backpack.h"

using namespace std;

const int maxHealNum = 5;
const int maxArmorNum = 4;
const int maxWeaponNum = 6;

struct Heal{
    string name;
    int fullness;
    int healing;
};

struct Armor{
    string name;
    double defenseRate; // multiplication of player's defense value
};

struct Weapon{
    string name;
    double damage;      // multiplication of attack damage
    int energyLose;     // consume of energy for each attack
    int mpLose;         //consume of mp for each magic attack
};

const Heal heals[maxHealNum] = {{"monster meat", 25, -10},
                                {"bread", 30, 5},
                                {"poor healing", 0, 10},
                                {"medium healing", 0, 50},
                                {"high healing", 0, 100}};

const Armor armors[maxArmorNum] = {{"cloths", 1.05},
                                   {"wood chest", 1.1},
                                   {"leather chest", 1.25},
                                   {"silver chest", 1.5}};

const Weapon weapons[maxWeaponNum] = {{"hammer", 2, 30, 0},
                                      {"great sword", 1.5, 15, 0},
                                      {"long sword", 1.25, 5, 0},
                                      {"spear", 1.1, 10, 0},
                                      {"sword", 1, 1, 0},
                                      {"wand", 1.5, 0, 15}};

void generateThings(Item[maxSpace]);

#endif