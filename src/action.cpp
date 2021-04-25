#include "action.h"
#include "fight.h"
#include "npc.h"
#include "saving.h"
#include "shop.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <thread>

// Include conio for Windows and a web version of the code for Mac and Linux
// As conio is a library only work in Windows system
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#else
#include "../lib/conio/conio.h"
#endif

using namespace std;

void action(Screen scr, Map map, Player player, vector<Item> &items, bool &isReplay) {
    char key = ' ';
    scr.log = "Press WASD to move or press [H] for help";
    while (key != 'q') {
        bool wall = false, isValid = true;
        key = getch();    // Get char when player press any char without newline to allow easy navigation in map
        // Clean screen everytime map is updated
        // To avoid mutiple maps and the same time and diffcult of keeping track of player pos
        clearScreen();
        // handle player's input and prevent player walking into walls
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
            openBackpack(items, player);
            break;
        case 'h':
        case 'H':
            printHelp();
            cin.get();
            break;
        default:
            // Handle invalid input and tell player to input again
            if (player.hp > 0)
                scr.log = "Please input again or press [H] for help";
            // To prevent input to be handled
            isValid = false;
        }
        // Render screen to let player to see effect of input
        scr.renderScreen(map, player);

        if (isValid) {
            // Check for is player on stair
            if (map.layout[player.y][player.x] == 'S') {
                player.gameLevel++;
                string buffName = allBuffs[rand() % maxBuff].name;
                cout << GREEN << "Another adventurer give you a blessing of " << buffName << "." << endl
                     << RESET << endl;
                addBuff(true, buffName, player);
                // To check for is it the last level
                bool isEnd = true;
                if (player.gameLevel % 5 == 0) {
                    player.gameLevel++;
                    // Player has to fight a boss every 5 level of the game
                    bossScreen(player, items, player.gameLevel / 5, isEnd);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    // Save game after fighting boss
                    if (player.hp > 0)
                        saveGame(player, items);
                    // If player defeat the last boss (on level 55) will show end screen
                    if (isEnd) {
                        ending(player);
                        cout << "\nYou win the game! Wanna play again??\ny - Yes, what a fun game!\tn - No, I have better things to do with my life." << endl;
                        tryAgain("Please input again:\ny - Yes, what a fun game!\tn - No, I have better things to do with my life.", isReplay);
                        break;
                    }
                }
                // Re-render the map for a new level
                map.fill();
                // Reset player position
                player.x = 1;
                player.y = 1;
                // Check for is player on monster
            } else if (map.layout[player.y][player.x] == 'M') {
                // tell player they meet monster
                scr.log = "Monster!";
                clearScreen();
                scr.renderScreen(map, player);
                // wait for 1 sec and then go into fight screen
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                clearScreen();
                // Use for checking if player escape monster
                bool isEscape = false;
                fightScreen(player, items, isEscape);
                // If player does not escape, the monster on map will be removed
                if (!isEscape) {
                    map.removeMapIcon(player.x, player.y);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                // Print screen for player to see
                scr.renderScreen(map, player);
                // Check for is player on chest
            } else if (map.layout[player.y][player.x] == 'C') {
                // Tell player that a golden chest is found
                scr.log = "Find a golden chest!";
                clearScreen();
                scr.renderScreen(map, player);
                // generate chest item and put it into player item
                generateChestItems(items, player);
                // The chest on map will be removed
                map.removeMapIcon(player.x, player.y);
            } else if (map.layout[player.y][player.x] == 'N') {
                // Tell player they meet Charon (NPC for shop)
                scr.log = "Hey Charon!";
                clearScreen();
                scr.renderScreen(map, player);
                // Go into shop screen
                shopScreen(player, items);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                // The shop on map will be removed
                map.removeMapIcon(player.x, player.y);
            } else {
                // If nothing happened, the monster will move on map
                map.update(player.x, player.y);
            }

            // Check if player die
            if (player.hp <= 0) {
                cout << "You die:( Wanna try again?\ny - Yes, I want to try again!\tn - No, I suck at this game." << endl;
                tryAgain("Please input again:\ny - Yes, I want to try again!\tn - No, I suck at this game.", isReplay);
                break;
            }

            // check if player is walking into a wall
            if (wall)
                scr.log = "There is a wall in my way";
            // If not then energy will be reduced by one, if energy is 0, it will start to reduce HP
            else {
                if (player.energy > 0)
                    player.energy--;
                else
                    player.hp--;
                // update buff status
                updateOnBuff(player);
            }
        }
    }
}

