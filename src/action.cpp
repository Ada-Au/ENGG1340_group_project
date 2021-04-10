#include "action.h"
#include "backpack.h"
#include <iostream>
#include <thread>
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#else
#include "../lib/conio/conio.h"
#endif

using namespace std;

void action(Screen scr, Map map, Player player, Item item[], bool &isReplay) {
    char key = ' ';
    cin.ignore();
    while (key != 'q') {
        scr.renderScreen(map, player);
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
        case 'b':
        case 'B':
            openBackpack(item, player);
            break;
        case 'h':
        case 'H':
            printHelp();
            break;
        default:
            if (player.hp > 0)
                scr.log = "Please input again or press [H] for help";
        }

        if (map.layout[player.y][player.x] == 'S') {
            player.gameLevel++;
            bool isEnd = false;
            if (player.gameLevel % 5 == 0) {
                cout << player.gameLevel / 5;
                bossScreen(player, item, player.gameLevel / 5, isEnd);
                player.gameLevel++;
                if (isEnd) {
                    // TODO
                    cout << "You win the game! Wanna play again??\ny - Yes, what a fun game!\tn - No, I have better things to do with my life." << endl;
                    key = ' ';
                    while (key != 'n' && key != 'N' && key != 'y' && key != 'Y') {
                        cin >> key;
                        if (key == 'n' || key == 'N') {
                            break;
                        } else if (key == 'y' || key == 'Y') {
                            isReplay = true;
                        } else {
                            cout << "Please input again:\ny - Yes, what a fun game!\tn - No, I have better things to do with my life." << endl;
                            cin >> key;
                        }
                    }
                    break;
                }
            }
            map.fill();
            player.x = 1;
            player.y = 1;
        } else if (map.layout[player.y][player.x] == 'M') {
            scr.log = "Monster!";
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            bool isEscape = false;
            fightScreen(player, item, isEscape);
            if (!isEscape) {
                map.removeMonster(player.x, player.y);
            }
            key = getch();
        } else {
            map.update();
        }

        // TODO
        if (player.hp <= 0) {
            key = ' ';
            cout << "You die:( Wanna try again?\ny - Yes, I want to try again!\tn - No, I suck at this game." << endl;
            while (key != 'n' && key != 'N' && key != 'y' && key != 'Y') {
                cin >> key;
                if (key == 'n' || key == 'N') {
                    break;
                } else if (key == 'y' || key == 'Y') {
                    isReplay = true;
                } else {
                    cout << "Please input again:\ny - Yes, I want to try again!\tn - No, I suck at this game." << endl;
                    cin >> key;
                }
            }
            break;
        }

        if (wall)
            scr.log = "There is a wall in my way";
        else {
            if (player.energy > 0)
                player.energy--;
            else
                player.energy = 0;
            updateOnBuff(player);
        }
    }
}