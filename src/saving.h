#ifndef saving_h
#define saving_h

#include "backpack.h"
#include "player.h"

void saveGame(Player player, Item items[maxSpace]);
void getSavedGame(Player &player, string fileName, Item items[maxSpace]);

#endif