#ifndef Map_h
#define Map_h

#include "env.h"

class Map {
  public:
    void fill();
    char layout[map_height][map_width];
    void update(int, int);
    void removeMapIcon(int, int);
};

#endif