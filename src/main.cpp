#include "map.h"
#include "player.h"
#include "screen.h"
#include <iostream>
#include "../lib/conio/conio.h"

void waitKey(char &key)
{
    key = getch();
}

int main()
{
    char key = ' ';
    Screen scr;
    Map map;
    Player player;

    map.fill();
    scr.renderScreen(map, player);

    while (key != 'q')
    {
        waitKey(key);
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
        //Rendering the screen
        scr.renderScreen(map, player);
    }
    return 0;
}