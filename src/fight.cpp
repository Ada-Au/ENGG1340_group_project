#include "fight.h"
#include <iomanip>
#include <time.h>
#include <math.h>

#include <iostream>

using namespace std;

void setUpMonster(Player player, int &monsterN, float &mHp, float &mMaxHp, float &mDamage, float &mRate, float &mExp) {
    monsterN = rand() % monsterSize;
    mHp = rand () % player.gameLevel + ( pow(0.4 * player.gameLevel, 2) / 2 ) + ( monsters[monsterN].hp * pow(player.gameLevel, 0.5) ); //monster's Hp range ~ gameLevel
    mMaxHp = mHp;
    mDamage = rand() % player.gameLevel + (2 * player.gameLevel + monsters[monsterN].damage);                                         // monster's damage range ~ gameLevel
    mRate = monsters[monsterN].rate - (player.gameLevel / 2);
    mExp = ( ( log(player.gameLevel) / log(2) ) * ( 0.4 * player.gameLevel ) + 5);
    // mExp reward and penalty based on the difference of level between player and game
    if (monsterN == 1)
        mExp *= 1.5;
    if (player.gameLevel > (player.level + 3) ) {           
        mExp *= 1.5;
    } else if (player.gameLevel < (player.level - 3) ){
        mExp *= 0.2;
    }                                                          
}

void fightScreen(Player &player, Item item[]) {
    srand(time(NULL));
    int monsterN ;
    float mHp, mMaxHp, mDamage, mRate, mExp;    
    char key;
    setUpMonster(player, monsterN, mHp, mMaxHp, mDamage, mRate, mExp);
    while (mHp >= 0 && player.hp >= 0) {
        int showMHp = mHp / mMaxHp * 50;
        std::cout << fixed << setprecision(2);
        std::cout << "Monster's HP: " << mHp << '/' << mMaxHp << endl;
        std::cout << '|' << setfill(' ') << string(showMHp, '*')
                  << setw(50 - showMHp) << '|' << endl;
        renderNpc("monster", "");
        std::cout << "Player's HP: " << player.hp << '/' << player.maxHp << endl;
        std::cout << '|' << string(player.hp / 2, '*') << setfill(' ')
                  << setw(50 - player.hp / 2) << '|' << endl;
        std::cout << "Player's Energy: " << player.energy << '/' << player.maxEnergy
                  << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
        std::cout << "ACTION (please input number 1-4)" << endl
                  << "1 - Attack               2 - Defence " << endl
                  << "3 - Use Something        4 - Escape" << endl;
        cin >> key;
        switch (key) {
        case '1':
            if (player.mp >= 0 || player.energy >= 0) {    //player can attack only either energy or mp is not 0
                float criticalHit = 1;
                string critical = "";
                if (rand() % 10 >= 1) {                    // rate of player's hitting >= 90%
                    if (rand() % 100 <= 6) {               // rate of critical hit = 6%
                        criticalHit = 1.5;
                        critical = " critical";
                    }
                    mHp -= player.damage * criticalHit;          // should be weapon damage (<- update in backpage.cpp: exchangeWeapon(player))
                    if (player.energy > 0)
                        player.energy -= player.weaponEnergy;    
                    if (player.mp > 0)                           // limit player's min.energy and min.mp to 0
                        player.mp -= player.weaponMp;
                    if (player.energy < 0)
                        player.energy = 0;
                    if (player.mp < 0)
                        player.mp = 0;
                    std::cout << "Player: Successfully make " << (player.damage * criticalHit) << critical + " damage." << endl;
                } else {
                    std::cout << "Player: Miss!" << endl;
                }
            } else {
                cout << "You have no energy to attack now." << endl;
            }
            // monster strongness? (6)
            if (mHp > 0) {
                if (rand() % 100 >= monsters[monsterN].rate) {
                    std::cout << "Monster: Got you!" << endl;
                    if ( (player.defense / 2) > mDamage)
                        std::cout << "Player: Successfully defense." << endl;
                    else
                        player.hp -= (mDamage - (player.defense / 2));
                    
                } else {
                    std::cout << "Monster: Miss!" << endl;
                }
            }
            break;

        case '2':
            if (mHp > 0) {
                if (rand() % 10 >= 2) {
                    if ((10 - player.defense) <= 0) {
                        std::cout << "Player: Successfully defense." << endl;
                    } else {
                        player.hp -= (10 - player.defense);
                        std::cout << "Monster: Got you!" << endl;
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
            break;
        }
        std::cout << endl;
    }
    if (player.hp <= 0) {
        std::cout << endl;    // "You die!" repeat in action.cpp
    } else {
        std::cout << "You kill the monster!" << endl;
        std::cout << fixed << setprecision(2) << "You gain "  << mExp << " XP!" << endl;
        player.exp += mExp;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(item);
    }
}
