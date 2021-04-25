#include "player.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Player::Player() {
    mark = '@';      // player's icon on map
    x = 1, y = 1;    // player's initial position
    // player's initial status
    mp = 100, hp = 100, energy = 100, maxEnergy = 100;
    maxMp = 100, maxHp = 100, exp = 0, maxExp = 20, damage = 0, defense = 0;
    level = 1, gameLevel = 1;       // player's level and round level
    coin = 0;                       // player's money
    isFirst = true;                 // bool for player first meeting Charon
    race = "human";                 // player's initial race
    weapon = {"Empty", 2, 0, 1};    // player's weapon {name, damage, mp loss, energy loss}
    armor = "Empty";                // player's armor
    aDefense = 0;                   // player's initial armor defense value
}

void addBuff(bool isBuff, string name, Player &player) {
    // check for if its buff or debuff
    if (isBuff) {
        // check for if buff exist
        bool flag = true;
        for (int i = 0; i < player.buffs.size(); i++) {
            if (player.buffs[i].name == name) {
                flag = false;
                break;
            }
        }
        // if exist, add buff to player
        if (flag)
            for (int i = 0; i < maxBuff; i++) {
                if (allBuffs[i].name == name) {
                    player.buffs.push_back(allBuffs[i]);
                    break;
                }
            }
    } else {
        // same as above
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

// level-up mechanism of player's max experience point & skills system
void nextLevel(Player &player) {
    // player.maxExp = (0.85 * pow(player.level, 3) + 0.04 * pow(player.level, 2) + 2 * player.level); TODO
    player.maxExp += 5;
    player.exp -= player.maxExp;
    int point = (player.level / 20) + 2;    // every 20 level add one more skill point for each upgrade
    while (point != 0) {                    // until player uses up all skill points
        char key;
        cout << "\nYou have " << point << " points to upgrade!" << endl
             << "z - Maximum MP (+2): " << player.maxMp << endl
             << "x - Maximum energy (+2): " << player.maxEnergy << endl
             << "c - Damage level (+2% damage per level): " << player.damage << endl
             << "v - Defense level (+2% defense per level): " << player.defense << endl
             << "Input character to upgrade: ";
        cin >> key;
        // restrict player's choice within 'Z'/'z', 'X'/'x', 'C'/'c', 'V'/'v'
        while (key != 'z' && key != 'Z' && key != 'x' && key != 'X' && key != 'c' && key != 'C' && key != 'v' && key != 'V') {
            cout << "Please input a valid character to upgrade: ";
            cin >> key;
        }
        switch (key) {
        case 'z':    // increase max.mp
        case 'Z':
            player.maxMp += 2;
            break;
        case 'x':    //increase max.energy
        case 'X':
            player.maxEnergy += 2;
            break;
        case 'c':    // increase atk
        case 'C':
            player.damage++;
            break;
        case 'v':    // increase dfs
        case 'V':
            player.defense++;
            break;
        }
        point--;
    }
    cout << endl;
}

// player's upgrade after level up
void upgradePlayer(Player &player) {
    // player's experience points won't be clear after level up
    // instead, player's experience points accumulate
    // max. player level is 100
    if (player.exp >= player.maxExp && player.level <= 100) {
        player.level++;
        player.maxHp += 2;    // max.Hp plus 2 for every level
        cout << "\n\nYou are now level " << player.level << "!!\n";
        nextLevel(player);    // upgrade of skills & max.exp
        // restore of energy, hp and mp for every level upgrade
        player.energy = player.maxEnergy;
        player.hp = player.maxHp;
        player.mp = player.maxMp;
    }
}

// Update user status by buff effect and count down timer for buff
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
