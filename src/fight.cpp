#include "fight.h"
#include "map.h"
#include "npc.h"
// #include "things.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void displayStats(float mHp, float mMaxHp, Player player, string mName, bool escape = false) {
    int showMHp = mHp / mMaxHp * 50;
    int showHp = player.hp / player.maxHp * 50;
    cout << fixed << setprecision(2);
    cout << "Monster's HP: " << mHp << '/' << mMaxHp << endl;
    cout << '|' << setfill(' ') << string(showMHp, '*')
         << setw(50 - showMHp) << '|' << endl;
    renderNpc(mName, "");
    cout << "Player's HP: " << player.hp << '/' << player.maxHp << endl;
    cout << '|' << string(showHp, '*') << setfill(' ')
         << setw(50 - showHp) << '|' << endl;
    cout << "Player's Energy: " << player.energy << '/' << player.maxEnergy
         << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
    cout << "ACTION (please input number 1-4)" << endl
         << "1 - Attack               2 - Defence " << endl
         << "3 - Use Something";
    if (escape)
        cout << "        4 - Escape";
    cout << endl;
}

bool fight(Player &player, Item items[], Monster monster, float &mHp, bool escape = false) {
    char key;
    while (mHp > 0 && player.hp > 0) {
        float mDamage = monster.damage;    // TODO add fluctuation
        displayStats(mHp, monster.hp, player, monster.name, escape);
        cin >> key;
        switch (key) {
        case '1':
            if (player.energy - player.weapon.energy > 0 && player.mp - player.weapon.mp > 0) {
                if (rand() % 10 >= 1) {    // rate of player's hitting >= 90%
                    float criticalHit = 1;
                    bool critical = false;
                    if (rand() % 100 <= 6) {    // rate of critical hit = 6%
                        criticalHit = 1.5;
                        critical = true;
                    }
                    player.energy -= player.weapon.energy;
                    player.mp -= player.weapon.mp;
                    cout << "Player: Successfully make " << (player.weapon.damage * criticalHit * (1 + player.damage / 50.0));
                    if (critical)
                        cout << " critical";
                    cout << " damage." << endl;
                    mHp -= player.weapon.damage * criticalHit * (1 + player.damage / 50.0);

                } else {
                    cout << "Player: Miss!" << endl;
                }

                if ((!escape && rand() % 10 >= 1) || rand() % 10 >= 3) {
                    float criticalHit = 1;
                    bool critical = false;
                    if (rand() % 100 <= 6) {    // rate of critical hit = 6%
                        criticalHit = 1.2;
                        critical = true;
                    }
                    cout << monster.name << ": Successfully make " << monster.damage * criticalHit;
                    if (critical)
                        cout << " critical";
                    cout << " damage." << endl;
                    player.hp -= monster.damage * criticalHit;
                } else {
                    cout << monster.name << ": Miss!" << endl;
                }
            } else {
                cout << RED << "You have no energy to attack now." << RESET << endl;
            }
            break;

        case '2':
            if (mHp > 0) {
                if (monster.damage - player.aDefense * (1 + player.defense / 50.0) <= 0 || rand() % 10 >= 8) {    // 100% if player defense is higher than monster attack
                    player.hp -= monster.damage - player.aDefense * (1 + player.defense / 50.0);                  // When lower, 80% defense part of attack, 20% defense all
                    cout << monster.name << ": Got you! Make " << monster.damage - player.aDefense * (1 + player.defense / 50.0) << " damage!" << endl;
                } else {
                    cout << "Player: Successfully defensed." << endl;
                }
            }
            break;

        case '3':
            openBackpack(items, player);
            break;
            cout << endl;

        case '4':
            if (escape) {
                if (rand() % 100 < 30) {
                    return true;
                } else {
                    cout << "You didn't escape! " << monster.name << " hit you with " << mDamage << '!' << endl;
                    player.hp -= mDamage;
                }
                break;
            }
        default:
            cout << "Please input a valid number" << endl;
        }
        cout << endl;
    }
    return false;
}

