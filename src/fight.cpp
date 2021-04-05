#include "fight.h"
#include "backpack.h"
#include "things.h"
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
        cout << "Monster's HP: " << mHp << '/' << monsters[monsterN].hp << endl;
        cout << '|' << setfill(' ') << string(showMHp, '*')
             << setw(50 - showMHp) << '|' << endl;
        renderNpc("monster", "");
        cout << "Player's HP" << endl;
        cout << '|' << string(player.hp / 2, '*') << setfill(' ')
             << setw(50 - player.hp / 2) << '|' << endl;
        cout << "Player's Energy: " << player.energy << "/100" 
             << setw(map_width - 40) << "Player's MP: " << player.mp << '/' << player.maxMp << endl;
        cout << "ACTION (please input number 1-4)" << endl
             << "1 - Attack               2 - Defence " << endl
             << "3 - Use Something        4 - Escape" << endl;
        cin >> key;
        switch(key){
            case '1':
                // need to get player weapon first...
                if (rand() % 10 >= 0) {    // rate of hitting
                    mHp -= 2;              // should be weapon damage
                    cout << "Player: Successfully make " << 2 << " damage." << endl;
                } else {
                    cout << "Player: Miss!" << endl;
                }
                // monster strongness? (6)
                if (mHp > 0) {
                    if (rand() % 10 >= 6) {
                        player.hp -= 10;
                        cout << "Monster: Got you!" << endl;
                    } else {
                        cout << "Monster: Miss!" << endl;
                    }
                }
                break;
            
            case '2':
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
        cout << endl;
    }

    if (player.hp == 0) {
        cout << "You die!" << endl;
    } else {
        cout << "You kill the monster!" << endl;
        generateThings(item);
        //need to annouce what player got after battle?
    }
}
