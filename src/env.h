#ifndef ENV_H
#define ENV_H
#include <string>

const int map_height = 30;
const int map_width = 60;
const int map_maxTunnels = 1200;
const int maxLength = 10;
const int max_debuff = 12; // +4 is the min map size
const std::string debuffs[max_debuff] = {
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
    "Hallucination"};

#endif