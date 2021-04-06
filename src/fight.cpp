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
        std::cout << "Player's HP" << endl;
        std::cout << '|' << string(player.hp / 2, '*') << setfill(' ')
             << setw(50 - player.hp / 2) << '|' << endl;
        std::cout << "Player's Energy: " << player.energy << '/' << player.maxEnergy
             << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
        std::cout << "ACTION (please input number 1-4)" << endl
             << "1 - Attack               2 - Defence " << endl
             << "3 - Use Something        4 - Escape" << endl;
        cin >> key;
        switch(key){
            case '1':
                // need to get player weapon first...
                if (rand() % 10 >= 0) {    // rate of hitting
                    mHp -= player.damage;              // should be weapon damage (<- update in exchange(player))
                    std::cout << "Player: Successfully make " << player.damage << " damage." << endl;
                } else {
                    std::cout << "Player: Miss!" << endl;
                }
                // monster strongness? (6)
                if (mHp > 0) {
                    if (rand() % 10 >= 6) {
                        player.hp -= 10;
                        std::cout << "Monster: Got you!" << endl;
                    } else {
                        std::cout << "Monster: Miss!" << endl;
                    }
                }
                break;
            
            case '2':
                if (mHp > 0) {
                    if (rand() % 10 >= 2) {
                        if ((10 - player.defense) <= 0){
                            std::cout << "Player: Successfully defense." << endl;                            
                        } else{
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
        // if (key == '1') {
        //     // need to get player weapon first...
        //     if (rand() % 10 >= 0) {    // rate of hitting
        //         mHp -= 2;              // should be weapon damage
        //         cout << "Player: Successfully make " << 2 << " damage." << endl;
        //     } else {
        //         cout << "Player: Miss!" << endl;
        //     }
        //     // monster strongness? (6)
        //     if (mHp > 0) {
        //         if (rand() % 10 >= 6) {
        //             player.hp -= 10;
        //             cout << "Monster: Got you!" << endl;
        //         } else {
        //             cout << "Monster: Miss!" << endl;
        //         }
        //     }
        // }
        std::cout << endl;
    }

    if (player.hp <= 0) {
        std::cout << "You die!" << endl;
    } else {
        std::cout << "You kill the monster!" << endl;
        upgradePlayer(player);
        //annouce what player got after battle save in generateThings(item)
        generateThings(item);
    }
}
