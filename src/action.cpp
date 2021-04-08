#include "action.h"
#include <iostream>
#include <thread>
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#else
#include "../lib/conio/conio.h"
#endif

using namespace std;

void action(Screen scr, Map map, Player player) {
    char key = ' ';
    while (key != 'q') {
        bool wall = false;
        key = getch();
        switch (key) {
        case 'w':
        case 'W':
            if (map.layout[player.y - 1][player.x] == '#')
                wall = true;
            else
                player.y--;
            break;
        case 'a':
        case 'A':
            if (map.layout[player.y][player.x - 1] == '#')
                wall = true;
            else
                player.x--;
            break;
        case 's':
        case 'S':
            if (map.layout[player.y + 1][player.x] == '#')
                wall = true;
            else
                player.y++;
            break;
        case 'd':
        case 'D':
            if (map.layout[player.y][player.x + 1] == '#')
                wall = true;
            else
                player.x++;
            break;
        default:
            scr.log = "Please input again";
        }
        scr.renderScreen(map, player);
        cout << map.layout[player.y][player.x] << endl;
        if (map.layout[player.y][player.x] == 'S') {
            map.fill();
            player.x = 1;
            player.y = 1;
        } else if (map.layout[player.y][player.x] == 'M') {
            scr.log = "Monster!";
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            fightScreen(player);
            map.removeMonster(player.x, player.y);
            key = getch();
        } else {
            map.update();
        }

        if (player.hp <= 0) {
            cout << "You die!\n Wanna restart?\ny - Yes     q - Quit game\n";
        }

        if (wall)
            scr.log = "There is a wall in my way";
        else {
            player.energy--;
            updateOnBuff(player);
        }
    }
}