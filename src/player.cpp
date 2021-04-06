#include "player.h"
#include <algorithm>

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
    for (int i = 0; i < player.debuffs.size(); i++) {
        player.hp += player.debuffs[i].hp;
        player.hp += player.debuffs[i].mp;
    }
    for (int i = 0; i < player.buffs.size(); i++) {
        player.hp += player.buffs[i].hp;
        player.hp += player.buffs[i].mp;
    }
};
