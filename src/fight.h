#ifndef Fight_h
#define Fight_h

#include "backpack.h"
#include "player.h"
#include <string>

void fightScreen(Player &, vector<Item> &, bool &);
void bossScreen(Player &, vector<Item> &, int, bool &);

#endif