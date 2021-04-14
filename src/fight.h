#ifndef Fight_h
#define Fight_h

#include "backpack.h"
#include "player.h"
#include <string>

void fightScreen(Player &, Item[maxSpace], bool &);
void bossScreen(Player &, Item[maxSpace], int, bool &);

#endif