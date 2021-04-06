#include "things.h"
#include <iostream>
#include <time.h>

using namespace std;

void generateThings(Item item[])
{
    string heal = "", weapon = "", armor = "";
    int healsNum, weaponsNum, armorsNum;
    srand(time(NULL));
    if (rand() % 100 >= 95){
        heal = "high healing";
        armor = "silver chest";
        weapon = "hammer";
    }else if (rand() % 100 >= 75){
        heal = "medium healing";
        armor = "leather chest";
        if ((rand() % 100) % 2 == 0){
          weapon = "great sword";  
        }else{
            weapon = "wand";
        }
    }else if (rand() % 100 >= 50){
        heal = "poor healing";
        armor = "wood chest";
        weapon = "long sword";
    }else if (rand() % 100 >= 40){
        heal = "bread";
        armor = "cloths";
        weapon = "spear";
    }else{
        heal = "monster meat";
        weapon = "sword";
    }
    armorsNum = (rand() % 2);
    weaponsNum = (rand() % 2);
    healsNum =  (rand() % 6);

    updateItems(heal, healsNum, 'A', item);
    updateItems(armor, armorsNum, 'A', item);
    updateItems(weapon, weaponsNum, 'A', item);

    if (healsNum != 0 && heal != "")
        cout << heal << " x " << healsNum << " GET!\n";
    if (armorsNum != 0 && armor != "")
        cout << armor << " x " << armorsNum << " GET!\n";
    if (weaponsNum != 0 && weapon != "")
        cout << weapon << " x " << weaponsNum << " GET!\n";

}