#include "player.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100, maxEnergy = 100;
    maxMp = 100, maxHp = 100, exp = 19, maxExp = 20, damage = 0, defense = 0;
    level = 1, gameLevel = 1;
    race = "human";
    weapon = {"", 2, 0, 1}, armor = "";
    aDefense = 0;
    // debuffs.push_back(allDebuffs[0]);
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

void nextLevel(Player &player) {
    player.maxExp += 10;
    int point = (player.level / 20) + 2;    // every 20 level add one more skill point for each upgrade
    while (point != 0) {
        char key;
        cout << "\nYou have " << point << " points to upgrade!" << endl
             << "1 - Maximum MP (+2): " << player.maxMp << endl
             << "2 - Maximum energy (+2): " << player.maxEnergy << endl
             << "3 - Damage level (+2% damage per level): " << player.damage << endl
             << "4 - Defense level (+2% defense per level): " << player.defense << endl
             << "Input number to upgrade: ";
        cin >> key;
        while (key != '1' && key != '2' && key != '3' && key != '4') {
            cout << "Please input a valid number to upgrade: ";
            cin >> key;
        }
        switch (key) {
        case '1':
            player.maxMp += 2;
            break;
        case '2':
            player.maxEnergy += 2;
            break;
        case '3':
            player.damage++;
            break;
        case '4':
            player.defense++;
            break;
        }
        point--;
    }
    cout << endl;
}

void upgradePlayer(Player &player) {
    if (player.exp >= player.maxExp && player.level <= 100) {
        player.level++;
        player.maxHp += 2;    // maxHp plus 2 for every level
        cout << "\n\nYou are now level " << player.level << "!!\n";
        nextLevel(player);    // upgrade of skills
        // restore of energy, hp and mp for every level upgrade (optional)
        player.energy = player.maxEnergy;
        player.hp = player.maxHp;
        player.mp = player.maxMp;
        player.exp = player.exp - player.maxExp;
    }
}

void updateOnBuff(Player &player) {
    for (int i = player.debuffs.size() - 1; i >= 0; i--) {
        player.hp += player.debuffs[i].hp;
        player.mp += player.debuffs[i].mp;
        player.debuffs[i].time--;
        if (player.debuffs[i].time <= 0) {
            player.debuffs.erase(player.debuffs.begin() + i);
        }
    }
    for (int i = player.buffs.size() - 1; i >= 0; i--) {
        player.hp += player.buffs[i].hp;
        player.mp += player.buffs[i].mp;
        player.buffs[i].time--;
        if (player.buffs[i].time <= 0) {
            player.buffs.erase(player.buffs.begin() + i);
        }
    }
}
