#include "player.h"
#include "start.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

Begin start;
Player player;

void PrintInform()
{
    cout << setfill('-') <<setw(50) << "\n";
    cout << "Here is your indentity information\n";
    cout << ">Name: "<< player.name << "\n"
         << ">Role: " << player.role << "\n"
         << ">Race: " << player.race << "\n"
         << ">Gender: " << player.gender << "\n";
    cout << setfill('-') <<setw(50) << "\n";
    cout << "\nIs this ok?\n\n" << player.name << ", " << player.role << ' ' << player.race << ' ' << player.gender << "\n\n";
    cout << "y- Yes: start my exploration in Hell\n" << "n- No: correct my role, race and gnender\n" << "q- I QUIT NOW\n\n";
}

void PrintChoice()
{
    cout << "\n1 -Pick a ROLE\n" << "2 -Pick a RACE\n" << "3 -Pick a GENDER\n"
         << "y -Yes: All are alright now\n" << "q -I QUIT NOW\n"
         << "Enter your choice: ";
}

void PrintRole()
{
    cout << setfill('-') <<setw(50) << "\n";
    cout << "\nPick a role or profession\n\n";

    for (char i = 'a'; i < 'a' + max_role; i++){
        int j = i -'a';
        cout << i << " -" << player.roleList[j] << "\n";
    }
    cout << "* -Random\n";
}

void PrintRace()
{
    cout << setfill('-') <<setw(50) << "\n";
    cout << "\nWhat's your race?\n\n";

    for (char i = 'a'; i < 'a' + max_race; i++){
        int j = i -'a';
        cout << i << " -" << player.raceList[j] << "\n";
    }
    cout << "* -Random\n";
}

void PrintGender()
{
    cout << setfill('-') <<setw(50) << "\n";
    cout << "\nWhat's your gender?\n\n";

    for (char i = 'a'; i < 'a' + max_gender; i++){
        int j = i -'a';
        cout << i << " -" << player.genderList[j] << "\n";
    }
    cout << "* -Random\n";
}

void Player::setData (char flag, int max)
{
    //To-do: only allow players input one char & game response immediately
    //       if players input invalid key, print LOGs
    //       close the screen and open next options

    if (max == max_role)
    {
        if (flag <= 'a' && flag >= 'a' + max_role){
            int iflag = flag - 'a';
            player.role = player.roleList[iflag];
        }
        else if (flag == '*')
            player.role = player.roleList[rand() % max_role];
    }
    else if (max == max_race)
    {
        if (flag <= 'a' && flag >= 'a' + max_race){
            int iflag = flag - 'a';
            player.race = player.raceList[iflag];
        }
        else if (flag == '*')
            player.race = player.raceList[rand() % max_race];
    }
    else if (max == max_gender)
    {
        if (flag <= 'a' && flag >= 'a' + max_gender){
            int iflag = flag - 'a';
            player.gender = player.genderList[iflag];
        }
        else if (flag == '*')
            player.gender = player.genderList[rand() % max_role];
    }
}

int main()
{
    cout << "YOU DIED, Welcome to the Underworld!\n"
         << "Do you remeber your name?\t";
    cin >> player.name;
    cout << endl;

    player.role = player.roleList[rand() % max_role];
    player.gender = player.genderList[rand() % max_gender];

    PrintInform();

    char key = ' ';
    cin >> key;

    while (key == 'n')
    {
        PrintChoice();
        char flag = ' ';
        cin >> flag;

        switch (flag)
        {
            case '1':
            {
                PrintRole();
                PrintChoice();
                cin >> flag;
                player.setData(flag, max_role);
            }
            case '2':
            {
                PrintRace();
                PrintChoice();
                cin >> flag;
                player.setData(flag, max_race);
            }
            case '3':
            {
                PrintGender();
                PrintChoice();
                cin >> flag;
                player.setData(flag, max_gender);
            }
            case 'y':
            {
                break;
            }
        }
        PrintInform();
        cin >> key;
        break;
    }
    return 0;
}