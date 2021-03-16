#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    Player player;

    cout << "YOU DIED. Welome to the Underworld!\n"
         << "Do you remember your name?\n"
         << "Input your name: ";

    cin >> player.name;
    // cout << "Here is your indentity information\n";
    // cout << "Name: " << player.name << "\n"
    //      << "Role: " << player.randomRole() << "\n"
    //      << "Race: " << player.randomRace() << "\n"
    //      << "Gender: " << player.randomGender() << "\n"
    cout << player.name;
    return 0;
}
