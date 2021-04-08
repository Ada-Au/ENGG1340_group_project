#include "player.h"
#include "things.h"
// #include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100, maxEnergy = 100; maxMp = 100, maxHp = 100, exp = 0, maxExp = 10, damage = 2, defense = 0, weaponEnergy = 1;
    level = 1;
    race = "human";
    weapon = "";
    armor = "";
    debuffs.push_back(allDebuffs[0]);
}

void addBuff(bool isAdd, int buff, Player &player) {
    if (isAdd) {
        bool flag = true;
        for (int i = 0; i < player.buffs.size(); i++) {
            if (player.buffs[i].name == allBuffs[buff].name) {
                flag = false;
                break;
            }
        }
        if (flag)
            player.buffs.push_back(allBuffs[buff]);
    } else {
        bool flag = true;
        for (int i = 0; i < player.debuffs.size(); i++) {
            if (player.debuffs[i].name == allDebuffs[buff].name) {
                flag = false;
                break;
            }
        }
        if (flag)
            player.debuffs.push_back(allDebuffs[buff]);
    }
}

void upgradePlayer(Player &player)
{
    if (player.exp >= player.maxExp && player.level < 100){
        player.level ++;
        player.maxHp += 2;              // maxHp plus 2 for every level
        player.damage ++;               // damage plus level for every level-upgrade
        player.exp -= player.maxExp;    // restart of exp.
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

        // restore of energy, hp and mp for every level upgrade (optional)
        player.energy = player.maxEnergy;
        player.hp = player.maxHp;
        player.mp = player.maxMp;

        std::cout << "You are now " << player.level << "!\n";
    }
}

void updateOnBuff(Player &player) {
    vector<Buff> newBuffs;
    for (int i = player.debuffs.size(); i > 0; i--) {
        player.hp += player.debuffs[i].hp;
        player.hp += player.debuffs[i].mp;
        player.debuffs[i].time++;
        if (player.debuffs[i].time == 5) {
            player.debuffs.erase(player.debuffs.begin() + i - 1);
        }
    }
    for (int i = player.buffs.size(); i > 0; i--) {
        player.hp += player.buffs[i].hp;
        player.hp += player.buffs[i].mp;
        player.buffs[i].time++;
        if (player.buffs[i].time == 5) {
            player.buffs.erase(player.buffs.begin() + i - 1);
        }
    }
};
