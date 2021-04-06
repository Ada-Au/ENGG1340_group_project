#include "homepage.h"
#include "env.h"
#include <iostream>
#include <string>

#define KEY_ENTER '\r'

using namespace std;

void homescreen() {
    int selected = 0;
    int choices = 3;

    //To-do: Press any key to continue
    //       add reminder: plz play this game with full screen
    for (int i = 0; i < 10; i++)
        cout << homepage[i] << "\n";

    //Press 1, 2, 3 to continue
    cout << "[1]  START\t[2]  LOAD\t[3]  QUIT\n";

    char c;
    switch (c = cin.get()) {
    case '1':
        cout << "Selected START";    //start a new game
        break;
    case '2':
        cout << "Selected LOAD";    // input files
        break;
    case '3':
        cout << "Selected QUIT";
        break;
    default:
        break;
    }

    // if (updated) {
    //     cout << log << "\t<Press Enter to Continue...>";
    //     if (cin.get()) {
    //         selecting = false;
    //         break;
    //     } else
    //         updated = false;
    // }
}
