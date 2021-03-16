#ifndef Map_h
#define Map_h
#endif

#include "constants.h"

class Map
{
public:
    void fill();

public:
    char layout[map_height][map_width];
};