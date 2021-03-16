#include "map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Map::fill()
{
    int height = 20, width = 20;
    int maxTunnels = 250, maxLength = 10;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            layout[h][w] = '#';
        }
    }

    srand(time(NULL));
    int currentRow = 1, currentCol = 1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int temp[2] = {0, 0};
    int *lastDirection = temp, *randomDirection;

    while (maxTunnels > 0 && height > 0 && width > 0 && maxLength > 0)
    {
        randomDirection = directions[rand() % 4];
        while ((randomDirection[0] == -lastDirection[0] &&
                randomDirection[1] == -lastDirection[1]) ||
               (randomDirection[0] == lastDirection[0] &&
                randomDirection[1] == lastDirection[1]))
        {
            randomDirection = directions[rand() % 4];
        }

        int randomLength = rand() % maxLength, tunnelLength = 0;
        while (tunnelLength < randomLength)
        {
            // break the loop if it is going out of the layout
            if (((currentRow == 1) && (randomDirection[0] == -1)) ||
                ((currentCol == 1) && (randomDirection[1] == -1)) ||
                ((currentRow == height - 2) && (randomDirection[0] == 1)) ||
                ((currentCol == width - 2) && (randomDirection[1] == 1)))
            {
                break;
            }
            else
            {
                layout[currentRow][currentCol] = '.';
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
            std::cout << "generating: " << 250 - maxTunnels << "/250" << std::endl;
        }
    }

    std::cout << std::endl
              << "done:D " << std::endl
              << std::endl;
    // for (int h = 0; h < height; h++)
    // {
    //     for (int w = 0; w < width; w++)
    //     {
    //         std::cout << layout[h][w];
    //     }
    //     std::cout << std::endl;
    // }
}
