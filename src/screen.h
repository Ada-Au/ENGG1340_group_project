#include <iostream>
// #include <string.h>

#ifndef Map_h
#include "map.h"
#endif

#ifndef Player_h
#include "player.h"
#endif

class Screen
{
public:
    void renderScreen(Map, Player);
    // void fillHelp();
    std::string log;
};