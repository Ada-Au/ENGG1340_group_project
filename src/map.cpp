#include "map.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Map::fill() {
    int maxTunnels = map_maxTunnels;
    int shopPos = rand() % (map_maxTunnels - 100);
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            layout[h][w] = '#';
        }
    }

    srand(time(NULL));
    int yPos = 1, xPos = 1, tempY = 2, tempX = 2;
    int temp[2] = {0, 0};
    int *lastDirection = temp, *randomDirection;

    cout << "generating... ";

    while (maxTunnels > 0 && map_height > 0 && map_width > 0 && maxLength > 0) {
        randomDirection = directions[rand() % 4];
        while ((randomDirection[0] == -lastDirection[0] &&
                randomDirection[1] == -lastDirection[1]) ||
               (randomDirection[0] == lastDirection[0] &&
                randomDirection[1] == lastDirection[1])) {
            randomDirection = directions[rand() % 4];
        }

        int randomLength = rand() % maxLength, tunnelLength = 0;
        while (tunnelLength < randomLength) {
            if (((yPos == 1) && (randomDirection[0] == -1)) ||
                ((xPos == 1) && (randomDirection[1] == -1)) ||
                ((yPos == map_height - 2) && (randomDirection[0] == 1)) ||
                ((xPos == map_width - 2) && (randomDirection[1] == 1))) {
                break;
            } else {
                if (!(yPos == 1 && xPos == 1) && rand() % 100 >= 90 && layout[yPos][xPos] != ' ')
                    layout[yPos][xPos] = 'M';
                else if ((!(yPos == 1 && xPos == 1) && maxTunnels == shopPos) || layout[yPos][xPos] == 'N')
                    layout[yPos][xPos] = 'N';
                else if ((!(yPos == 1 && xPos == 1) && rand() % 100 == 1) && layout[yPos][xPos] == ' ')
                    layout[yPos][xPos] = 'C';
                else if (rand() % 100 == 1 && layout[yPos][xPos] == ' ') {
                    tempY = yPos;
                    tempX = xPos;
                } else
                    layout[yPos][xPos] = ' ';

                yPos += randomDirection[0];
                xPos += randomDirection[1];
                tunnelLength++;
            }
            if (tunnelLength > 0) {
                lastDirection = randomDirection;
                maxTunnels--;
            }
        }
    }
    if (yPos == 1 && xPos == 1)
        layout[tempY][tempX] = 'S';
    else
        layout[yPos][xPos] = 'S';

    cout << "\ndone:D\tPress enter to continue...\n\n\n ";
}

void Map::update(int x, int y) {
    srand(time(NULL));
    char newMap[map_height][map_width];
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            newMap[h][w] = ' ';
        }
    }
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            if (newMap[h][w] != 'M') {
                newMap[h][w] = layout[h][w];
                if (layout[h][w] == 'M' && rand() % 10 < 6) {
                    int randomN = rand() % 4;
                    int randomDirection[2] = {directions[randomN][0],
                                              directions[randomN][1]};
                    if (layout[h + randomDirection[0]]
                              [w + randomDirection[1]] == ' ' &&
                        newMap[h + randomDirection[0]]
                              [w + randomDirection[1]] != 'M' &&
                        (h + randomDirection[0]) != y && (w + randomDirection[1]) != x) {
                        newMap[h][w] = ' ';
                        newMap[h + randomDirection[0]][w + randomDirection[1]] = 'M';
                    }
                }
            }
        }
    }
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            layout[h][w] = newMap[h][w];
        }
    }
}

void Map::removeMapIcon(int x, int y) { layout[y][x] = ' '; }