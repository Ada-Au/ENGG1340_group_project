#include "player.h"
// #include <stdlib.h>
#include <iostream>

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100, maxMp = 100, maxHp = 100;
    race = "human";
    debuffs->push_back(allDebuffs[1]);
    debuffs->push_back(allDebuffs[0]);
    debuffs->push_back(allDebuffs[2]);
    debuffs->push_back(allDebuffs[4]);
    debuffs->push_back(allDebuffs[6]);
    debuffs->push_back(allDebuffs[0]);

    buffs->push_back(allBuffs[1]);
    buffs->push_back(allBuffs[0]);
}