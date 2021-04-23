#ifndef Action_h
#define Action_h

#include "backpack.h"
#include "map.h"
#include "screen.h"

void action(Screen, Map, Player, vector<Item> &, bool &);
void tryAgain(string, bool &);
void ending();
void clearScreen();

#endif