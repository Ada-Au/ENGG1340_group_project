#include "action.h"
#include "../lib/conio/conio.h"

void action(Screen scr, Map map, Player player)
{
    char key = ' ';
    while (key != 'q')
    {
        key = getch();
        switch (key)
        {
        case 'w':
            if (map.layout[player.y - 1][player.x] == '#')
                scr.log = "There is a wall in my way";
            else
                player.y--;
            break;
        case 'a':
            if (map.layout[player.y][player.x - 1] == '#')
                scr.log = "There is a wall in my way";
            else
                player.x--;
            break;
        case 's':
            if (map.layout[player.y + 1][player.x] == '#')
                scr.log = "There is a wall in my way";
            else
                player.y++;
            break;
        case 'd':
            if (map.layout[player.y][player.x + 1] == '#')
                scr.log = "There is a wall in my way";
            else
                player.x++;
            break;
        default:
            scr.log = "Please input again";
        }
        scr.renderScreen(map, player);
    }
}