#ifndef Player_h
#define Player_h

#include "env.h"
#include <string>
#include <vector>

using namespace std;

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, maxMp, maxHp;
    // void setData(char key, int max);
    std::vector<std::string> debuffs[max_debuff];
    std::vector<std::string> buffs[max_buff];
    string name, role, gender, race;
};

#endif