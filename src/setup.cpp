#include "setup.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void PrintInform(Player player) {
    cout << setfill('-') << setw(50) << "\n";
    cout << "Here is your indentity information\n";
    cout << ">Name: " << player.name << "\n"
         << ">Role: " << player.role << "\n"
         << ">Race: " << player.race << "\n"
         << ">Gender: " << player.gender << "\n";
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nIs this ok?\n\n"
         << player.name << ", " << player.role << ' ' << player.race << ' '
         << player.gender << "\n\n";
    cout << "y - Yes: start my exploration in Hell\n"
         << "n - No: correct my role, race and gender\n"
         << "q - I QUIT NOW\n\n";
}

void PrintChoice() {
    cout << "\n1 -Pick a ROLE\n"
         << "2 - Pick a RACE\n"
         << "3 - Pick a GENDER\n"
         << "y - Yes: All are alright now\n"
         << "q - I QUIT NOW\n"
         << "Enter your choice: ";
}

void PrintRole() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nPick a role or profession\n\n";

    for (char i = 'a'; i < 'a' + max_role; i++) {
        int j = i - 'a';
        cout << i << " -" << roleList[j] << "\n";
    }
    cout << "* - Random\n";
}

void PrintRace() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your race?\n\n";

    for (char i = 'a'; i < 'a' + max_race; i++) {
        int j = i - 'a';
        cout << i << " -" << raceList[j] << "\n";
    }
    cout << "* - Random\n";
}

void PrintGender() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your gender?\n\n";

    for (char i = 'a'; i < 'a' + max_gender; i++) {
        int j = i - 'a';
        cout << i << " -" << genderList[j] << "\n";
    }
    cout << "* - Random\n";
}

void setData(char key, int choice, Player &player) {
    // To-do: only allow players input one char & game response immediately
    //       if players input invalid key, print LOGs
    //       close the screen and open next options
    int i = key - 'a';
    srand(time(NULL));
    switch (choice) {
    case 1:    // role
        if (key >= 'a' && key <= 'a' + max_role)
            player.role = roleList[i];
        else if (key == '*')
            player.role = roleList[rand() % max_role];
        else
            cout << "Please input again";
        break;
    case 2:    // race
        if (key >= 'a' && key <= 'a' + max_race)
            player.race = raceList[i];
        else if (key == '*')
            player.race = raceList[rand() % max_race];
        else
            cout << "Please input again";
        break;
    case 3:    // gender
        if (key >= 'a' && key <= 'a' + max_gender)
            player.gender = genderList[i];
        else if (key == '*')
            player.gender = genderList[rand() % 2];
        else
            cout << "Please input again";
        break;
    }
}

void setupScreen(Player &player) {
    cout << "YOU DIED, Welcome to the Underworld!\n"
         << "Do you remember your name?\t";
    cin >> player.name;
    cout << endl;
    srand(time(NULL));
    player.role = roleList[rand() % max_role];
    player.gender = genderList[rand() % max_gender];

    PrintInform(player);

    char key = ' ';
    cin >> key;

    while (key == 'n') {
        PrintChoice();
        cin >> key;
        switch (key) {
        case '1': {
            PrintRole();
            cin >> key;
            setData(key, 1, player);
            break;
        }
        case '2': {
            PrintRace();
            cin >> key;
            setData(key, 2, player);
            break;
        }
        case '3': {
            PrintGender();
            cin >> key;
            setData(key, 3, player);
            break;
        }
        case 'y':
            break;
        case 'q':
            return;
        }
        PrintInform(player);
        cin >> key;
    }
}
