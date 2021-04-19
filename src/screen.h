#ifndef Screen_h
#define Screen_h

#include "env.h"
#include "map.h"
#include "player.h"

const int helpSize = 9;

class Screen {
  public:
    void renderScreen(Map, Player);

    // void fillHelp();
    std::string log;
};

const char helpScreen[helpSize][map_width] = {
    "Keyboard shortcuts",
    "- [W]\t move Up",
    "- [A]\t move Left",
    "- [S]\t move Down",
    "- [D]\t move Right",
    "- [B]\t open backpack",
    "- [Q]\t quit game",
    "- [H]\t open Help",
    "",
};

void printHelp();

#endif