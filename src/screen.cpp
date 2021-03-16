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
        std::cout << "      ";
        if (h == 0 || h == map_height - 1)
        {
            std::cout << "*******************************" << std::endl;
        }
        else
            std::cout << "*" << std::setfill(' ') << std::setw(30) << "*" << std::endl;
    }
    std::cout << "\n"
              << std::setfill('*') << std::setw(map_width + 2)
              << "\n\n"
              << log << "\n"
              << std::setw(map_width + 2)
              << std::endl
              << "\n\n";
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