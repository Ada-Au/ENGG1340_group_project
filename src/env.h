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

#endif