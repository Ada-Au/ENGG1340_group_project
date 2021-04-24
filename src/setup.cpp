#include "setup.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <time.h>

using namespace std;

// print the player's information
void PrintInform(Player player) {
    string ID[6] = {"------------------------------------------",
                    "> Name: " + player.name,
                    "> Role: " + player.role,
                    "> Race: " + player.race,
                    "> Gender: " + player.gender,
                    "------------------------------------------"};
    renderNpc("Charon", "Here is your indentity information");
    for (int i = 0; i < 6; i++)
        cout << ID[i] << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

// print player's choice in setting up player's information
void PrintChoice() {
    cout << "Do you have anything to change for your ID?\n"
         << "1 - Pick a ROLE\n"
         << "2 - Pick a RACE\n"
         << "3 - Pick a GENDER\n"
         << "n - No: start my exploration in Hell\n"
         << "q - I QUIT NOW\n"
         << "Enter your choice: ";
}

// print choices of roles
void PrintRole() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nPick a role or profession\n\n";

    for (char i = 'a'; i < 'a' + max_role; i++) {
        int j = i - 'a';
        cout << i << " - " << roleList[j] << "\n";
    }
    cout << "* - Random\n";
}

// print choices of race
void PrintRace() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your race?\n\n";

    for (char i = 'a'; i < 'a' + max_race; i++) {
        int j = i - 'a';
        cout << i << " - " << raceList[j] << "\n";
    }
    cout << "* - Random\n";
}

// print choices of gender
void PrintGender() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your gender?\n\n";
    for (char i = 'a'; i < 'a' + max_gender; i++) {
        int j = i - 'a';
        cout << i << " - " << genderList[j] << "\n";
    }
    cout << "* - Random\n";
}

// print player's question in Charon's introduction
// and read player's choices
// Input: bool repeat: determine whether player entered invalid input
//                     if yes, Charon appears to ask "What do you say?"
void DealQuestion(bool repeat, string &key) {
    if (repeat) {
        cout << "1 - Who are you?\n"
             << "2 - Where am I?\n"
             << "3 - (Nothing want to ask)\n"
             << "Enter your choice: ";
    } else {
        renderNpc("Charon", " What do you say?");
        cout << "1 - Who are you?\n"
             << "2 - Where am I?\n"
             << "3 - (Nothing want to ask)\n"
             << "Enter again: ";
    }
    cin >> key;
    cout << endl;
}

// Charon's introduction at the beginning of game
void introduction(string key) {
    DealQuestion(true, key);
    // Require player enter again after he/she enters invalid input
    while (key[1] != '\0' || (key[0] != '1' && key[0] != '2' && key[0] != '3')) {
        DealQuestion(false, key);
    }
    while (key[0] != '3') {
        switch (key[0]) {
        case '1':
            renderNpc("Charon", "I am Charon, a ferryman in hell.");
            break;
        case '2':
            renderNpc("Charon", "I've just said-- Welcome to HELL.");
            break;
        }
        DealQuestion(true, key);
        // Avoid reading invalid inputs again
        while (key[1] != '\0' || (key[0] != '1' && key[0] != '2' && key[0] != '3' && key[1] == '\0')) {
            DealQuestion(false, key);
        }
    }
}

