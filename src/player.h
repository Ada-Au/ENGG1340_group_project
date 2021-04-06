#ifndef Player_h
#define Player_h

#include "env.h"
#include <string>
#include <vector>

using namespace std;

const int maxDebuff = 12, maxBuff = 2;    // these 2 + 8 is the min map size

struct Buff {
    string name;
    float hp, mp;
    // rate of attack increase
    // can add other
};
const Buff allDebuffs[maxDebuff] = {{"Burning", -2, 0}, {"Freezing", -2, 0}, {"Poison", -3, -2}, {"Hunger", -2, -1}, {"Bleeding", -5, 0}};
const Buff allBuffs[maxBuff] = {{"Full", 2, 0}, {"Focus", 0, 2}};

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, maxMp, maxHp;
    vector<Buff> debuffs;
    vector<Buff> buffs;
    string name, role, gender, race;
};

void addBuff(bool, int, Player &);
void updateOnBuff(Player &);

#endif