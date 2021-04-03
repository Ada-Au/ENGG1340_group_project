#include "action.h"
#include "backpack.h"
#include <thread>
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#else
#include "../lib/conio/conio.h"
#endif
struct items item[maxSpace];
void action(Screen scr, Map map, Player player) {

    char key = ' ';
    while (key != 'q') {
        bool wall = false;
        key = getch();
        switch (key) {
        case 'w':
            if (map.layout[player.y - 1][player.x] == '#')
                wall = true;
            else
                player.y--;
            break;
        case 'a':
            if (map.layout[player.y][player.x - 1] == '#')
                wall = true;
            else
                player.x--;
            break;
        case 's':
            if (map.layout[player.y + 1][player.x] == '#')
                wall = true;
            else
                player.y++;
            break;
        case 'd':
            if (map.layout[player.y][player.x + 1] == '#')
                wall = true;
            else
                player.x++;
            break;
        case 'b':
            backpack( item[maxSpace] );
            break;
            
        default:
            scr.log = "Please input again";
        }

        if (map.layout[player.y][player.x] == 'M') {
            scr.log = "Monster";
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "into fight screen";
        } else {
            scr.renderScreen(map, player);
        }

        if (wall)
            scr.log = "There is a wall in my way";
        else {
            player.energy--;
            map.update();
        }
    }
}