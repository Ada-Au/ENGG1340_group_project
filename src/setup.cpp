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
    cout << "\n1 - Pick a ROLE\n"
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
    string log;
    // To-do: avoid player's lengthen input
    int i = key - 'a';
    srand(time(NULL));
    switch (choice) {
    case 1:    // role
        if (key >= 'a' && key <= 'a' + max_role)
            player.role = roleList[i];
        else if (key == '*')
            player.role = roleList[rand() % max_role];
        else{
            cout << "Please input again\t";
            cin >> key;
            setData(key, choice, player);
        }      
        break;
    case 2:    // race
        if (key >= 'a' && key <= 'a' + max_race) {
            player.race = raceList[i];
        } else if (key == '*') {
            player.race = raceList[rand() % max_race];
        } else{
            cout << "Please input again\t";
            cin >> key;
            setData(key, choice, player);
        }

        if (player.race == "elf") {
            log = "Charon: So you had been alone for thousands years so that you got the magic power?\n";
        } else if (player.race == "drawf") {
            log = "Charon: No wonder why you are such...short?\n";
        } else if (player.race == "orc") {
            log = "Charon: So you are a brute in human face. Got it.\n";
        }
        cout << log;
        break;
    case 3:    // gender
        if (key >= 'a' && key <= 'a' + max_gender)
            player.gender = genderList[i];
        else if (key == '*')
            player.gender = genderList[rand() % 2];
        else{
            cout << "Please input again\t";
            cin >> key;
            setData(key, choice, player);
        }
        break;
    }
}

void setupScreen(Player &player, int &flag) {
    cout << "\nYOU DIED, Welcome to the Underworld!\n"
         << "What's your name?\t";
    cin >> player.name;
    cout << endl;
    srand(time(NULL));
    player.role = roleList[rand() % max_role];
    player.gender = genderList[rand() % max_gender];

    PrintInform(player);

    char key[2];
    cin >> key;

    while ((key[0] != 'y' && key[0] != 'Y') && (key[0] != 'q' && key[0] != 'Q')) {
        PrintChoice();
        cin >> key;
        if (key[1] == '\0'){
            switch (key[0]) {
                case '1': {
                    PrintRole();
                    cin >> key;
                    setData(key[0], 1, player);
                    break;
                }
                case '2': {
                    PrintRace();
                    cin >> key;
                    setData(key[0], 2, player);
                    break;
                }
                case '3': {
                    PrintGender();
                    cin >> key;
                    setData(key[0], 3, player);
                    break;
                }
                case 'q':
                case 'Q':
                    flag = 0;
                    break;
            }
            if (key[0]!='Q' && key[0]!='q')
                PrintInform(player);            
        }
    } if (key[0] == 'q' || key[0] == 'Q')
        flag = 0;
}