// Let player input their choice after the game has ended
void tryAgain(string str, bool &isReplay) {
    string choice;
    cin.ignore();
    do {
        getline(cin, choice);
        if (choice == "n" || choice == "N") {
            isReplay = false;
            break;
        } else if (choice == "y" || choice == "Y") {
            isReplay = true;
            break;
        } else {
            cout << str << endl;
            choice = " ";
        }
    } while (choice != "n" && choice != "N" && choice != "y" && choice != "Y");
}

// Print the boat selling screen in ending
void printBoatsInEnding() {
    string boats[11] = {"1 - trash", "0 G",
                        "2 - wooden boat", "(Sold out)",
                        "3 - iron boat", "(Sold out)",
                        "4 - golden boat", "10,000 G",
                        "5 - EPIC DIAMOND BOAT", "99,999 G(discount cause I cannot sell this for years)",
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

// Show different ending based on the coins that player
void tryAgainInEnding(string &choice, bool &choosing, Player &player) {
    printBoatsInEnding();
    getline(cin, choice);
    while (choosing) {
        if (choice == "1") {
            renderNpc("Charon", "You're broke before you came?");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "What did you do in hell???");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Are you a brainless slime,");
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            renderNpc("Charon", "that can only jump around??");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Go get a job and make money!!");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Bad Ending: Working in Hell.\n";
            choosing = false;
            break;
        } else if (choice == "2" || choice == "3") {
            renderNpc("Charon", "Can't you see it is SOLD OUT??");
            cout << "Enter again: ";
            tryAgainInEnding(choice, choosing, player);
            break;
        } else if (choice == "4" && player.coin >= 10000) {
            renderNpc("Charon", "Nice, you got enough money this time.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "golden boat x 1 GET!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            renderNpc("Charon", "Here is your boat.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Sail it to the end of the river.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Enjoy your afterlife :)");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Normal Ending: Having an Afterlife.\n";
            choosing = false;
            break;
        } else if (choice == "5" && player.coin >= 99999) {
            renderNpc("Charon", "You work real hard.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Proud of you for buying it. :D");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Here is your boat.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Sail it to the Heaven, boy.");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout << "Good Ending: Going to the Heaven.\n";
            choosing = false;
            break;
        } else {
            renderNpc("Charon", "No such choice.");
            tryAgainInEnding(choice, choosing, player);
            break;
        }
    }
}

// Print ending for player
void ending(Player &player) {
    string choice = " ";
    bool choosing = true;
    cout << "At the end, you defeated Hades, the Lord of Hell, in your endless, extraordinary journey of hell.\n";
    cout << "You feel drained out after such long battles, playing around the cold and dark, gods and monsters\n";
    cout << "Closing your eyes, you were just desperate for a moment of rest...\n";
    cout << "A whistle passes into your ears, a familiar voice... <press enter to continue>";
    cin.get();
    cout << "\n\"Oh, you come back to buy boats?\"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    renderNpc("Charon", "Many people came and buy boats.");
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    renderNpc("Charon", "Not many was left.");
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    renderNpc("Charon", "Which one do you want?");
    tryAgainInEnding(choice, choosing, player);
}

// clear Screen (Windows have different command for it)
void clearScreen() {
    if (ISWINDOW)
        std::system("cls");
    else
        std::system("clear");
}
