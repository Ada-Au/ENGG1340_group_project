#include "map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Map::fill()
{
    int maxTunnels = map_maxTunnels;
    for (int h = 0; h < map_height; h++)
    {
        for (int w = 0; w < map_width; w++)
        {
            layout[h][w] = '#';
        }
    }

    srand(time(NULL));
    int currentRow = 1, currentCol = 1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int temp[2] = {0, 0};
    int *lastDirection = temp, *randomDirection;

    while (maxTunnels > 0 && map_height > 0 && map_width > 0 && maxLength > 0)
    {
        randomDirection = directions[rand() % 4];
        while (
            (randomDirection[0] == -lastDirection[0] &&
             randomDirection[1] == -lastDirection[1]) ||
            (randomDirection[0] == lastDirection[0] &&
             randomDirection[1] == lastDirection[1]))
        {
            randomDirection = directions[rand() % 4];
        }

        int randomLength = rand() % maxLength, tunnelLength = 0;
        while (tunnelLength < randomLength)
        {
            if (((currentRow == 1) && (randomDirection[0] == -1)) ||
                ((currentCol == 1) && (randomDirection[1] == -1)) ||
                ((currentRow == map_height - 2) && (randomDirection[0] == 1)) ||
                ((currentCol == map_width - 2) && (randomDirection[1] == 1)))
            {
                break;
            }
            else
            {
                layout[currentRow][currentCol] = ' ';
                currentRow += randomDirection[0];
                currentCol += randomDirection[1];
                tunnelLength++;
            }
            if (tunnelLength > 0)
            {
                lastDirection = randomDirection;
                maxTunnels--;
            }
        }
        if (maxTunnels >= 0)
        {
            std::cout << "generating: " << map_maxTunnels - maxTunnels << "/" << map_maxTunnels << std::endl;
        }
    }

    std::cout << std::endl
              << "done:D " << std::endl
              << std::endl;
}
