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
        int isPlay = 1;    // determine close game or not
        isReplay = false;
        player = Player();
        vector<Item> items;
        menu(isPlay, player, items);
        if (isPlay == 3) {
            isReplay = true;
            continue;
        }    // todo return to menu screen if no file
        if (isPlay == 0)
            return 0;
        else {
            setupScreen(player, isPlay);
            if (!isPlay)
                return 0;
            boatScreen();
        }
        map.fill();
        cout << "Start your adventure!" << endl;
        action(scr, map, player, items, isReplay);
    }
    return 0;
}

// std::cout << "COLOR" << std::endl
//           << BLACK << " BLACK" << RED << " RED" << GREEN << " GREEN"
//           << YELLOW << " YELLOW" << BLUE << " BLUE" << MAGENTA << " MAGENTA"
//           << CYAN << " CYAN" << WHITE << " WHITE" << std::endl
//           << BOLDBLACK << " BLACK" << BOLDRED << " RED" << BOLDGREEN
//           << " GREEN" << BOLDYELLOW << " YELLOW" << BOLDBLUE << " BLUE"
//           << BOLDMAGENTA << " MAGENTA" << BOLDCYAN << " CYAN" << BOLDWHITE
//           << " WHITE" << RESET << std::endl;