// set up data of player
void setData(string key, int choice, Player &player) {
    // Avoid player's random input
    while (key[1] != '\0') {
        cout << "Please input again: ";
        cin >> key;
    }
    int i = key[0];    // index for list of race/role/gender
    // convert player's choice form char to int
    // if player's input is lower-case
    if (key[0] >= 'a')
        i -= 'a';
    // else if player's input is upper-case
    else
        i -= 'A';
    srand(time(NULL));
    string log = "";    // Charon's log after player's selecting race
    switch (choice) {
    case 1:    // role
        // allow player's input is lower-case and upper-case
        if ((key[0] >= 'a' && key[0] <= 'a' + max_role) || (key[0] >= 'A' && key[0] <= 'A' + max_role))
            player.role = roleList[i];
        // randomly generate if player input '*'
        else if (key[0] == '*')
            player.role = roleList[rand() % max_role];
        // require player to enter again if he/she entered invalid choice
        else {
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }
        break;
    case 2:    // race
        if ((key[0] >= 'a' && key[0] <= 'a' + max_race) || (key[0] >= 'A' && key[0] <= 'A' + max_race)) {
            player.race = raceList[i];
        } else if (key[0] == '*') {
            player.race = raceList[rand() % max_race];
        } else {
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }
        // set up Charon's log after player's selecting race
        if (player.race == "elf") {
            log = "Hundred years of virginity make you an elf?";
        } else if (player.race == "drawf") {
            log = "No wonder why you are so...short?";
        } else if (player.race == "orc") {
            log = "So you are a brute in human face. Got it.";
        }
        // print Charon if player selects race other than human
        if (log != "") {
            renderNpc("Charon", log);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        break;
    case 3:    // gender
        if ((key[0] >= 'a' && key[0] <= 'a' + max_gender) || (key[0] >= 'A' && key[0] <= 'A' + max_gender))
            player.gender = genderList[i];
        else if (key[0] == '*')
            player.gender = genderList[rand() % max_gender];
        else {
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }
        break;
    }
}

// set up player's information at the beginning of the game
// int isPlay: to determine whether player starts/load/quit game
void setupScreen(Player &player, int &isPlay) {
    string key;           // string to store player's choice
    srand(time(NULL));    // seed random for randomly setting up player's role and gender
    player.role = roleList[rand() % max_role];
    player.gender = genderList[rand() % max_gender];
    renderNpc("Charon", "YOU DIED, Welcome to the Hell!");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    renderNpc("Charon", "What's your name?");
    cout << "My name is: ";
    // cin.ignore();    // ignore new line so that set up can start
    getline(cin, player.name);
    cout << endl;
    renderNpc("Charon", "Welcome " + player.name + ".");
    introduction(key);
    PrintInform(player);
    PrintChoice();
    cin >> key;
    while (((key[0] != 'n' && key[0] != 'N') && (key[0] != 'q' && key[0] != 'Q') && key[0] != '1' && key[0] != '2' && key[0] != '3') || key[1] != '\0') {
        cout << "Enter again: ";
        cin >> key;
        cout << endl;
    }
    while (key[0] != 'n' && key[0] != 'N' && key[0] != 'Q' && key[0] != 'q') {
        if (key[1] == '\0') {
            switch (key[0]) {
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
            case 'q':
            case 'Q':
                isPlay = 0;
                break;
            }
            if (key[0] != 'Q' && key[0] != 'q') {
                PrintInform(player);
                PrintChoice();
                cin >> key;
            }
        } else {
            cout << "Please enter again: ";
            cin >> key;
            cout << endl;
        }
    }
    if (key[0] == 'q' || key[0] == 'Q')
        isPlay = 0;
}

void printBoats() {
    string boats[11] = {"1 - trash", "0 G",
                        "2 - wooden boat", "2 G",
                        "3 - iron boat", "3 G",
                        "4 - golden boat", "5 G",
                        "5 - EPIC DIAMOND BOAT", "999,999,999 G",
                        ""};
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            cout << "Boats" << setfill(' ') << setw(36) << "Price" << endl;
        if (i % 2 == 0)
            cout << boats[i] << setfill(' ') << setw(40 - boats[i].length());
        else
            cout << boats[i] << endl;
    }
}

void boatScreen() {
    renderNpc("Charon", "Before you go on, you have to buy a boat.");
    cout << "\nYou search through your pocket...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << '.' << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << ".." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "1G GET.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    renderNpc("Charon", "Choose one here.");
    printBoats();
    string choice = "";
    while ((choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5') || choice[1] != '\0') {
        cout << "Enter your choice: ";
        cin >> choice;
    }
    while (choice[0] != '1') {
        while ((choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5') || choice[1] != '\0') {
            renderNpc("Charon", "No such choice.");
            printBoats();
            cout << "Enter your choice: ";
            cin >> choice;
        }
        if (choice[0] == '5') {
            renderNpc("Charon", "Look at how much money you have!");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Why do you think you can afford that!?");
        } else
            renderNpc("Charon", "You got no money to buy that.");
        printBoats();
        cout << "Enter your choice: ";
        cin >> choice;
    }
    renderNpc("Charon", "To my surprise, you bought trash.");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    renderNpc("Charon", "What a poor boy.");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    renderNpc("Charon", "Here are some breads in case you 'die'");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    renderNpc("Charon", "Enjoy your trip to hell:)");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout << "You get on the trash, start rolling hard.\n"
         << "After a few minutes, you found there is water leaking...\n"
         << "The boat is sinking!!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout << "You fell down for very long.long..long... time. Guess now you are in the bottom layer of hell.\\_('U')_/\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}