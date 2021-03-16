#ifndef Player_h
#define Player_h

#include <string>
#include <vector>
#include "env.h"

class Player
{
public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy;
    std::vector<std::string> debuffs[max_debuff];
    std::vector<std::string> buffs[max_buff];
};

#endif