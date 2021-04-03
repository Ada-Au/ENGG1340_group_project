#ifndef Things_h
#define Things_h
#include <iostream>
#include <string>

using namespace std;

struct Heals{
    string name;
    int fullness;
    int healing;
};

struct Armors{
    string name;
    double defenseRate; // multiplication of player's defense value
};

struct Weapons{
    string name;
    double damage;         // multiplication of attack damage
    int energyLose;     // consume of energy for each attack
    int mpLose;         //consume of mp for each magic attack
};

const Heals monsterMeat = {"monster meat", 25, -10};
const Heals bread = {"bread", 30, 5};
const Heals poorHealing = {"poorHealing", 0, 10};
const Heals mediumHealing = {"mediumHealing", 0, 50};
const Heals highHealing = {"highHealing", 0, 100};

const Armors cloths = {"cloths", 1.05}
const Armors woodChest = {"wood chest", 1.1};
const Armors leatherChest = {"leather chest", 1.25};
const Armors silverChest = {"silver chest", 1.5};

const Weapons hammer = {"hammer", 2, 30, 0};
const Weapons greatSword = {"great sword", 1.5, 15, 0};
const Weapons longSword = {"long sword", 1.25, 5, 0};
const Weapons spear = {"spear", 1.1, 10, 0};
const Weapons sword = {"sword", 1, 1, 0};
const wand = {"wand", 1.5, 0, 15};



#endif