#include "homepage.h"
#include "env.h"
#include <iostream>
#include <string>
#include <iomanip>

#define KEY_ENTER '\r'

using namespace std;

void menu(int &flag) {
    int selected = 0;
    int choices = 3;

    //To-do: Press any key to continue
    //       add reminder: plz play this game with full screen
    for (int i = 0; i < 10; i++)
        cout << homepage[i] << "\n";
    
    cout << "(Please play this game with full screen)" << endl;

    //Press 1, 2, 3 to continue
    cout << setw(104) << "[1]  START    [2]  LOAD    [3]  QUIT\n";

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
        flag = 0;
        break;
    default:
        break;
    }
}
