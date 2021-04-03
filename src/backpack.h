#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include <iostream>
#include <string>

using namespace std;

struct Item {
    string name;
    int num;
};

void updateItems(string, int, char, Item[maxSpace]);
void openBackpack(Item[maxSpace]);

#endif