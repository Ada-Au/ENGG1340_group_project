#include "action.h"
#include "../lib/conio/conio.h"
#include <thread>

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

        if (map.layout[player.y][player.x] == 'M')
        {
            scr.log = "Monster";
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "into fight screen";
        }
        else
        {
            scr.renderScreen(map, player);
        }
        map.update();
    }
}