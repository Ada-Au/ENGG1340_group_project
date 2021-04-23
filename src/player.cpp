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
    coin = 0;
    isFirst = true;
    race = "human";
    weapon = {"Empty", 2, 0, 1}, armor = "Empty";
    aDefense = 0;
    // debuffs.push_back(allDebuffs[0]);
}

void addBuff(bool isBuff, string name, Player &player) {
    if (isBuff) {
        bool flag = true;
        for (int i = 0; i < player.buffs.size(); i++) {
            if (player.buffs[i].name == name) {
                flag = false;
                break;
            }
        }

        if (flag)
            for (int i = 0; i < maxBuff; i++) {
                if (allBuffs[i].name == name) {
                    player.buffs.push_back(allBuffs[i]);
                    break;
                }
            }
    } else {
        bool flag = true;
        for (int i = 0; i < player.debuffs.size(); i++) {
            if (player.debuffs[i].name == name) {
                flag = false;
                break;
            }
        }
        if (flag)
            for (int i = 0; i < maxDebuff; i++) {
                if (allDebuffs[i].name == name) {
                    player.debuffs.push_back(allDebuffs[i]);
                    break;
                }
            }
    }
}

void nextLevel(Player &player) {
    player.maxExp = (0.85 * pow(player.level, 3) + 0.04 * pow(player.level, 2) + 2 * player.level);
    int point = (player.level / 20) + 2;    // every 20 level add one more skill point for each upgrade
    while (point != 0) {
        char key;
        cout << "\nYou have " << point << " points to upgrade!" << endl
             << "z - Maximum MP (+2): " << player.maxMp << endl
             << "x - Maximum energy (+2): " << player.maxEnergy << endl
             << "c - Damage level (+2% damage per level): " << player.damage << endl
             << "v - Defense level (+2% defense per level): " << player.defense << endl
             << "Input character to upgrade: ";
        cin >> key;
        while (key != 'z' && key != 'Z' && key != 'x' && key != 'X' && key != 'c' && key != 'C' && key != 'v' && key != 'V') {
            cout << "Please input a valid character to upgrade: ";
            cin >> key;
        }
        switch (key) {
        case 'z':
        case 'Z':
            player.maxMp += 2;
            break;
        case 'x':
        case 'X':
            player.maxEnergy += 2;
            break;
        case 'c':
        case 'C':
            player.damage++;
            break;
        case 'v':
        case 'V':
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
