#include "homepage.h"
#include "env.h"
#include "saving.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void menu(int &isPlay, Player &player, vector<Item> &items) {
    int selected = 0;
    int choices = 3;

    //To-do: Press any key to continue
    for (int i = 0; i < 10; i++)
        cout << homepage[i] << "\n";

    cout << "(Please play this game with full screen)" << endl;

    //Press 1, 2, 3 to continue
    cout << setw(104) << setfill(' ') << "[1]  START    [2]  LOAD    [3]  QUIT\n";

    char c[2] = {'4'};
    while ((c[0] != '1' && c[0] != '2' && c[0] != '3') || c[1] != '\0') {
        cout << "Enter your choice: ";
        cin >> c;
    }
    switch (c[0]) {
    case '1':
        cout << "START! :D\n\n";    //start a new game
        updateItems("bread", 3, 2, 'A', items);
        break;
    case '2':
        cout << "Selected LOAD\n";    // input files
        getSavedGame(player, items);
        isPlay = 2;
        break;
    case '3':
        cout << "Selected QUIT\n";
        isPlay = 0;
        break;
    }
}
