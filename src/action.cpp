#include "action.h"
#include "backpack.h"
#include <iostream>
#include <thread>
#include <iomanip>
#include <stdlib.h>
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
            cin.get();
            break;
        default:
            if (player.hp > 0)
                scr.log = "Please input again or press [H] for help";
        }

        if (map.layout[player.y][player.x] == 'S') {
            player.gameLevel++;
            bool isEnd = true;
            if (player.gameLevel % 5 == 0) {
                cout << player.gameLevel / 5;
                // bossScreen(player, item, player.gameLevel / 5, isEnd);
                player.gameLevel++;
                if (isEnd) {
                    ending();
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
            scr.renderScreen(map, player);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            bool isEscape = false;
            fightScreen(player, item, isEscape);
            if (!isEscape) {
                map.removeMonster(player.x, player.y);
            }
            key = getch();
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
        clearScreen();
        }
    }
}

void tryAgain(string str, bool &isReplay) {
    string choice;
    // if (ISWINDOW)                    //fix after adding ending() :D
    //     cin.ignore();
    do {
        getline(cin, choice);
        if (choice[1] == '\0' && (choice[0] == 'n' || choice[0] == 'N')) {
            isReplay = false;
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

void printBoatsInEnding() {
    string boats[11] = {"1 - trash", "0 G",
                        "2 - wooden boat", "(Sold out)",
                        "3 - iron boat", "(Sold out)",
                        "4 - golden boat", "10,000 G",
                        "5 - EPIC DIAMOND BOAT", "999,999,999 G",
                        ""};
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            cout << "\nBoats" << setfill(' ') << setw(36) << "Price" << endl;
        if (i % 2 == 0)
            cout << boats[i] << setfill(' ') << setw(40 - boats[i].length());
        else
            cout << boats[i] << endl;
    }
}

void tryAgainInEnding(string &choice, bool &choosing){       //To-do: adding condition -> player's property
    printBoatsInEnding();
    getline(cin, choice);
    while (choosing){
        if (choice[1] == '\0' && choice[0] == '1') {
            renderNpc("charon", "You're broke before you came?");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "What did you do in hell???");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Are you a brainless slime,");
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            renderNpc("charon", "that can only jump around??");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Go get a job and make money!!");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Bad Ending: Working in Hell.\n";
            choosing = false;
            break;
        } else if (choice[1] == '\0' && (choice[0] == '2' || choice[0] == '3') ) {
            renderNpc("charon", "Can't you see it is SOLD OUT??");
            cout << "Enter again: ";
            tryAgainInEnding(choice, choosing);
            break;
        } else if (choice[1] == '\0' && choice[0] == '4') {
            renderNpc("charon", "Nice, you got enough money this time.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "golden boat x 1 GET!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            renderNpc("charon", "Here is your boat.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Sail it to the end of the river.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Enjoy your afterlife :)");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Normal Ending: Having an Afterlife.\n";
            choosing = false;
            break;
        } else if (choice[1] == '\0' && choice[0] == '5') {
            renderNpc("charon", "You work real hard.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Proud of you for buying it. :D");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Here is your boat.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("charon", "Sail it to the Heaven, boy.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Good Ending: Going to the Heaven.\n";
            choosing = false;
            break;
        } else {
            renderNpc("charon", "No such choice.");
            tryAgainInEnding(choice, choosing);
            break;
        }        
    }
}

void ending() {
    string choice = " ";
    bool choosing = true;
    cout << "At the end, you defeated Hades, the Lord of Hell, through out your endless, extraordinary journey here.\n";
    cout << "You feel drained out after such long battles, playing around the cold and dark, danger and monsters\n";
    cout << "Closing your eyes, you were just desperate for a moment of rest...\n";
    cout << "A whistle passes into your ears, a familiar voice...";
    cin.get();
    cout << "\n\"Oh, you come back to buy boats?\"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    renderNpc("charon", "Many people come and buy mt boats.");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    renderNpc("charon", "Which one do you want?");
    tryAgainInEnding(choice, choosing);
}
