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
    void renderScreen(Map map, Player player); // "capturing" the screen
    // void fillHelp();                                     // filling help

    // public:
    // std::string help[21]; // It's description of controls
    std::string log;
    // char **map;           // it's the screen we are printing on or "camera view" if you can call it
    // int cordX, cordY; // coordinates of the screen
};