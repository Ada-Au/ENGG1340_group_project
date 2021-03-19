#ifndef Player_h
#define Player_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "env.h"

using namespace std;

const int max_role = 12;
const int max_race = 4;
const int max_gender = 2;

class Player
{
    public:
  Player();
    char mark;
    int x, y;
    float mp, hp, energy;
    vector<string> debuffs[max_debuff];
    vector<string> buffs[max_buff];
    string name;
    string role;
    string gender;
    string race = "human";
    string roleList[max_role] = {"Archeologist", "Barbarian", "Caveman/Cavewoman", "Healer", "Knight", "Monk", "Priest/Priestess", "Rogue", "Ranger", "Samurai", "Tourist", "Wizard"};
    string raceList[max_race] = {"human", "drawf", "elf", "orc"};
    string genderList[max_gender] = {"male", "female"};
    void setData(char flag, int max);
    void PrintInform();
};
#endif