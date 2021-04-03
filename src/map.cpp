#include "map.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Map::fill() {
    int maxTunnels = map_maxTunnels;
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            layout[h][w] = '#';
        }
    }

    srand(time(NULL));
    int currentRow = 1, currentCol = 1;
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
            if (((currentRow == 1) && (randomDirection[0] == -1)) ||
                ((currentCol == 1) && (randomDirection[1] == -1)) ||
                ((currentRow == map_height - 2) && (randomDirection[0] == 1)) ||
                ((currentCol == map_width - 2) && (randomDirection[1] == 1))) {
                break;
            } else {
                if (!(currentRow == 1 && currentCol == 1) &&
                    rand() % 100 >= 90 &&
                    layout[currentRow][currentCol] != ' ') {
                    layout[currentRow][currentCol] = 'M';
                } else
                    layout[currentRow][currentCol] = ' ';
                currentRow += randomDirection[0];
                currentCol += randomDirection[1];
                tunnelLength++;
            }
            if (tunnelLength > 0) {
                lastDirection = randomDirection;
                maxTunnels--;
            }
        }
    }

    cout << "\ndone:D\n\n\n";
}

void Map::update() {
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
                if (layout[h][w] == 'M' && rand() % 100 < 70) {
                    int randomN = rand() % 4;
                    int randomDirection[2] = {directions[randomN][0],
                                              directions[randomN][1]};
                    if (layout[h + randomDirection[0]]
                              [w + randomDirection[1]] == ' ' &&
                        newMap[h + randomDirection[0]]
                              [w + randomDirection[1]] != 'M') {
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

void Map::removeMonster(int x, int y) { layout[y][x] = ' '; }