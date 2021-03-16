#include <string>
#include "env.h"

#ifndef Player_h
#define Player_h
#endif

class Player
{
public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy;
    std::string debuff[max_debuff];
};