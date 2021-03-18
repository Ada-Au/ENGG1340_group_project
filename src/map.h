#ifndef Map_h
#define Map_h

#include "env.h"
#include <vector>

class Map
{
public:
    void fill();
    char layout[map_height][map_width];
    void update();
    void removeMonster(int, int);
    std::vector<int> monsterX;
    std::vector<int> monsterY;
};

#endif