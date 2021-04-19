#include "setup.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <time.h>

using namespace std;

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

void PrintChoice() {
    cout << "Do you have anything to change for your ID?\n"
         << "1 - Pick a ROLE\n"
         << "2 - Pick a RACE\n"
         << "3 - Pick a GENDER\n"
         << "n - No: start my exploration in Hell\n"
         << "q - I QUIT NOW\n"
         << "Enter your choice: ";
}

void PrintRole() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nPick a role or profession\n\n";

    for (char i = 'a'; i < 'a' + max_role; i++) {
        int j = i - 'a';
        cout << i << " - " << roleList[j] << "\n";
    }
    cout << "* - Random\n";
}

void PrintRace() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your race?\n\n";

    for (char i = 'a'; i < 'a' + max_race; i++) {
        int j = i - 'a';
        cout << i << " - " << raceList[j] << "\n";
    }
    cout << "* - Random\n";
}

void PrintGender() {
    cout << setfill('-') << setw(50) << "\n";
    cout << "\nWhat's your gender?\n\n";
    for (char i = 'a'; i < 'a' + max_gender; i++) {
        int j = i - 'a';
        cout << i << " - " << genderList[j] << "\n";
    }
    cout << "* - Random\n";
}

void DealQuestion(int repeat, char key[]) {
    if (repeat == 0) {
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

void introduction(char key[]) {
    DealQuestion(0, key);
    while (key[1] != '\0' || (key[0] != '1' && key[0] != '2' && key[0] != '3')) {
        DealQuestion(1, key);
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
        DealQuestion(0, key);
        while (key[1] != '\0') {
            DealQuestion(1, key);
        }
    }
}

void setData(char key[], int choice, Player &player) {
    string log;
    // To-do: avoid player's lengthen input
    while (key[1] != '\0') {
        cout << "Please input again: ";
        cin >> key;
    }
    int i = key[0];
    if (key[0] >= 'a')
        i -= 'a';
    else
        i -= 'A';
    srand(time(NULL));
    switch (choice) {
    case 1:    // role
        if ((key[0] >= 'a' && key[0] <= 'a' + max_role) || (key[0] >= 'A' && key[0] <= 'A' + max_role))
            player.role = roleList[i];
        else if (key[0] == '*')
            player.role = roleList[rand() % max_role];
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

        if (player.race == "elf") {
            log = "Hundred years of virginity make you an elf?";
        } else if (player.race == "drawf") {
            log = "No wonder why you are so...short?";
        } else if (player.race == "orc") {
            log = "So you are a brute in human face. Got it.";
        }
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

void setupScreen(Player &player, int &isPlay) {
    char key[2];
    srand(time(NULL));
    player.role = roleList[rand() % max_role];
    player.gender = genderList[rand() % max_gender];
    renderNpc("Charon", "YOU DIED, Welcome to the Hell!");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    renderNpc("Charon", "What's your name?");
    cout << "My name is: ";
    cin.ignore();
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
    cout << "1 G GET.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    renderNpc("Charon", "Choose one here.");
    printBoats();
    char c[2] = {'6'};
    while ((c[0] != '1' && c[0] != '2' && c[0] != '3' && c[0] != '4' && c[0] != '5') || c[1] != '\0') {
        cout << "Enter your choice: ";
        cin >> c;
    }
    while (c[0] != '1') {
        while ((c[0] != '1' && c[0] != '2' && c[0] != '3' && c[0] != '4' && c[0] != '5') || c[1] != '\0') {
            renderNpc("Charon", "No such choice.");
            printBoats();
            cout << "Enter your choice: ";
            cin >> c;
        }
        if (c[0] == '5') {
            renderNpc("Charon", "Look at how much money you have!");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            renderNpc("Charon", "Why do you think you can afford that!?");
        } else
            renderNpc("Charon", "You got no money to buy that.");
        printBoats();
        cout << "Enter your choice: ";
        cin >> c;
    }
    renderNpc("Charon", "To my surprise, you bought trash.");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    renderNpc("Charon", "What a poor boy.");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    renderNpc("Charon", "Enjoy your trip to hell:)");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout << "You get on the trash, start rolling hard.\n"
         << "After a few minutes, you found there is water leaking...\n"
         << "The boat is sinking!!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout << "You fell down for very long.long..long... time. Guess now you are in the bottom layer of hell.¯\\_(ツ)_/¯\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}