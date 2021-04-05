#ifndef Player_h
#define Player_h

#include "env.h"
#include <string>
#include <vector>

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, maxMp, maxHp, exp, maxExp;
    int level;
    std::string armor, weapon;
    // void setData(char key, int max);
    std::vector<std::string> debuffs[max_debuff];
    std::vector<std::string> buffs[max_buff];
    std::string name, role, gender, race;
};

#endif