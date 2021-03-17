#ifndef Start_h
#define Start_h
#endif

#include <iostream>
#include "player.h"

using namespace std;

class PrintID
{   
    Player player;

    public:
    PrintID();

    void PrintInform()
    {
        cout << "> Name: " << player.name << "\n"
        << "> Role: " << player.role << "\n"
        << "> Race: " << player.race << "\n"
        << "> Gender: " << player.gender << "\n\n";

        cout << "Is this ok? \n\n" << player.name << ", " << player.gender << " " << player.race << " " << player.role << "\n\n";  //remember to print eihter Caveman/Cavewomen
        cout << "y -Yes: start my exploration in Hell\n" << "n -No: correct my role, race and gender again\n" << "q -I QUIT NOW\n";
    };

    void PrintChoice()
    {
        cout << "1 -Pick a role\n" << "2 -Pick a race\n" << "3 -Pick a gender\n\n";
        cout << "y -Yes: All are alright now\n" << "q -I QUIT NOW\n";
    };

    void PrintRole()
    {
        cout << "Pick a role or profession\n\n";
        for (char i = 'a'; i < 'a' + max_role; i++){
            int j = i - 'a';
            cout << i <<" -"<< player.roleList[j] << endl;
        }
        cout << '*' << " -Random\n\n\n";
    };

    void PrintRace()
    {
        cout << "What's your race?\n\n";
        for (char i = 'a'; i < 'a' + max_race; i++){
            int j = i - 'a';
            cout << i <<" -"<< player.raceList[j] << endl;
        }
        cout  << '*' << " -Random\n\n\n";
    };

    void PrintGender()
    {
        cout << "What's your gender?\n\n";
        for (char i = 'a'; i < 'a' + max_gender; i++){
            int j = i - 'a';
            cout << i <<" -"<< player.genderList[j] << endl;
        }
        cout << '*' << " -Random\n\n\n";
    };

   void DealInput(char flag, int max)
    {
        if(max == max_role)
        {
            if (flag <='a' && flag >= 'a' + max_role){
                int iflag = flag - 'a';
                player.role = player.roleList[iflag];
            }
            else if (flag =='*')
                 player.randomRole(player.role);
            
        else if(max==max_race){
            if(flag <='a' && flag >= 'a' + max_race){
                int iflag = flag - 'a';
                player.role = player.raceList[iflag];
            }
            else if (flag =='*')
                player.randomRace(player.race);
            
        }
        else if (max == max_gender){
            if(flag <='a' && flag >= 'a' + max_gender){
                int iflag = flag - 'a';
                player.role = player.genderList[iflag];
            }
            else if (flag =='*')
                player.randomGender(player.gender);
            }
        }
    };
};