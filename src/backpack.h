#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

const int maxNum = 99;
const int maxSpace = 50;

struct Item {
    string name;
    int num;
};

void updateItems(string, int, char,Item[maxSpace]);
void openBackpack(Item[maxSpace], Player &);

#endif