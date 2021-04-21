#include "screen.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#if defined _WIN32 || defined _WIN64
#define ISWINDOW true
#else
#define ISWINDOW false
#endif
using namespace std;

void Screen::renderScreen(Map map, Player player) {
    const int statSize = 18;
    string stat[statSize] = {"[ " + player.name + " ]",
                             "",
                             "Level: " + to_string(player.level),
                             "Game level: " + to_string(player.gameLevel),
                             "Coins: " + to_string(player.coin),
                             "HP: " + to_string(player.hp).substr(0, to_string(player.hp).find(".") + 3) + " / " + to_string(player.maxHp).substr(0, to_string(player.hp).find(".") + 3),
                             "MP: " + to_string(player.mp).substr(0, to_string(player.mp).find(".") + 3) + " / " + to_string(player.maxMp).substr(0, to_string(player.hp).find(".") + 3),
                             "Energy: " + to_string(player.energy).substr(0, to_string(player.mp).find(".") + 3) + " / " + to_string(player.maxEnergy).substr(0, to_string(player.hp).find(".") + 3),
                             "ATK: " + to_string(player.weapon.damage * (1 + player.damage / 50.0)).substr(0, to_string(player.weapon.damage * (1 + player.damage / 50.0)).find(".") + 3),
                             " - Weapon: " + player.weapon.name,
                             " - Damage level: " + to_string(player.damage),
                             "DFS: " + to_string(player.aDefense * (1 + player.defense / 50.0)).substr(0, to_string(player.aDefense * (1 + player.defense / 50.0)).find(".") + 3),
                             " - Armor: " + player.armor,
                             " - Defense level: " + to_string(player.defense),
                             "",
                             "Debuffs: ",
                             "",
                             "Buffs: "};

    int debuffSize = player.debuffs.size();
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            if (h == player.y && w == player.x) {
                if (map.layout[h][w] == 'M') {
                    cout << BOLDRED << player.mark << RESET;
                } else
                    cout << BOLDGREEN << player.mark << RESET;
            } else {
                if (map.layout[h][w] == 'M') {
                    cout << RED << 'M' << RESET;
                } else if (map.layout[h][w] == 'S') {
                    cout << BOLDMAGENTA << 'S' << RESET;
                } else if (map.layout[h][w] == 'C') {
                    cout << BOLDYELLOW << 'C' << RESET;
                } else if (map.layout[h][w] == 'N') {
                    cout << BOLDCYAN << 'N' << RESET;
                } else
                    cout << map.layout[h][w];
            }
        }

        cout << "      ";
        if (h == 0 || h == map_height - 1) {    // print player's status
            cout << "*******************************" << endl;
        } else if (h <= statSize - 2) {    //print player's inform
            cout << "*  " << stat[h - 1] << setw(28 - stat[h - 1].length())
                 << setfill(' ') << "*" << endl;
        } else if (h - (statSize - 1) < debuffSize) {    //print player's debuffs
            cout << "*   - " << player.debuffs.at(h - (statSize - 1)).name
                 << setw(25 - player.debuffs.at(h - (statSize - 1)).name.length())
                 << setfill(' ') << "*" << endl;
        } else if (h - (statSize - 1) < debuffSize + 2) {
            cout << "*  " << stat[h - 1 - debuffSize]
                 << setw(28 - stat[h - 1 - debuffSize].length()) << setfill(' ')
                 << "*" << endl;
        } else if (h - (statSize + 1) - debuffSize < player.buffs.size()) {    //print player's buffs
            cout << "*   - " << player.buffs.at(h - (statSize + 1) - debuffSize).name
                 << setw(25 - player.buffs.at(h - (statSize + 1) - debuffSize).name.length())
                 << setfill(' ') << "*" << endl;
        } else
            cout << "*" << setfill(' ') << setw(30) << "*" << endl;
    }

    cout << "\n"
         << setfill('*') << setw(map_width + 2) << "\n\n"
         << log << "\n"
         << setw(map_width + 2) << endl
         << "\n\n";

    log = "";
}

void printHelp() {
    for (int i = 0; i < helpSize; i++)
        cout << helpScreen[i] << endl;
}
