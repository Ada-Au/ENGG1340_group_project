#include "action.h"
#include "backpack.h"
#include <iostream>
#include <thread>
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#define ISWINDOW true
#else
#include "../lib/conio/conio.h"
#define ISWINDOW false
#endif

using namespace std;

void action(Screen scr, Map map, Player player, Item item[], bool &isReplay) {
    char key = ' ';
    scr.renderScreen(map, player);
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
        case 'b':
        case 'B':
            openBackpack(item, player);
            break;
        case 'h':
        case 'H':
            printHelp();
            cin.get();
            break;
        default:
            if (player.hp > 0)
                scr.log = "Please input again or press [H] for help";
        }

        clearScreen();
        scr.renderScreen(map, player);

        if (map.layout[player.y][player.x] == 'S') {
            player.gameLevel++;
            bool isEnd = false;
            if (player.gameLevel % 5 == 0) {
                cout << player.gameLevel / 5;
                bossScreen(player, item, player.gameLevel / 5, isEnd);
                player.gameLevel++;
                if (isEnd) {
                    cout << "You win the game! Wanna play again??\ny - Yes, what a fun game!\tn - No, I have better things to do with my life." << endl;
                    tryAgain("Please input again:\ny - Yes, what a fun game!\tn - No, I have better things to do with my life.", isReplay);
                    break;
                }
            }
            map.fill();
            player.x = 1;
            player.y = 1;
        } else if (map.layout[player.y][player.x] == 'M') {
            scr.log = "Monster!";
            clearScreen();
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            bool isEscape = false;
            clearScreen();
            fightScreen(player, item, isEscape);
            if (!isEscape) {
                map.removeMonster(player.x, player.y);
            }
            scr.renderScreen(map, player);
            cin.ignore();
        } else {
            map.update();
        }

        if (player.hp <= 0) {
            cout << "You die:( Wanna try again?\ny - Yes, I want to try again!\tn - No, I suck at this game." << endl;
            tryAgain("Please input again:\ny - Yes, I want to try again!\tn - No, I suck at this game.", isReplay);
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

void tryAgain(string str, bool &isReplay) {
    string choice;
    cin.ignore();
    do {
        getline(cin, choice);
        if (choice[1] == '\0' && (choice[0] == 'n' || choice[0] == 'N')) {
            break;
        } else if (choice[1] == '\0' && (choice[0] == 'y' || choice[0] == 'Y')) {
            isReplay = true;
            break;
        } else {
            cout << str << endl;
            choice = " ";
        }
    } while (choice[0] != 'n' && choice[0] != 'N' && choice[0] != 'y' && choice[0] != 'Y');
}

void clearScreen() {
    if (ISWINDOW)
        std::system("cls");
    else
        std::system("clear");
}
