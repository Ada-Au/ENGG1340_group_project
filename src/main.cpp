#include "map.h"
#include "player.h"
#include "screen.h"
#include "action.h"
#include <iostream>

int main()
{
    char key = ' ';
    Screen scr;
    Map map;
    Player player;

    map.fill();
    scr.renderScreen(map, player);
    action(scr, map, player);

    return 0;
}