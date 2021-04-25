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
        // clear screen before game start
        if (ISWINDOW)
            std::system("cls");
        else
            std::system("clear");
        // show menu screen to allow player to start or load game
        menu(isPlay, player, items);
        // restart game
        if (isPlay == 3) {
            isReplay = true;
            continue;
        }
        // end game
        if (isPlay == 0)
            return 0;
        // Do not show these screen when player load screen
        else if (isPlay != 2) {
            setupScreen(player, isPlay);
            if (isPlay == 0)
                return 0;
            boatScreen();
        }
        // start game
        map.fill();
        cout << endl
             << "Start your adventure!" << endl;
        action(scr, map, player, items, isReplay);
    }
    return 0;
}
