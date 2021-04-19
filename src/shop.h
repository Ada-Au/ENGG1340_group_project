#ifndef Shop_h
#define Shop_h
#include "backpack.h"
#include "player.h"

struct ShopItem {
    string name, desc;
    int amount;
    int price, cost;
};

void shopScreen(Player player,Item[maxSpace], bool &);

#endif
