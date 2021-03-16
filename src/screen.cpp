#include "screen.h"
#include "env.h"
#include <iomanip>

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
    std::cout << "\n"
              << std::setfill('*') << '*'
              << std::setw(map_width) << "\n\n"
              << log << "\n\n"
              << std::setw(map_width)
              << '\n';
    // std::cout << '\t' << help[i] << '\n'; // printing help
    log = "";
}

// void Screen::fillHelp()
// {
//     help[0] = "\"Numpad\"... - Movement";
//     help[1] = "";
//     for (int i = 2; i < 21; i++)
//         help[i] = "";
// }