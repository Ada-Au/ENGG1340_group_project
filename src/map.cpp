#include "map.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

// four directions
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// build the map including stair, monster, shop and chests
void Map::fill() {
    // maximum blank space(without walls) map will have
    int maxTunnels = map_maxTunnels;
    // add random shop position
    int shopPos = rand() % (map_maxTunnels - 100);
    // create a map filled with walls
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            layout[h][w] = '#';
        }
    }

    // seed random and set position for building map as 1,1 and stair inital position
    srand(time(NULL));
    int yPos = 1, xPos = 1, tempY = 2, tempX = 2;
    int temp[2] = {0, 0};
    int *lastDirection = temp, *randomDirection;

    cout << "generating... ";

    // start building map, a tunnel(space) will be form at 1,1 and move around the map to create rooms for player to move
    while (maxTunnels > 0 && map_height > 0 && map_width > 0 && maxLength > 0) {
        randomDirection = directions[rand() % 4];
        // to prevent the tunnel build in the direction same as before
        while ((randomDirection[0] == -lastDirection[0] &&
                randomDirection[1] == -lastDirection[1]) ||
               (randomDirection[0] == lastDirection[0] &&
                randomDirection[1] == lastDirection[1])) {
            randomDirection = directions[rand() % 4];
        }

        // add a random length for the tunnel to be
        int randomLength = rand() % maxLength, tunnelLength = 0;
        // use tunnelLength to count for the length that tunnel already built
        while (tunnelLength < randomLength) {
            // to prevent the tunnel break the outside wall of the game
            if (((yPos == 1) && (randomDirection[0] == -1)) ||
                ((xPos == 1) && (randomDirection[1] == -1)) ||
                ((yPos == map_height - 2) && (randomDirection[0] == 1)) ||
                ((xPos == map_width - 2) && (randomDirection[1] == 1))) {
                break;
            } else {
                if (!(yPos == 1 && xPos == 1) && rand() % 100 >= 90 && layout[yPos][xPos] != ' ')
                    layout[yPos][xPos] = 'M';    // have a 10% chance of having a monster generate on map
                else if ((!(yPos == 1 && xPos == 1) && maxTunnels == shopPos) || layout[yPos][xPos] == 'N')
                    layout[yPos][xPos] = 'N';    // spawn shop base on shop position
                else if ((!(yPos == 1 && xPos == 1) && rand() % 100 == 1) && layout[yPos][xPos] != ' ')
                    layout[yPos][xPos] = 'C';    // have a 1% chance of having a chest generate on map if the space is empty
                else
                    layout[yPos][xPos] = ' ';    // set a empty space
                if (rand() % 100 == 1 && layout[yPos][xPos] == ' ') {
                    // randomize stair position
                    tempY = yPos;
                    tempX = xPos;
                }

                // update tunnel position
                yPos += randomDirection[0];
                xPos += randomDirection[1];
                // count tunnel length added
                tunnelLength++;
            }
            // set random direction for tunnel and count the tunnel printed
            if (tunnelLength > 0) {
                lastDirection = randomDirection;
                maxTunnels--;
            }
        }
    }
    // add stair at end of tunnel if it is not on 1,1 else put stair at the presetted position
    if (yPos == 1 && xPos == 1)
        layout[tempY][tempX] = 'S';
    else
        layout[yPos][xPos] = 'S';

    cout << "\ndone:D\tPress enter to continue...\n\n\n ";
}

// Update map monster every step player take
void Map::update(int x, int y) {
    srand(time(NULL));
    char newMap[map_height][map_width];
    // create an empty map
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            newMap[h][w] = ' ';
        }
    }
    // copy the current map to the empty map with monster position updated
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            // do not update the new map when there is already monster on that position so monster will not be on another monster
            if (newMap[h][w] != 'M') {
                // copy everything on map
                newMap[h][w] = layout[h][w];
                // monster have a 50% chance to move
                if (layout[h][w] == 'M' && rand() % 10 < 6) {
                    // get a random direction to move
                    int randomN = rand() % 4;
                    int randomDirection[2] = {directions[randomN][0],
                                              directions[randomN][1]};
                    // check if the new position is empty
                    if (layout[h + randomDirection[0]]
                              [w + randomDirection[1]] == ' ' &&
                        newMap[h + randomDirection[0]]
                              [w + randomDirection[1]] != 'M' &&
                        (h + randomDirection[0]) != y && (w + randomDirection[1]) != x) {
                        // update new map
                        newMap[h][w] = ' ';
                        newMap[h + randomDirection[0]][w + randomDirection[1]] = 'M';
                    }
                }
            }
        }
    }
    // copy new map to layout
    for (int h = 0; h < map_height; h++) {
        for (int w = 0; w < map_width; w++) {
            layout[h][w] = newMap[h][w];
        }
    }
}

// remove anything that is on the given position
void Map::removeMapIcon(int x, int y) { layout[y][x] = ' '; }