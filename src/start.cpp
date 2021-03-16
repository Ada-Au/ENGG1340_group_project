#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    Player player;

    cout << "YOU DIED. Welome to the Underworld!\n"
         << "Do you remember your name?\t"
         << "Enter your name: ";

    cin >> player.name;
    cout << endl;

    player.randomRole(player.role);
    player.randomGender(player.gender);

    cout << "Here is your indentity information\n"
    << "> Name: " << player.name << "\n"
    << "> Role: " << player.role << "\n"
    << "> Race: " << player.race << "\n"
    << "> Gender: " << player.gender << "\n\n";

    cout << "Is this ok? \n\n" << player.name << ", " << player.gender << " " << player.race << " " << player.role << "\n\n";
    cout << "y -Yes: start my exploration in Hell\n" << "n -No: correct my role, race and gender again\n" << "q -I QUIT NOW\n";

    char key = ' ';
    cin >> key;

    switch(key)
    {
    case 'y':
        break;

    case 'n':
        char flag = ' ';
        
        cout << "Pick a role or profession\n\n";
        for (char i = 'a'; i < 'a' + max_role; i++){
            int iflag = i - 'a';
            cout << i <<" -"<< player.roleList[iflag] << endl;
        }
        cout << '*' << " -Random\n\n\n";


        break;

    case 'q':
        break;
    }

    return 0;
}
