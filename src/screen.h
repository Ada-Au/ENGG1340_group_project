#ifndef Screen_h
#define Screen_h

#include <iostream>
#include "map.h"
#include "player.h"

class Screen
{
public:
    void renderScreen(Map, Player);
    // void fillHelp();
    std::string log;
};

#endif