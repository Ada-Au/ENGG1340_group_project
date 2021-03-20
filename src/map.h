#ifndef Map_h
#define Map_h

#include "env.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Map {
  public:
    void fill();
    char layout[map_height][map_width];
    void update();
    void removeMonster(int, int);
};

#endif