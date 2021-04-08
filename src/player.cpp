#include "player.h"
#include <algorithm>
#include <iostream>

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100, mp = 100, hp = 100;
    race = "human";
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

void updateOnBuff(Player &player) {
    vector<Buff> newBuffs;
    // for (int i = player.debuffs.size(); i > 0; i--) {
    //     player.hp += player.debuffs[i].hp;
    //     player.hp += player.debuffs[i].mp;
    //     player.debuffs[i].time++;
    // if (player.debuffs[i].time == 5) {
    //     player.debuffs.erase(player.debuffs.begin() + i - 1);
    // }
    // }
    // for (int i = player.buffs.size(); i > 0; i--) {
    //     player.hp += player.buffs[i].hp;
    //     player.hp += player.buffs[i].mp;
    //     player.buffs[i].time++;
    // if (player.buffs[i].time == 5) {
    //     player.buffs.erase(player.buffs.begin() + i - 1);
    // }
    // }
};
