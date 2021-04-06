#include "player.h"
#include "things.h"
// #include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100, maxEnergy = 100; maxMp = 100, maxHp = 100, exp = 0; maxExp = 10, damage = 2, defense = 0;
    level = 1;
    race = "human";
    armor = "";
    weapon = "";
    debuffs->push_back(allDebuffs[1]);
    debuffs->push_back(allDebuffs[0]);
    debuffs->push_back(allDebuffs[2]);
    debuffs->push_back(allDebuffs[4]);
    debuffs->push_back(allDebuffs[6]);
    debuffs->push_back(allDebuffs[0]);

    buffs->push_back(allBuffs[1]);
    buffs->push_back(allBuffs[0]);
}

void upgradePlayer(Player &player)
{
    //experience points of player
    if (player.exp >= player.maxExp && player.level < 100){
        player.level ++;
        player.maxHp += 2;           // maxHp plus 2 for every level
        player.damage ++;           // damage plus level for every level
        player.exp -= player.maxExp;
        if (player.maxExp < 10000 )        // 1 - 13 level
            player.maxExp *= 2;
        else if (player.maxExp < 20000)    // 14 - 18 level
            player.maxExp *= 1.25;
        else if (player.maxExp < 30000)    // 19 - 24 level
            player.maxExp *= 1.1;
        else
            player.maxExp *= 1.05;         // 25 - 99 level

        // every 10 level, maxEnergy plus 5 until it becomes 150
        if (player.level % 10 == 0 && player.maxEnergy < 150)
            player.maxEnergy += 5;
        // every 5 level, maxMp plus 5 until it becomes 250
        if (player.level % 5 == 0 && player.maxMp < 250)
            player.maxMp += 5;        

        // restore of energy, hp and mp for every level upgrade
        player.energy = player.maxEnergy;
        player.hp = player.maxHp;
        player.mp = player.maxMp;

        std::cout << "You are now " << player.level << "!\n";
    }
}

