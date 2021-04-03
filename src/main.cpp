#include "action.h"
#include "map.h"
#include "player.h"
#include "screen.h"
#include "setup.h"
#include <iostream>

using namespace std;

int main() {
    char temp = ' ';
    Screen scr;
    Map map;
    Player player;

    setupScreen(player);

    map.fill();
    scr.renderScreen(map, player);
    action(scr, map, player);

    // std::cout << "COLOR" << std::endl
    //           << BLACK << " BLACK" << RED << " RED" << GREEN << " GREEN"
    //           << YELLOW << " YELLOW" << BLUE << " BLUE" << MAGENTA << " MAGENTA"
    //           << CYAN << " CYAN" << WHITE << " WHITE" << std::endl
    //           << BOLDBLACK << " BLACK" << BOLDRED << " RED" << BOLDGREEN
    //           << " GREEN" << BOLDYELLOW << " YELLOW" << BOLDBLUE << " BLUE"
    //           << BOLDMAGENTA << " MAGENTA" << BOLDCYAN << " CYAN" << BOLDWHITE
    //           << " WHITE" << RESET << std::endl;
    return 0;
}