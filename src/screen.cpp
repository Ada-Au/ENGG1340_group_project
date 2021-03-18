#include "screen.h"
#include "env.h"
#include <iomanip>

void Screen::renderScreen(Map map, Player player) // "capturing" the screen and printing it
{
    std::string stat[9] = {"[name]", "", "HP: " + std::to_string(player.hp), "MP: " + std::to_string(player.mp), "Energy: " + std::to_string(player.energy), "", "Debuffs: ", "", "Buffs: "};
    int debuffSize = player.debuffs->size();
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
        else if (h <= 7)
            std::cout << "*  " << stat[h - 1] << std::setw(28 - stat[h - 1].length()) << std::setfill(' ') << "*" << std::endl;
        else if (h - 8 < debuffSize)
        {
            std::cout << "*   - " << player.debuffs->at(h - 8) << std::setw(25 - player.debuffs->at(h - 8).length()) << std::setfill(' ') << "*" << std::endl;
        }
        else if (h - 8 < debuffSize + 2)
        {
            std::cout << "*  " << stat[h - 1 - debuffSize] << std::setw(28 - stat[h - 1 - debuffSize].length()) << std::setfill(' ') << "*" << std::endl;
        }
        else if (h - 10 - debuffSize < player.buffs->size())
        {
            std::cout << "*   - " << player.buffs->at(h - 10 - debuffSize) << std::setw(25 - player.buffs->at(h - 10 - debuffSize).length()) << std::setfill(' ') << "*" << std::endl;
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
    // std::cout << '\t' << help[i] << '\n';
    log = "";
}

// void Screen::fillHelp()
// {
//     help[0] = "\"Numpad\"... - Movement";
//     help[1] = "";
//     for (int i = 2; i < 21; i++)
//         help[i] = "";
// }