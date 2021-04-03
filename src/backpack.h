#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include <iostream>

using namespace std;

struct items{
    string name = "";
    int num = 0;
};

items item[maxSpace];

void updateItems(string, int, char);
void backpack(items);

#endif