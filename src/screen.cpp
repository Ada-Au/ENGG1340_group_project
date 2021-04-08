#include "screen.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Screen::renderScreen(Map map, Player player) {
    string stat[12] = {"[ " + player.name + " ]",
                       "",
                       "Level: " + to_string(player.level),
                       "HP: " + to_string(player.hp).substr(0, to_string(player.hp).find(".") + 3),    // + '/' + to_string(player.maxHp),
                       "MP: " + to_string(player.mp).substr(0, to_string(player.mp).find(".") + 3),    // + '/' + to_string(player.maxMp),
                       "Energy: " + to_string(player.energy),                                          //+ '/' + to_string(player.maxEnergy),
                       "ATK: " + to_string(player.damage),
                       "DFS: " + to_string(player.defense),
                       "",
                       "Debuffs: ",
                       "",
                       "Buffs: "};

    int debuffSize = player.debuffs.size();
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            if (h == player.y && w == player.x) {
                if (map.layout[h][w] == 'M') {
                    cout << RED << player.mark << RESET;
                } else
                    cout << BOLDGREEN << player.mark << RESET;
            } else {
                if (map.layout[h][w] == 'M') {
                    cout << RED << 'M' << RESET;
                } else if (map.layout[h][w] == 'S') {
                    cout << BOLDMAGENTA << 'S' << RESET;
                } else
                    cout << map.layout[h][w];
            }
        }

        cout << "      ";
        if (h == 0 || h == map_height - 1) {    // print player's status
            cout << "*******************************" << endl;
        } else if (h <= 10) {    //print player's inform
            cout << "*  " << stat[h - 1] << setw(28 - stat[h - 1].length())
                 << setfill(' ') << "*" << endl;
        } else if (h - 11 < debuffSize) {    //print player's debuffs
            cout << "*   - " << player.debuffs.at(h - 11).name
                 << setw(25 - player.debuffs.at(h - 11).name.length())
                 << setfill(' ') << "*" << endl;
        } else if (h - 11 < debuffSize + 2) {
            cout << "*  " << stat[h - 1 - debuffSize]
                 << setw(28 - stat[h - 1 - debuffSize].length()) << setfill(' ')
                 << "*" << endl;
        } else if (h - 13 - debuffSize < player.buffs.size()) {    //print player's buffs
            cout << "*   - " << player.buffs.at(h - 13 - debuffSize).name
                 << setw(25 - player.buffs.at(h - 13 - debuffSize).name.length())
                 << setfill(' ') << "*" << endl;
        } else
            cout << "*" << setfill(' ') << setw(30) << "*" << endl;
    }

    cout << "\n"
         << setfill('*') << setw(map_width + 2) << "\n\n"
         << log << "\n"
         << setw(map_width + 2) << endl
         << "\n\n";

    //  cout << '\t' << help[i] << '\n';
    log = "";
}

void printHelp() {
    for (int i = 0; i < helpSize; i++)
        cout << helpScreen[i] << endl;
}
// void Screen::fillHelp()
// {
//     help[0] = "\"Numpad\"... - Movement";
//     help[1] = "";
//     for (int i = 2; i < 21; i++)
//         help[i] = "";
// }