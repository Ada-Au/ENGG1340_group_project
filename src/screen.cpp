#include "screen.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Screen::renderScreen(Map map, Player player) {
    string stat[9] = {"[name]",
                      "",
                      "HP: " + to_string(player.hp),
                      "MP: " + to_string(player.mp),
                      "Energy: " + to_string(player.energy),
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
        if (h == 0 || h == map_height - 1) {
            cout << "*******************************" << endl;
        } else if (h <= 7)
            cout << "*  " << stat[h - 1] << setw(28 - stat[h - 1].length())
                 << setfill(' ') << "*" << endl;
        else if (h - 8 < debuffSize) {
            cout << "*   - " << player.debuffs.at(h - 8).name
                 << setw(25 - player.debuffs.at(h - 8).name.length())
                 << setfill(' ') << "*" << endl;
        } else if (h - 8 < debuffSize + 2) {
            cout << "*  " << stat[h - 1 - debuffSize]
                 << setw(28 - stat[h - 1 - debuffSize].length()) << setfill(' ')
                 << "*" << endl;
        } else if (h - 10 - debuffSize < player.buffs.size()) {
            cout << "*   - " << player.buffs.at(h - 10 - debuffSize).name
                 << setw(25 - player.buffs.at(h - 10 - debuffSize).name.length())
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

// void Screen::fillHelp()
// {
//     help[0] = "\"Numpad\"... - Movement";
//     help[1] = "";
//     for (int i = 2; i < 21; i++)
//         help[i] = "";
// }