#ifndef Player_h
#define Player_h

#include "env.h"
#include <string>
#include <vector>

using namespace std;

const int maxDebuff = 12, maxBuff = 2;    // these 2 + 8 is the min map size

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, maxMp, maxHp;
    struct Buff {
        string name;
        float hp, mp;
        // can add other
    };
    const Buff allDebuffs[maxDebuff] = {{"Burning", -2, 0}, {"Freezing", -2, 0}, {"Poison", -3, -2}, {"Hunger", -2, -1}, {"Bleeding", -5, 0}};
    const Buff allBuffs[maxBuff] = {{"Full", 2, 0}, {"Anger", 2, 2}};
    vector<Buff> debuffs[maxDebuff];
    vector<Buff> buffs[maxBuff];
    string name, role, gender, race;
};

#endif