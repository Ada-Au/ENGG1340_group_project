#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

const int maxHealNum = 7;
const int maxArmorNum = 6;
const int maxWeaponNum = 12;
const int maxSpace = 50;
const int maxStack = 99;

struct Heal {
    const string name;
    const string desc;
    const float fullness;
    const float healing;
    const int cost;
    const int price;
};

struct Armor {
    const string name;
    const string desc;
    const float defense;    // player's defense
    const int cost;
    const int price;
};

struct Weapon {
    const string name;
    const string desc;
    const float damage;        // multiplication of attack damage
    const float energyLose;    // consume of energy for each attack
    const float mpLose;        // consume of mp for each magic attack
    const int cost;
    const int  price;
};

const Heal heals[maxHealNum] = {{"monster meat", "(+25 Energy, -10 HP)", 25, -10, 2, 12},
                                {"bread", "(+30 Energy, 5 HP)", 30, 5, 5, 30},
                                {"poor healing", "(+10 HP)", 0, 10, 10, 65},
                                {"average healing", "(+20 HP)", 0, 20, 15, 90},
                                {"decent healing", "(+50 HP)", 0, 50, 24, 145},
                                {"medium healing", "(+75 HP)", 0, 75, 36, 288},
                                {"high healing", "(+100 HP)", 0, 100, 50, 420}};

const Armor armors[maxArmorNum] = {{"boat remains", "(+1 DFS)", 1, 1, 15},
                                   {"wood shield", "(+5 DFS)", 5, 10, 150},
                                   {"leather shield", "(+10 DFS)", 10, 40, 550},
                                   {"silver shield", "(+15 DFS)", 15, 60, 900},
                                   {"golden shield", "(+20 DFS)", 20, 72, 1980},
                                   {"diamond shield", "(+100 DFS)", 100, 999, 999999}};

const Weapon weapons[maxWeaponNum] = {{"hammer", "(+10 ATK, -30 Energy/atk)", 10, 30, 0, 37, 592},
                                      {"great sword", "(+8 ATK, -15 Energy/atk)", 8, 15, 0, 18, 290},
                                      {"long sword", "(+4.5 ATK, -5 Energy/atk)", 4.5, 5, 0, 15, 204},
                                      {"spear", "(+6 ATK, -10 Energy/atk)", 6, 10, 0, 12, 200},
                                      {"sword", "(+2 ATK, -0.5 Energy/atk)", 2, 0.5, 0, 5, 169},
                                      {"wand", "(+4 ATK, -15 MP/atk)", 4, 0, 15, 30, 474},
                                      {"vorpan", "(+10 ATK, -10 Energy/atk)",10, 10, 0, 45, 3819},
                                      {"soul sword", "(+20 ATK, -8 Energy/atk, -8 MP/atk)", 20, 8, 8, 66, 6666},
                                      {"twin daggers", "(+14 Atk, -12 Energy/atk)", 14, 12, 0, 44, 4242},
                                      {"war spear", "(+12 Atk, -7 Energy/atk)", 12, 7, 0, 39, 3647},
                                      {"blood katana", "(+18 Atk, -20 Energy/atk)", 18, 20, 0, 42, 4536},
                                      {"toothpick", "(+15 Atk, -25 Energy/atk)", 15, 25, 0, 40, 3840}};

struct Item {
    string name;
    int num;
    int cost;
};

void generateThings(Item[maxSpace]);
void updateItems(string, int, int, char, Item[maxSpace]);
void displayBackpack(Item[maxSpace], bool);
void openBackpack(Item[maxSpace], Player &);

#endif