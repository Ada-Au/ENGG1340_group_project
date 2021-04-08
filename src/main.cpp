#include "action.h"
#include "map.h"
#include "player.h"
#include "screen.h"
#include "setup.h"
#include "homepage.h"
#include "backpack.h"
#include <iostream>

using namespace std;

int main() {
    char temp = ' ';
    Screen scr;
    Map map;
    Player player;
    Item item[maxSpace] = {"", 0};
    int flag = 1;   // determine close game or not
    
    menu(flag);
    if (flag == 0)
        return 0;
    setupScreen(player, flag);
    if (flag == 0)
        return 0;
    map.fill();
    cout << "Start your adventure!" << endl;
    scr.renderScreen(map, player);
    action(scr, map, player, item);

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