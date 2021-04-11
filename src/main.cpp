#include "action.h"
#include "backpack.h"
#include "homepage.h"
#include "map.h"
#include "player.h"
#include "screen.h"
#include "setup.h"
#include <iostream>

using namespace std;

int main() {
    Screen scr;
    Map map;
    Player player;
    // Item item[maxSpace] = {"", 0};
    bool isReplay = true;
    while (isReplay) {
        int isPlay = 1;    // determine close game or not
        isReplay = false;
        player = Player();
        Item item[maxSpace] = {"", 0};
        menu(isPlay);
        // if (isPlay == 0)
        //     return 0;
        // else if (isPlay == 2)   // To-do: load files
        //     return 0;         
        // setupScreen(player, isPlay);
        // if (isPlay == 0)
        //     return 0;
        // boatScreen(); 
        map.fill();
        cout << "Start your adventure!" << endl;
        scr.renderScreen(map, player);
        action(scr, map, player, item, isReplay);
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