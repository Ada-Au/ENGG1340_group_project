#include "screen.h"
#include "constants.h"

void Screen::renderScreen(Map map, Player player) // "capturing" the screen and printing it
{
    for (int h = 0; h < map_height; h++)
    {
        for (int w = 0; w < map_width; w++)
        {
            if (h == player.y && w == player.x)
                std::cout << player.mark;
            else
                std::cout << map.layout[h][w];
        }
        std::cout << std::endl;
    }
    std::cout << log << '\n';
    // std::cout << '\t' << help[i] << '\n'; // printing help
    // log = "";
}

// void Screen::fillHelp() //filling help
// {
//     help[0] = "\"Numpad\"... - Movement"; //help message № 1
//     help[1] = "";                         //help message № 2
//     for (int i = 2; i < 21; i++)          //blanket messages
//         help[i] = "";
// }