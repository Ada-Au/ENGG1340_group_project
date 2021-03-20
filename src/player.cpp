#include "player.h"

Player::Player() {
    mark = '@';
    x = 1, y = 1;
    mp = 100, hp = 100, energy = 100;
    race = "human";
    debuffs->push_back(allDebuffs[1]);
    debuffs->push_back(allDebuffs[0]);
    debuffs->push_back(allDebuffs[2]);
    debuffs->push_back(allDebuffs[4]);
    debuffs->push_back(allDebuffs[6]);
    debuffs->push_back(allDebuffs[0]);

    buffs->push_back(allBuffs[1]);
    buffs->push_back(allBuffs[0]);
}

// void setData(char key, int max, Player player)
// {
//     //To-do: only allow players input one char & game response immediately
//     //       if players input invalid key, print LOGs
//     //       close the screen and open next options
//     int i = key - 'a';
//     switch (max)
//     {
//     case '1': // role
//     {
//         if (key <= 'a' && key >= 'a' + max_role)
//         {
//             player.role = roleList[i];
//         }
//         else if (key == '*')
//             player.role = roleList[rand() % max_role];
//         break;
//     }
//     case '2': // race
//     {
//         if (key <= 'a' && key >= 'a' + max_race)
//         {
//             player.race = raceList[i];
//         }
//         else if (key == '*')
//             player.race = raceList[rand() % max_race];
//         break;
//     }
//     case '3': // gender
//         if (key <= 'a' && key >= 'a' + max_gender)
//         {
//             player.gender = genderList[i];
//         }
//         else if (key == '*')
//             player.gender = genderList[rand() % max_role];
//         break;
//     }
// }