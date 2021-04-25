#include "action.h"
#include "backpack.h"
#include "homepage.h"
#include "map.h"
#include "player.h"
#include "screen.h"
#include "setup.h"
#include "shop.h"
#include <iostream>

using namespace std;

int main() {
    Screen scr;
    Map map;
    Player player;
    bool isReplay = true;
    while (isReplay) {
        int isPlay = 1;    // determine game status
        isReplay = false;
        player = Player();
        vector<Item> items;
        // menu(isPlay, player, items);
        // if (isPlay == 3) {
        //     isReplay = true;
        //     continue;
        // }
        // if (isPlay == 0)
        //     return 0;
        // else if (isPlay != 2) {
        //     setupScreen(player, isPlay);
        //     if (isPlay == 0)
        //         return 0;
        //     boatScreen();
        // }
        map.fill();
        cout << endl
             << "Start your adventure!" << endl;
        action(scr, map, player, items, isReplay);
    }
    return 0;
}
