#ifndef Things_h
#define Things_h
#include <iostream>
#include <string>

using namespace std;

struct Heals{
    string name;
    int fullness;
    int healing;
    int sell;
    int buy;
};

struct Armors{
    string name;
    double defenseRate; // multiplication of player's defense value
    int sell;
    int buy;
};

struct Weapons{
    string name;
    double damage;      // multiplication of attack damage
    int energyLose;     // consume of energy for each attack
    int mpLose;         //consume of mp for each magic attack
    int sell;
    int buy;
};

const Heals monsterMeat = {"monster meat", 25, -10, 2, 5};
const Heals bread = {"bread", 30, 5, 5, 25};
const Heals poorHealing = {"poorHealing", 0, 10, 8, 30};
const Heals mediumHealing = {"mediumHealing", 0, 50, 25, 90};
const Heals highHealing = {"highHealing", 0, 100, 50, 200};

const Armors cloths = {"cloths", 1.05, 10, 35};
const Armors woodChest = {"wood chest", 1.1, 20, 70};
const Armors leatherChest = {"leather chest", 1.25, 35, 122};
const Armors silverChest = {"silver chest", 1.5, 100, 350};

const Weapons hammer = {"hammer", 2, 30, 0, 45, 158};
const Weapons greatSword = {"great sword", 1.5, 15, 0, 40, 140};
const Weapons longSword = {"long sword", 1.25, 5, 0, 36, 126};
const Weapons spear = {"spear", 1.1, 10, 0, 32, 112};
const Weapons sword = {"sword", 1, 1, 0, 12, 36};
const Weapons wand = {"wand", 1.5, 0, 15, 50, 275};



#endif