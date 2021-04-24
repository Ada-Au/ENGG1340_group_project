#include "homepage.h"
#include "env.h"
#include "saving.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void menu(int &isPlay, Player &player, vector<Item> &items) {
    for (int i = 0; i < 10; i++)
        cout << homepage[i] << "\n";
    cout << "(Please play this game with full screen)" << endl;

    // Press 1, 2, 3 to continue
    cout << setw(104) << setfill(' ') << "[1]  START    [2]  LOAD    [3]  QUIT\n";

    string choice = "";
    while (choice != "1" && choice != "2" && choice != "3") {
        cout << "Enter your choice: ";
        cin >> choice;
    }
    switch (choice[0]) {
    case '1':    // start a new game
        cout << "START! :D\n\n";
        updateItems("bread", 3, 2, 'A', items);    // give breads to player in the beginning
        break;
    case '2':
        cout << "Selected LOAD\n";    // input files
        isPlay = 2;
        getSavedGame(player, items, isPlay);
        break;
    case '3':    // quit game
        cout << "Selected QUIT\n";
        isPlay = 0;
        break;
    }
}
