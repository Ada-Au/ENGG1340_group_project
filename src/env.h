#ifndef ENV_H
#define ENV_H
#include <string>

const int map_height = 30;
const int map_width = 60;
const int map_maxTunnels = 1200;
const int maxLength = 10;
const int max_debuff = 12, max_buff = 2; // these 2 + 8 is the min map size
const std::string allDebuffs[max_debuff] = {
    "Burning",
    "Freezing",
    "Blind",
    "Poison",
    "Hunger",
    "Bleeding",
    "Fear",
    "Nervous",
    "Wet",
    "Cursed",
    "Paralyzed",
    "Hallucination",
};

const std::string allBuffs[max_buff] = {
    "Full",
    "Anger",
};

const int max_role = 12;
const int max_race = 4;
const int max_gender = 2;
const std::string roleList[max_role] = {"Archeologist", "Barbarian", "Caveman/Cavewoman", "Healer", "Knight", "Monk", "Priest/Priestess", "Rogue", "Ranger", "Samurai", "Tourist", "Wizard"};
const std::string raceList[max_race] = {"human", "drawf", "elf", "orc"};
const std::string genderList[max_gender] = {"male", "female"};

#endif