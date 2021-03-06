#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

const int maxHealNum = 7;
const int maxArmorNum = 6;
const int maxWeaponNum = 13;
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
    const int price;
};

const Heal heals[maxHealNum] = {{"monster meat", "(+25 Energy, -10 HP)", 25, -10, 5, 12},
                                {"bread", "(+30 Energy, 5 HP)", 30, 5, 12, 30},
                                {"poor healing", "(+10 HP)", 0, 10, 25, 65},
                                {"average healing", "(+20 HP)", 0, 20, 37, 90},
                                {"decent healing", "(+50 HP)", 0, 50, 60, 145},
                                {"medium healing", "(+75 HP)", 0, 75, 90, 288},
                                {"high healing", "(+100 HP)", 0, 100, 125, 420}};

const Armor armors[maxArmorNum] = {{"boat remains", "(+1 DFS)", 1, 2, 15},
                                   {"wood shield", "(+5 DFS)", 5, 25, 150},
                                   {"leather shield", "(+10 DFS)", 10, 100, 550},
                                   {"silver shield", "(+15 DFS)", 15, 150, 900},
                                   {"golden shield", "(+20 DFS)", 20, 180, 1980},
                                   {"diamond shield", "(+100 DFS)", 100, 2999, 9999}};

const Weapon weapons[maxWeaponNum] = {{"hammer", "(+10 ATK, -30 Energy/atk)", 10, 30, 0, 92, 592},
                                      {"great sword", "(+8 ATK, -15 Energy/atk)", 8, 15, 0, 45, 290},
                                      {"long sword", "(+4.5 ATK, -5 Energy/atk)", 4.5, 5, 0, 37, 204},
                                      {"spear", "(+6 ATK, -10 Energy/atk)", 6, 10, 0, 30, 200},
                                      {"sword", "(+2 ATK, -0.5 Energy/atk)", 2, 0.5, 0, 12, 169},
                                      {"wand", "(+8 ATK, -15 MP/atk)", 8, 0, 15, 100, 474},
                                      {"vorpan", "(+10 ATK, -10 Energy/atk)", 10, 10, 0, 202, 3819},
                                      {"soul sword", "(+20 ATK, -8 Energy/atk, -8 MP/atk)", 20, 8, 8, 166, 6666},
                                      {"twin daggers", "(+14 Atk, -12 Energy/atk)", 14, 12, 110, 4242},
                                      {"war spear", "(+12 Atk, -7 Energy/atk)", 12, 7, 0, 97, 3647},
                                      {"blood katana", "(+18 Atk, -20 Energy/atk)", 18, 20, 0, 105, 4536},
                                      {"toothpick", "(+15 Atk, -25 Energy/atk)", 15, 25, 0, 100, 3840},
                                      {"diamond sword", "(+30 ATK, -5 Energy/atk)", 30, 5, 0, 4999, 99999}};

struct Item {
    string name;
    int num;
    int cost;
};

void generateDrops(vector<Item> &, Player &);
void updateItems(string, int, int, char, vector<Item> &);
void displayBackpack(vector<Item> &, bool);
void openBackpack(vector<Item> &, Player &);
void generateChestItems(vector<Item> &, Player &);

#endif