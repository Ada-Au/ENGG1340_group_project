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
    int defenseValue;
};

struct Weapons{
    string name;
    int dps;    //attack damage
    int power;  // magic attack damage
    int mpLose;
};

struct Tools{
    string name;
};


#endif