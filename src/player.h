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
    int time;
    // rate of attack increase
    // can add other
};
const Buff allDebuffs[maxDebuff] = {{"Burning", -2, 0, 5}, {"Freezing", -2, 0, 5}, {"Poison", -3, -2, 5}, {"Hunger", -2, -1, 5}, {"Bleeding", -5, 0, 5}};
const Buff allBuffs[maxBuff] = {{"Full", 2, 0, 5}, {"Focus", 0, 2, 5}};

class Player {
  public:
    Player();
    char mark;
    int x, y;
    float mp, hp, energy, exp, maxExp, maxHp;    // fixed or system set variables
    float maxMp, maxEnergy;                      // allow player to upgrade
    int damage, defense;

    int level, gameLevel, coin;
    struct playerWeapon {
        string name;
        float damage, mp, energy;
    } weapon;
    string armor;
    float aDefense;
    vector<Buff> debuffs;
    vector<Buff> buffs;
    string name, role, gender, race;
    bool isFirst;
};

void upgradePlayer(Player &);
void addBuff(bool, string, Player &);
void updateOnBuff(Player &);

#endif