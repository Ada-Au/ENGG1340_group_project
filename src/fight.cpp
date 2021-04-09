#include "fight.h"
#include <iomanip>
#include <time.h>

#include <iostream>

using namespace std;

void fightScreen(Player &player, Item item[]) {
    srand(time(NULL));
    int monsterN = rand() % monsterSize;
    float mHp = monsters[monsterN].hp;
    char key;
    while (mHp >= 0 && player.hp >= 0) {
        int showMHp = mHp / monsters[monsterN].hp * 50;
        std::cout << "Monster's HP: " << mHp << '/' << monsters[monsterN].hp << endl;
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
            // need to get player weapon first...
            if (player.mp >= 0 || player.energy >= 0) {    //player can attack only either energy or mp is not 0
                float criticalHit = 1;
                string critical = "";
                if (rand() % 10 >= 1) {         // rate of player's hitting
                    if (rand() % 100 <= 6) {    // rate of critical hit
                        criticalHit = 1.5;
                        critical = " critical";
                    }
                    mHp -= player.damage * criticalHit;    // should be weapon damage (<- update in backpage.cpp: exchange(player))
                    if (player.energy > 0)
                        player.energy -= player.weaponEnergy;    // limit player's min energy and min mp to 0
                    if (player.mp > 0)
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
                cout << "You have no energy to attack now" << endl;
            }
            // monster strongness? (6)
            if (mHp > 0) {
                if (rand() % 100 >= monsters[monsterN].rate) {
                    std::cout << "Monster: Got you!" << endl;
                    if ( (player.defense / 2) > monsters[monsterN].damage)
                        std::cout << "Player: Successfully defense." << endl;
                    else
                        player.hp -= (monsters[monsterN].damage - (player.defense / 2));
                    
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
        // std::cout << "You die!" << endl;
        std::cout << endl;    // "You die!" repeat in action.cpp
    } else {
        std::cout << "You kill the monster!" << endl;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(item);
    }
}
