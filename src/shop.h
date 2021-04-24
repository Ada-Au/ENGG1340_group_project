#ifndef Shop_h
#define Shop_h
#include "backpack.h"
#include "player.h"

struct ShopItem {
    string name, desc;
    int amount;
    int cost, price;
};

void shopScreen(Player &player, vector<Item> &);

#endif
