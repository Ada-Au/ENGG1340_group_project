#ifndef Backpack_h
#define Backpack_h

#include "env.h"
#include <iostream>
#include <string>

using namespace std;

struct Items{
    string name = "";
    int num = 0;
};

void updateItems(string, int, char, Items[maxSpace]);
void backpack(Items[maxSpace]);

#endif