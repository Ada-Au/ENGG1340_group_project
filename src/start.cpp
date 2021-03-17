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
    cout << setfill('*') << setw(50) << endl;
    cout << "\nHere is your indentity information\n";
    cout << "> Name: " << player.name << "\n"
    << "> Role: " << player.role << "\n"
    << "> Race: " << player.race << "\n"
    << "> Gender: " << player.gender << "\n\n";
    cout << setfill('*') << setw(50) << endl;

    cout << "\nIs this ok? \n\n" << player.name << ", " << player.gender << " " << player.race << " " << player.role << "\n\n";  //remember to print eihter Caveman/Cavewomen
    cout << "y -Yes: start my exploration in Hell\n" << "n -No: correct my role, race and gender again\n" << "q -I QUIT NOW\n\n";
}

void PrintChoice()
{
    cout << "\n" << "1 -Pick a role\n" << "2 -Pick a race\n" << "3 -Pick a gender\n"
         << "y -Yes: All are alright now\n" << "q -I QUIT NOW\n"
         << "Enter your choice: ";
}

void PrintRole()
{   
    cout << setfill('*') << setw(50) << endl;
    cout << "\nPick a role or profession\n\n";
    for (char i = 'a'; i < 'a' + max_role; i++){
        int j = i - 'a';
        cout << i <<" -"<< player.roleList[j] << endl;
    }
    cout << '*' << " -Random\n";
}

void PrintRace()
{   
    cout << setfill('*') << setw(50) << endl;
    cout << "\nWhat's your race?\n\n";
    for (char i = 'a'; i < 'a' + max_race; i++){
        int j = i - 'a';
        cout << i <<" -"<< player.raceList[j] << endl;
    }
    cout  << '*' << " -Random\n";
}

void PrintGender()
{   
    cout << setfill('*') << setw(50) << endl;
    cout << "\nWhat's your gender?\n\n";
    for (char i = 'a'; i < 'a' + max_gender; i++){
        int j = i - 'a';
        cout << i <<" -"<< player.genderList[j] << endl;
    }
    cout << '*' << " -Random\n";
}

void DealInput(char flag, int max)
{
    // To-do: only allow players input one char & game responses immediately
    //        if players input invalid key, print LOG
    //        close the screen and open next options
    if(max == max_role)
    {
        if (flag <='a' && flag >= 'a' + max_role){
            int iflag = flag - 'a';
            player.role = player.roleList[iflag];
        }
        else if (flag =='*')
            player.role = player.roleList[rand() % max_role];
        
    else if(max==max_race){
        if(flag <='a' && flag >= 'a' + max_race){
            int iflag = flag - 'a';
            player.race = player.raceList[iflag];
        }
        else if (flag =='*')
            player.race = player.raceList[rand() % max_race];
        
    }
    else if (max == max_gender){
        if(flag <='a' && flag >= 'a' + max_gender){
            int iflag = flag - 'a';
            player.gender = player.genderList[iflag];
        }
        else if (flag =='*')
            player.gender = player.genderList[rand() % max_gender];
        }
    }
}

int main()
{
    cout << "YOU DIED. Welome to the Underworld!\n"
         << "Do you remember your name?\t";

    cin >> player.name;
    cout << endl;

    player.role = player.roleList[rand() % max_role];
    player.gender = player.genderList[rand() % max_gender];

    PrintInform();

    char key = ' ';
    cin >> key;

    while(key == 'n')
    {   
        PrintChoice();
        char flag = ' ';
        cin >> flag;
        
        switch (flag)
        {
            case '1':                       //input player's role
            {                
                PrintRole();
                PrintChoice();
                cin >> flag;
                DealInput(flag, max_role);
            }

            case '2':                        //input player's race
            {         
                PrintRace();
                PrintChoice();
                cin >> flag;
                DealInput(flag, max_race);
            }

            case '3':                        //input player's gender
            {         
                PrintGender();
                PrintChoice();
                cin >> flag;
                DealInput(flag, max_gender);
            }

            case 'y':
            {
                break;
            }
            
        }
        PrintInform();
        cin >> key;
    }
    return 0;
}
