#include "shop.h"
#include "npc.h"
#include <iostream>

using namespace std;

void shopScreen(Item items[]) {
    char key;
    renderNpc("charon", "Welcome, have a look.");
    cout << "ACTION (please input number 1-4)" << endl
         << "1 - Sell                    2 - Buy " << endl
         << "3 - Talk                    4 - Exit" << endl;
    cin >> key;
    while (key != '4'){
        switch(key) {
        case '1':
            displayBackpack(items, true);
            cin >> key;
            break;
        case '2':
            break;
        case '3':
            break;
        }        
    }

}