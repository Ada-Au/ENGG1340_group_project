#ifndef Screen_h
#define Screen_h

#include "map.h"
#include "player.h"
#include <iomanip>
#include <iostream>

class Screen {
  public:
    void renderScreen(Map, Player);
    // void fillHelp();
    std::string log;
};

#endif