void bossScreen(Player &player, Item items[], int bossIndex, bool &isEnd) {
    srand(time(NULL));
    Monster boss;
    switch (bossIndex) {
    case 1:
        boss = boss1;
        renderNpc(boss.name, "AH! Don't kill me please QwQ");
        break;
    case 2:
        boss = boss2;
        renderNpc(boss.name, "Burn! Flame! Blaze! Hahaha");
        break;
    case 3:
        boss = boss3;
        renderNpc(boss.name, "Oh hi. Don't 'die' so quick :D");
        break;
    case 4:
        boss = boss4;
        renderNpc(boss.name, "Sha du lulu ~ oh --BI--");
        renderNpc(boss.name, "Why are you here??");
        break;
    case 5:
        boss = boss5;
        renderNpc(boss.name, "fACe tHe FeAR");
        break;
    case 6:
        boss = boss6;
        renderNpc(boss.name, "Hello! CAN I SWALLOW YOU?");
        break;
    case 7:
        boss = boss7;
        renderNpc(boss.name, "...I want your body(O r O)");
        break;
    case 8:
        boss = boss8;
        renderNpc(boss.name, "People call me the Death.");
        renderNpc(boss.name, "But I'd like to call myself...");
        renderNpc(boss.name, "a slave of death (;_;)");
        break;
    case 9:
        boss = boss9;
        renderNpc(boss.name, "GLORY TO THE AFTERLIFE!!");
        break;
    case 10:
        boss = boss10;
        renderNpc(boss.name, "Welcome to the Hell of Nightmare.");
        renderNpc(boss.name, "How much is your soul worth?");
        break;
    case 11:
        boss = boss11[0];
        renderNpc(boss.name, "");
        break;
    case 12:
    default:
        boss = boss11[1];
        break;
    }
    float mHp = boss.hp;
    fight(player, items, boss, mHp);
    if (player.hp <= 0) {
        cout << endl;
    } else if (mHp <= 0 && bossIndex == 12) {
        isEnd = true;
    } else if (mHp <= 0) {
        cout << "You kill " << boss.name << '!' << endl;
        cout << fixed << setprecision(2) << "You gain " << boss.exp << " XP!" << endl;
        player.exp += boss.exp;
        generateDrops(items);    //annouce what player got after battle save in generateDrops(item)
        upgradePlayer(player);
        if (bossIndex == 11)
            bossScreen(player, items, 12, isEnd);
        else
            cout << endl;
    }
}

Monster setUpMonster(Player player) {
    int monsterN = rand() % monsterSize;
    float hp = rand() % player.gameLevel + (rand() % 100) / 100.0 + (pow(0.4 * player.gameLevel, 2) / 2) + (monsters[monsterN].hp * pow(player.gameLevel, 0.5));    //monster's Hp range ~ gameLevel
    float damage = rand() % player.gameLevel + (pow(0.4 * player.gameLevel, 2) / 2) + (monsters[monsterN].damage * pow(player.gameLevel, 0.5));
    float rate = monsters[monsterN].rate - (player.gameLevel / 2);
    float exp = ((log(player.gameLevel) / log(2)) * (0.4 * player.gameLevel) + 5);
    // mExp reward and penalty based on the difference of level between player and game
    if (monsterN == 1)
        exp *= 1.5;
    if (player.gameLevel > (player.level + 3)) {
        exp *= 1.5;
    } else if (player.gameLevel < (player.level - 3)) {
        exp *= 0.2;
    }
    return {monsters[monsterN].name, hp, damage, rate, exp};
}

void fightScreen(Player &player, Item items[], bool &isEscape) {
    srand(time(NULL));
    int monsterN;
    if (rand() % 10 < 8)
        monsterN = 0;
    else
        monsterN = 1;
    Monster monster = setUpMonster(player);
    isEscape = fight(player, items, monster, monster.hp, true);
    if (player.hp > 0 && !isEscape) {
        cout << "You kill a monster!" << endl;
        cout << fixed << setprecision(2) << "You gain " << monster.exp << " XP!" << endl;
        player.exp += monster.exp;
        generateDrops(items);    //annouce what player got after battle save in generateDrops(item)
        upgradePlayer(player);
    }
    cout << endl;
}
