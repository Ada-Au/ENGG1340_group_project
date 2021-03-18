#ifndef Player_h
#define Player_h

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int max_role = 12;
const int max_race = 4;
const int max_gender = 2;

class Player
{
    public:
        string name;
        string role;
        string gender;
        string race = "human";
        string roleList[max_role] = {"Archeologist", "Barbarian", "Caveman/Cavewoman", "Healer", "Knight", "Monk", "Priest/Priestess", "Rogue", "Ranger", "Samurai", "Tourist", "Wizard"};
        string raceList[max_race] = {"human", "drawf", "elf", "orc"};
        string genderList[max_gender] = {"male", "female"};
        Player();
        void setData(char flag, int max);
        void PrintInform();
};
#endif