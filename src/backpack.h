#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

const int maxHealNum = 5;
const int maxArmorNum = 4;
const int maxWeaponNum = 6;
const int maxSpace = 50;
const int maxStack = 99;

struct Heal {
    const string name;
    const string desc;
    const float fullness;
    const float healing;
};

struct Armor {
    const string name;
    const string desc;
    const float defense;    // player's defense
};

struct Weapon {
    const string name;
    const string desc;
    const float damage;        // multiplication of attack damage
    const float energyLose;    // consume of energy for each attack
    const float mpLose;        // consume of mp for each magic attack
};

const Heal heals[maxHealNum] = {{"monster meat", "(+25 Energy, -10 HP)", 25, -10},
                                {"bread", "(+30 Energy, 5 HP)", 30, 5},
                                {"poor healing", "(+10 HP)", 0, 10},
                                {"average healing", "(+20 HP)", 0, 20},
                                {"decent healing", "(+50 HP)", 0, 50}};

const Armor armors[maxArmorNum] = {{"boat remains", "(+1 DFS)", 1},
                                   {"wood shield", "(+5 DFS)", 5},
                                   {"leather shield", "(+10 DFS)", 10},
                                   {"silver shield", "(+15 DFS)", 15}};

const Weapon weapons[maxWeaponNum] = {{"hammer", "", 10, 30, 0},
                                      {"great sword", "", 8, 15, 0},
                                      {"long sword", "", 4.5, 5, 0},
                                      {"spear", "", 6, 10, 0},
                                      {"sword", "", 2, 0.5, 0},
                                      {"wand", "", 4, 0, 15}};

struct Item {
    string name;
    int num;
};

void generateThings(Item[maxSpace]);
void updateItems(string, int, char, Item[maxSpace]);
void openBackpack(Item[maxSpace], Player &);

#endif