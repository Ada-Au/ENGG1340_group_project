#include "homepage.h"
#include "env.h"
#include <iostream>
#include <string>
#include <iomanip>

#define KEY_ENTER '\r'

using namespace std;

void menu(int &isPlay) {
    int selected = 0;
    int choices = 3;

    //To-do: Press any key to continue
    //       add reminder: plz play this game with full screen
    for (int i = 0; i < 10; i++)
        cout << homepage[i] << "\n";
    
    cout << "(Please play this game with full screen)" << endl;

    //Press 1, 2, 3 to continue
    cout << setw(104) << "[1]  START    [2]  LOAD    [3]  QUIT\n";

    char c[2] = {'4'};
    while ( (c[0] != '1' && c[0] != '2' && c[0] != '3' )|| c[1] != '\0'){
        cout <<"Enter your choice: ";
        cin >> c;
    }
    switch (c[0]) {
    case '1':
        cout << "START! :D\n\n";      //start a new game
        break;
    case '2':
        cout << "Selected LOAD\n";    // input files
        isPlay = 2;
        break;
    case '3':
        cout << "Selected QUIT\n";
        isPlay = 0;
        break;
    }
}
