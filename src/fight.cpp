#include "fight.h"
#include "map.h"
#include "npc.h"
// #include "things.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void displayStats(float mHp, float mMaxHp, Player player, string mName, bool escape) {
    int showMHp = mHp / mMaxHp * 50;
    int showHp = player.hp / player.maxHp * 50;
    std::cout << fixed << setprecision(2);
    std::cout << "Monster's HP: " << mHp << '/' << mMaxHp << endl;
    std::cout << '|' << setfill(' ') << string(showMHp, '*')
              << setw(50 - showMHp) << '|' << endl;
    renderNpc(mName, "");
    std::cout << "Player's HP: " << player.hp << '/' << player.maxHp << endl;
    std::cout << '|' << string(showHp, '*') << setfill(' ')
              << setw(50 - showHp) << '|' << endl;
    std::cout << "Player's Energy: " << player.energy << '/' << player.maxEnergy
              << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
    std::cout << "ACTION (please input number 1-4)" << endl
              << "1 - Attack               2 - Defence " << endl
              << "3 - Use Something";
    if (escape)
        std::cout << "        4 - Escape";
    std::cout << endl;
}

void setUpMonster(Player player, int &monsterN, float &mHp, float &mMaxHp, float &mRate, float &mExp) {
    monsterN = rand() % monsterSize;
    mHp = rand() % player.gameLevel + (pow(0.4 * player.gameLevel, 2) / 2) + (monsters[monsterN].hp * pow(player.gameLevel, 0.5));    //monster's Hp range ~ gameLevel
    mMaxHp = mHp;
    mRate = monsters[monsterN].rate - (player.gameLevel / 2);
    mExp = ((log(player.gameLevel) / log(2)) * (0.4 * player.gameLevel) + 5);
    // mExp reward and penalty based on the difference of level between player and game
    if (monsterN == 1)
        mExp *= 1.5;
    if (player.gameLevel > (player.level + 3)) {
        mExp *= 1.5;
    } else if (player.gameLevel < (player.level - 3)) {
        mExp *= 0.2;
    }
}

bool fight(Player &player, Item items[], Monster monster, float &mHp, bool escape = false) {
    float mDamage = monster.damage;
    char key;
    while (mHp > 0 && player.hp > 0) {
        displayStats(mHp, monster.hp, player, monster.name, escape);
        cin >> key;
        switch (key) {
        case '1':
            if (rand() % 10 >= 1) {    // rate of player's hitting >= 90%
                float criticalHit = 1;
                bool critical = false;
                if (rand() % 100 <= 6) {    // rate of critical hit = 6%
                    criticalHit = 1.5;
                    critical = true;
                }
                if (player.energy - player.weapon.energy > 0 && player.mp - player.weapon.mp > 0) {
                    player.energy -= player.weapon.energy;
                    player.mp -= player.weapon.mp;
                    std::cout << "Player: Successfully make " << (player.weapon.damage * criticalHit);
                    if (critical)
                        std::cout << " critical";
                    std::cout << " damage." << endl;
                    mHp -= player.weapon.damage * criticalHit;
                } else {
                    cout << "You have no energy to attack now." << endl;
                }
            } else {
                std::cout << "Player: Miss!" << endl;
            }

            if (mHp > 0) {
                if (rand() % 100 >= monster.rate) {
                    std::cout << monster.name << ": Got you!" << endl;
                    if ((player.defense / 2) > monster.damage)
                        std::cout << "Player: Successfully defense." << endl;
                    else
                        player.hp -= (monster.damage - (player.defense / 2));
                    std::cout << monster.name << ": Got you! Make " << monster.damage - player.defense / 2 << " damage!" << endl;

                } else {
                    std::cout << monster.name << ": Miss!" << endl;
                }
            }
            break;

        case '2':
            if (mHp > 0) {
                if (rand() % 10 >= 2) {
                    if ((10 - player.defense) <= 0) {
                        std::cout << "Player: Successfully defense." << endl;
                    } else {
                        player.hp -= monster.damage - player.defense / 2;
                        std::cout << monster.name << ": Got you! Make " << monster.damage - player.defense / 2 << " damage!" << endl;
                    }
                } else {
                    std::cout << monster.name << ": Miss!" << endl;
                }
            }
            break;

        case '3':
            openBackpack(items, player);
            break;
            std::cout << endl;

        case '4':
            if (escape) {
                if (rand() % 100 < 30) {
                    return true;
                } else {
                    std::cout << "You didn't escape! " << monster.name << " hit you with " << mDamage << '!' << endl;
                    player.hp -= mDamage - player.defense;
                }
                break;
            }
        }
    }
    return false;
}

void bossScreen(Player &player, Item items[], int B, bool &isEnd) {
    srand(time(NULL));
    Monster boss;
    switch (B) {
    case 1:
        boss = boss1;
        renderNpc(boss.name, "Hello! Don't kill me please QwQ");
        break;
    case 2:
        boss = boss2;
        break;
    case 3:
        boss = boss3;
        break;
    case 4:
        boss = boss4;
        break;
    case 5:
        boss = boss5;
        break;
    case 6:
        boss = boss6;
        break;
    case 7:
        boss = boss7;
        break;
    case 8:
        boss = boss8;
        break;
    case 9:
        boss = boss9;
        break;
    case 10:
        boss = boss10;
        break;
    case 11:
        boss = boss11[0];
        break;
    case 12:
    default:
        boss = boss11[1];
        break;
    }
    float mHp = boss.hp;
    fight(player, items, boss, mHp);
    if (player.hp <= 0) {
        std::cout << endl;
    } else if (mHp <= 0 && B == 12) {
        isEnd = true;
    } else if (mHp <= 0) {
        std::cout << "You kill " << boss.name << '!' << endl;
        std::cout << fixed << setprecision(2) << "You gain " << boss.exp << " XP!" << endl;
        player.exp += boss.exp;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(items);
        if (B == 11)
            bossScreen(player, items, 12, isEnd);
        else
            cout << endl;
    }
}

void fightScreen(Player &player, Item items[], bool &isEscape) {
    srand(time(NULL));
    int monsterN = rand() % 2;
    float mHp = monsters[monsterN].hp;
    // setUpMonster(player, monsterN, mHp, mMaxHp, mRate, mExp);
    fight(player, items, monsters[monsterN], mHp, true);

    if (player.hp <= 0) {
        std::cout << endl;    // "You die!" repeat in action.cpp
    } else if (!isEscape) {
        std::cout << "You kill the monster!" << endl;
        std::cout << fixed << setprecision(2) << "You gain " << monsters[monsterN].exp << " XP!" << endl;
        player.exp += monsters[monsterN].exp;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(items);
        cout << endl;
    }
}
