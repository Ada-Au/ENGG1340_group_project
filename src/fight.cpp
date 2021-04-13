#include "fight.h"
#include "map.h"
#include "npc.h"
// #include "things.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void displayStats(float mHp, float mMaxHp, Player player) {
    int showMHp = mHp / mMaxHp * 50;
    int showHp = player.hp / player.maxHp * 50;
    std::cout << fixed << setprecision(2);
    std::cout << "Monster's HP: " << mHp << '/' << mMaxHp << endl;
    std::cout << '|' << setfill(' ') << string(showMHp, '*')
              << setw(50 - showMHp) << '|' << endl;
    renderNpc("monster", "");
    std::cout << "Player's HP: " << player.hp << '/' << player.maxHp << endl;
    std::cout << '|' << string(showHp, '*') << setfill(' ')
              << setw(50 - showHp) << '|' << endl;
    std::cout << "Player's Energy: " << player.energy << '/' << player.maxEnergy
              << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
    std::cout << "ACTION (please input number 1-4)" << endl
              << "1 - Attack               2 - Defence " << endl
              << "3 - Use Something        4 - Escape" << endl;
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
void bossScreen(Player &player, Item item[], int B, bool &isEnd) {
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
    float mHp = boss.hp, mDamage = boss.damage;
    char key;
    while (mHp >= 0 && player.hp >= 0) {
        displayStats(mHp, boss.hp, player);
        cin >> key;
        switch (key) {
        case '1':
            if (player.mp >= 0 || player.energy >= 0) {    //player can attack only either energy or mp is not 0
                float criticalHit = 1;
                string critical = "";
                if (rand() % 10 >= 1) {         // rate of player's hitting >= 90%
                    if (rand() % 100 <= 6) {    // rate of critical hit = 6%
                        criticalHit = 1.5;
                        critical = " critical";
                    }
                    mHp -= player.damage * criticalHit;    // should be weapon damage (<- update in backpage.cpp: exchangeWeapon(player))
                    if (player.energy > 0) {
                        // TODO update energy lose, and dont do damage if 0
                        // player.energy -= player.weaponEnergy;
                    }
                    if (player.mp > 0) {
                        // TODO update mp lose, and dont do damage if 0
                        // player.mp -= player.weaponMp;
                    }    // limit player's min.energy and min.mp to 0
                    // TODO should not do this: should check mp and en after deduct, if <0 then no damage
                    if (player.energy < 0)
                        player.energy = 0;
                    if (player.mp < 0)
                        player.mp = 0;
                    std::cout << "Player: Successfully make " << (player.damage * criticalHit) << critical + " damage." << endl;
                } else {
                    std::cout << "Player: Miss!" << endl;
                }
            } else {
                // TODO ???? what is this?
                cout << "You have no energy to attack now." << endl;
            }
            if (mHp > 0) {
                if (rand() % 100 >= boss.rate) {
                    std::cout << boss.name << ": Got you!" << endl;
                    if ((player.defense / 2) > mDamage)
                        std::cout << "Player: Successfully defense." << endl;
                    else
                        player.hp -= (mDamage - (player.defense / 2));
                    std::cout << boss.name << ": Got you! Make " << boss.damage - player.defense / 2 << " damage!" << endl;

                } else {
                    std::cout << boss.name << ": Miss!" << endl;
                }
            }
            break;

        case '2':
            if (mHp > 0) {
                if (rand() % 10 >= 2) {
                    if ((10 - player.defense) <= 0) {
                        std::cout << "Player: Successfully defense." << endl;
                    } else {
                        player.hp -= boss.damage - player.defense / 2;
                        std::cout << boss.name << ": Got you! Make " << boss.damage - player.defense / 2 << " damage!" << endl;
                    }
                } else {
                    std::cout << boss.name << ": Miss!" << endl;
                }
            }
            break;

        case '3':
            openBackpack(item, player);
            break;
            std::cout << endl;
        }
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
            generateThings(item);
            if (B == 11) {
                bossScreen(player, item, 12, isEnd);
            }
        }
    }
}

