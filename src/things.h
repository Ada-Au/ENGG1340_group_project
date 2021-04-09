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
    const string desc;
    const float fullness;
    const float healing;
};

struct Armor{
    const string name;
    const string desc;
    const float defenseValue; // player's defense
};

struct Weapon{
    const string name;
    const string desc;
    const float damage;         // multiplication of attack damage
    const float energyLose;     // consume of energy for each attack
    const float mpLose;         // consume of mp for each magic attack
};

const Heal heals[maxHealNum] = {{"monster meat", "+25 Energy, -10 HP",25, -10},
                                {"bread", "+30 Energy, 5 HP",30, 5},
                                {"poor healing", "+10 HP", 0, 10},
                                {"medium healing", "+50 HP", 0, 50},
                                {"high healing", "+100 HP", 0, 100}};

const Armor armors[maxArmorNum] = {{"cloths", "+2 DFS", 2},
                                   {"wood chest", "+5 DFS", 5},
                                   {"leather chest",  "+10 DFS",10},
                                   {"silver chest",  "+15 DFS",15}};

const Weapon weapons[maxWeaponNum] = {{"hammer", "", 2.0, 30, 0},
                                      {"great sword", "", 1.5, 15, 0},
                                      {"long sword",  "", 1.25, 5, 0},
                                      {"spear",  "", 1.1, 10, 0},
                                      {"sword",  "", 1.0, 0.5, 0},
                                      {"wand",  "", 1.5, 0, 15}};

void generateThings( Item[maxSpace] );

#endif