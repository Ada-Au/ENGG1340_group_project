#include "fight.h"
#include <iomanip>
#include <time.h>

#include <iostream>

using namespace std;
void fightScreen(Player player) {
    srand(time(NULL));
    int monsterN = rand() % monsterSize;
    float mHp = monsters[monsterN].hp;
    char key;
    while (mHp != 0 && player.hp != 0) {
        cout << "Monster's HP: " << mHp << '/' << monsters[monsterN].hp << endl;
        cout << '|' << setfill(' ')
             << string(mHp / monsters[monsterN].hp * 50, '*')
             << setw(50 - mHp / monsters[monsterN].hp * 50) << '|' << endl;
        renderNpc("monster", "");
        cout << "Player's HP" << endl;
        cout << '|' << string(player.hp / 2, '*') << setfill(' ')
             << setw(50 - player.hp / 2) << '|';
        cin >> key;
        cout << key;
    }
}
