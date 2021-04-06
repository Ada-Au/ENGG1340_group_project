#ifndef Player_h
#define Player_h

#include "env.h"
// #include "things.h"
#include <string>
#include <vector>

using namespace std;

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, maxEnergy, maxMp, maxHp, exp, maxExp, damage, defense, weaponEnergy, weaponMp;
    int level;
    string armor, weapon;
    // void setData(char key, int max);
    vector<string> debuffs[max_debuff];
    vector<string> buffs[max_buff];
    string name, role, gender, race;
};

void upgradePlayer(Player &);
// void exchange(Player &, string);
// void updateState(Player &, string, int);

#endif