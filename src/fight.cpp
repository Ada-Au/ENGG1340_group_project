#include "fight.h"
#include <iomanip>
#include <time.h>

#include <iostream>

using namespace std;
void fightScreen(Player player) {
    srand(time(NULL));
    int monsterN = rand() % monsterSize;
    float Mhp = monsters[monsterN].hp;

    cout << "player.name: " << player.name << endl;

    // while (Mhp != 0 && player.hp != 0) {
    //     cout << '|' << string('*', Mhp / monsters[monsterN].hp) << setfill(' ')
    //          << setw(50) << '|';
    //     renderNpc("", "monster");
    //     cout << '|' << string('*', player.hp / 100) << setfill(' ') << setw(50)
    //          << '|';
    // }
}
