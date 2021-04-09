#include "setup.h"
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

void PrintInform(Player player) {
    string ID[6] = {"------------------------------------------",
                    "> Name: " + player.name,
                    "> Role: " + player.role,
                    "> Race: " + player.race,
                    "> Gender: " + player.gender,
                    "------------------------------------------"
                    };
    renderNpc("charon","Here is your indentity information");
    for (int i = 0; i < 7; i++)
        cout << ID[i] << endl;
}

void PrintChoice() {
    cout << "Charon: Do you have anything to change for your ID?\n\n"
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

void introduction(char key[]) {
    cout  << "1 - Who are you?\n" << "2 - Where am I?\n" << "3 - (Nothing want to ask)\n" << "Enter your choice: "; 
    cin >> key;
    cout << endl;
    while (key[1] != '\0' || (key[0] != '1' && key[0] != '2' && key[0] != '3') ){
        renderNpc("charon"," What do you say?");
        cout  << "1 - Who are you?\n" << "2 - Where am I?\n" << "3 - (Nothing want to ask)\n" << "Enter again: "; 
        cin >> key;
        cout << endl;
    }
    while(key[0] != '3'){
        switch(key[0]){
            case '1':
                renderNpc("charon", "I am Charon, a ferryman in hell.");
                break;
            case '2':
                renderNpc("charon", "I've just said-- Welcome to HELL.");
                break;
        }
        cout  << "1 - Who are you?\n" << "2 - Where am I?\n" << "3 - (Nothing want to ask)\n" << "Enter your choice: "; 
        cin >> key;
        cout << endl;
        while (key[1] != '\0'){
            renderNpc("charon"," What do you say?");
            cout  << "1 - Who are you?\n" << "2 - Where am I?\n" << "3 - (Nothing want to ask)\n" << "Enter again: "; 
            cin >> key;
            cout << endl;
        }
    }
}

void setData(char key[], int choice, Player &player) {                
    string log;
    // To-do: avoid player's lengthen input
    while (key[1] != '\0'){
        cout << "Please input again: ";
        cin >> key;        
    }
    int i = key[0] - 'a';
    srand(time(NULL));
    switch (choice) {
    case 1:    // role
        if (key[0] >= 'a' && key[0] <= 'a' + max_role)
            player.role = roleList[i];
        else if (key[0] == '*')
            player.role = roleList[rand() % max_role];
        else{
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }      
        break;
    case 2:    // race
        if (key[0] >= 'a' && key[0] <= 'a' + max_race) {
            player.race = raceList[i];
        } else if (key[0] == '*') {
            player.race = raceList[rand() % max_race];
        } else{
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }

        if (player.race == "elf") {
            log = "You had been alone for thousands years so that you got the magic power?";
        } else if (player.race == "drawf") {
            log = "No wonder why you are such...short?";
        } else if (player.race == "orc") {
            log = "So you are a brute in human face. Got it.";
        }
        renderNpc("charon", log);
        break;
    case 3:    // gender
        if (key[0] >= 'a' && key[0] <= 'a' + max_gender)
            player.gender = genderList[i];
        else if (key[0] == '*')
            player.gender = genderList[rand() % 2];
        else{
            cout << "Please input again: ";
            cin >> key;
            setData(key, choice, player);
        }
        break;
    }
}

void setupScreen(Player &player, int &flag) {
    char key[2];
    srand(time(NULL));
    player.role = roleList[rand() % max_role];
    player.gender = genderList[rand() % max_gender];  
    renderNpc("charon","YOU DIED, Welcome to the Hell!");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    renderNpc("charon","What's your name?");
    cout << "My name is: ";
    cin >> player.name;
    cout << endl;
    renderNpc("charon","Welcome " + player.name + "."); 
    introduction(key);
    PrintInform(player);
    PrintChoice();
    cin >> key;
    while (( (key[0] != 'n' && key[0]!= 'N') && (key[0] != 'q' && key[0]!= 'Q') && key[0]!='1' && key[0]!='2' && key[0]!='3') || key[1]!='\0') {
        cout << "Enter again: ";
        cin >> key;
        cout << endl;
    }
    while (key[0] != 'n' && key[0] != 'N' && key[0]!='Q' && key[0]!='q') {
        if (key[1] == '\0'){
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
                    flag = 0;
                    break;
            }
            if (key[0]!='Q' && key[0]!='q'){
                PrintInform(player);
                PrintChoice();
                cin >> key;
            }  
        }else {
            cout << "Please enter again: ";
            cin >> key;
            cout << endl;
        }
    } if (key[0] == 'q' || key[0] == 'Q')
        flag = 0;
}