void fightScreen(Player &player, Item item[], bool &isEscape) {
    srand(time(NULL));
    int monsterN;
    float mHp, mMaxHp, mDamage, mRate, mExp;
    char key;
    setUpMonster(player, monsterN, mHp, mMaxHp, mRate, mExp);
    while (mHp > 0 && player.hp > 0) {
        mDamage = rand() % player.gameLevel + (2 * player.gameLevel + monsters[monsterN].damage);    // monster's damage range ~ gameLevel
        displayStats(mHp, mMaxHp, player);
        cin >> key;
        switch (key) {
        case '1':
            if (player.mp >= 0 || player.energy >= 0) {    //player can attack only either energy or mp is not 0
                float criticalHit = 1;
                string critical = "";
                if (rand() % 10 >= 1) {         // rate of player's hitting >= 90%
                    if (rand() % 100 <= 6) {    // rate of critical hit = 6%
                        criticalHit = 1.5;
                        critical = " critical";
                    }
                    mHp -= player.damage * criticalHit;    // should be weapon damage (<- update in backpage.cpp: exchangeWeapon(player))
                    if (player.energy > 0) {
                        // TODO update energy lose, and dont do damage if 0
                        // player.energy -= player.weaponEnergy;
                    }
                    if (player.mp > 0) {
                        // TODO update mp lose, and dont do damage if 0
                        // player.mp -= player.weaponMp;
                    }    // limit player's min.energy and min.mp to 0
                    // TODO should not do this: should check mp and en after deduct, if <0 then no damage
                    if (player.energy < 0)
                        player.energy = 0;
                    if (player.mp < 0)
                        player.mp = 0;
                    std::cout << "Player: Successfully make " << (player.damage * criticalHit) << critical + " damage." << endl;
                } else {
                    std::cout << "Player: Miss!" << endl;
                }
            } else {
                // TODO ???? what is this?
                cout << "You have no energy to attack now." << endl;
            }
            // monster strongness? (6)
            if (mHp > 0) {
                if (rand() % 100 >= monsters[monsterN].rate) {
                    std::cout << "Monster: Got you!" << endl;
                    if (player.defense / 2 > mDamage)
                        std::cout << "Player: Successfully defense." << endl;
                    else {
                        std::cout << "Monster: Make " << mDamage - player.defense / 2 << " damage!" << endl;
                        player.hp -= mDamage - player.defense / 2;
                    }

                } else {
                    std::cout << "Monster: Miss!" << endl;
                }
            }
            break;

        case '2':
            if (mHp > 0) {
                if (rand() % 10 >= 2) {
                    if ((mDamage - player.defense) <= 0) {
                        std::cout << "Player: Successfully defense." << endl;
                    } else {
                        player.hp -= mDamage - player.defense;
                        std::cout << "Monster: Got you! Make " << mDamage - player.defense << " damage!" << endl;
                    }
                } else {
                    std::cout << "Monster: Miss!" << endl;
                }
            }
            break;

        case '3':
            openBackpack(item, player);
            break;

        case '4':
            if (rand() % 100 < 30) {
                isEscape = true;
            } else {
                std::cout << "You didn't escape! Monster hit you with " << mDamage << '!' << endl;
                player.hp -= mDamage - player.defense;
            }
            break;
        }
        if (isEscape) {
            std::cout << "You escape!" << endl;
            break;
        }
        std::cout << endl;
    }

    if (player.hp <= 0) {
        std::cout << endl;    // "You die!" repeat in action.cpp
    } else if (!isEscape) {
        std::cout << "You kill the monster!" << endl;
        std::cout << fixed << setprecision(2) << "You gain " << mExp << " XP!" << endl;
        player.exp += mExp;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(item);
    }
}
