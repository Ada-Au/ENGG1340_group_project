#include "backpack.h"
#include "player.h"
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void generateDrops(Item items[]) {
    string heal = "", weapon = "";
    int healsNum, weaponsNum = 0;
    srand(time(NULL));
    int randNum = rand() % 100;
    if (randNum <= 3) {
        heal = "decent healing";
        weapon = "hammer";
        healsNum = rand() % 2;
    } else if (randNum <= 10) {
        heal = "average healing";
        if ((rand() % 1000) % 15 == 0) {
            weapon = "great sword";
        } else {
            weapon = "wand";
        }
        healsNum = rand() % 3;
    } else if (randNum <= 25) {
        heal = "poor healing";
        weapon = "long sword";
        healsNum = rand() % 6;
    } else if (randNum <= 40) {
        heal = "bread";
        weapon = "spear";
        healsNum = rand() % 3;
    } else if (randNum <= 90) {
        heal = "monster meat";
        weapon = "sword";
        healsNum = rand() % 7;
    }
    if (rand() % 10 >= 7) {
        weaponsNum = 1;
    }

    for (int i = 0; i < maxHealNum; i++) {
        if (heal == heals[i].name) {
            updateItems(heal, healsNum, heals[i].cost, 'A', items);
            break;
        }
    }
    for (int i = 0; i < maxWeaponNum; i++) {
        if (weapon == weapons[i].name) {
            updateItems(weapon, weaponsNum, weapons[i].cost, 'A', items);
            break;
        }
    }

    if (healsNum != 0 && heal != "")
        cout << heal << " x " << healsNum << " GET!\n";
    if (weaponsNum != 0 && weapon != "")
        cout << weapon << " x " << weaponsNum << " GET!\n";
}

void sortItems(Item items[]) {
    string tempName;
    int tempNum;
    int tempCost;
    for (int i = 0; i < maxSpace - 1; i++) {
        for (int j = 0; j < maxSpace - i - 1; j++) {
            if (items[j].num <= 0) {
                items[j].num = 0;
                tempName = items[j].name;
                tempNum = items[j].num;
                tempCost = items[j].cost;
                items[j].name = items[j + 1].name;
                items[j].num = items[j + 1].num;
                items[j].cost = items[j + 1].cost;
                items[j + 1].name = tempName;
                items[j + 1].num = tempNum;
                items[j + 1].cost = tempCost;
            }
        }
    }
}

void displayBackpack(Item items[], bool isShop) {    // Also display player's state if possible
    sortItems(items);
    cout << "Items\t\t\t\t\t\tNumber";
    if (isShop) {
        cout << "\t\tCost" << endl;
    } else {
        cout << endl;
    }
    for (int i = 0; i < maxSpace; i++) {
        // TODO can u make it not to run 50 time everytime?
        if (items[i].name != "" && items[i].num > 0) {
            cout << (i + 1) << "  " << items[i].name << setw(48 - items[i].name.length() - to_string(i + 1).length()) << setfill(' ') << items[i].num;
            if (isShop) {
                cout << "\t\t" << items[i].cost << " G" << endl;
            } else {
                cout << endl;
            }
        }
    }
    if (!isShop) {
        cout << "Press [number] to select items or [Q] to exit.\n"
             << "Press [W] to take off weapon or [A] to take off armor.\n\n";
    }
}

int findItem(string name, Item items[]) {
    for (int i = 0; i < maxSpace; i++) {
        if (name == items[i].name)
            return i;
    }
    return -1;
}

void updateState(Player &player, string object, int number) {
    for (int i = 0; i < maxHealNum; i++) {
        if (object == heals[i].name) {
            player.hp += (heals[i].healing * number);
            player.energy += (heals[i].fullness * number);
            break;
        }
    }
    if (player.hp > player.maxHp)
        player.hp = player.maxHp;
    if (player.energy > player.maxEnergy)
        player.energy = player.maxEnergy;
}

//To-do:
// 1) input items after monster fighting / getting things on ground
// 2) update number of items
// 3) sort by time(old to new)
void updateItems(string name, int number, int cost, char flag, Item items[]) {    // flag - A for adding, D for delete
    if (number > maxStack)
        number = maxStack;

    if (flag == 'D')
        number = -number;

    if (findItem(name, items) == -1 && number != 0) {
        for (int i = 0; i < maxSpace; i++) {
            if (items[i].name == "") {
                items[i].name = name;
                items[i].num += number;
                items[i].cost = cost;
                break;
            }
        }
    } else {
        items[findItem(name, items)].num += number;
        if (items[findItem(name, items)].num > maxStack)
            items[findItem(name, items)].num = maxStack;
    }
}

void openBackpack(Item items[], Player &player) {
    string choice;    // string for two digit nums
    displayBackpack(items, false);
    cin >> choice;
    while (choice != "q") {
        int pos;
        for (pos = 0; pos < maxSpace; pos++) {    //Find items pos in backpack
            if (choice == to_string(pos + 1))
                break;
        }
        if (choice == to_string(pos + 1)) {    //Select item in backpack
            //Find item if it's healing
            for (int i = 0; i < maxHealNum; i++) {
                if (items[pos].name == heals[i].name) {
                    cout << items[pos].name + " is selected.\t" + heals[i].desc << endl;
                    cout << "Amount to use: ";
                    int amount;
                    cin >> amount;
                    while (amount > items[pos].num || amount < 0) {
                        cout << "Exceeds amount, please enter a valid number: ";
                        cin >> amount;
                    }
                    cout << "\n\n";
                    updateItems(items[pos].name, amount, heals[i].cost, 'D', items);
                    updateState(player, items[pos].name, amount);
                    break;
                }
            }
            //Find item if it's armor
            for (int i = 0; i < maxArmorNum; i++) {
                if (items[pos].name == armors[i].name) {
                    cout << items[pos].name + " is equipped.\t" + armors[i].desc + "\n\n";
                    if (player.armor != "") {
                        for (int j = 0; j < maxArmorNum; j++) {
                            if (player.armor == armors[j].name) {
                                updateItems(player.armor, 1, armors[j].cost, 'A', items);
                                break;
                            }
                        }
                    }
                    player.armor = items[pos].name;
                    // use armor
                    for (int i = 0; i < maxArmorNum; i++) {
                        if (player.armor == armors[i].name) {
                            player.aDefense = armors[i].defense;
                            break;
                        }
                    }
                    updateItems(player.armor, 1, armors[i].cost, 'D', items);
                    break;
                }
            }
            //Find item if it's weapon
            for (int i = 0; i < maxWeaponNum; i++) {
                if (items[pos].name == weapons[i].name) {
                    cout << items[pos].name + " is equipped.\t" + weapons[i].desc + "\n\n";
                    //Exchange weapon
                    if (player.weapon.name != "") {
                        //Add player's old weapon in backpack & Update weapon's cost into item's
                        for (int j = 0; j < maxWeaponNum; j++) {
                            if (player.weapon.name == weapons[i].name) {
                                updateItems(player.weapon.name, 1, weapons[i].cost, 'A', items);
                                break;
                            }
                        }
                    }
                    player.weapon.name = items[pos].name;
                    // use weapon
                    for (int i = 0; i < maxWeaponNum; i++) {
                        if (player.weapon.name == weapons[i].name) {
                            player.weapon.damage = weapons[i].damage;
                            player.weapon.energy = weapons[i].energyLose;
                            player.weapon.mp = weapons[i].mpLose;
                            break;
                        }
                    }
                    updateItems(player.weapon.name, 1, weapons[i].cost, 'D', items);
                    break;
                }
            }
        } else if (choice == "a" || choice == "A") {
            if (player.armor != "") {
                //Add player's old armor in backpack & Update armor's cost into item's
                for (int i = 0; i < maxArmorNum; i++) {
                    if (player.armor == armors[i].name) {
                        updateItems(player.armor, 1, armors[i].cost, 'A', items);
                        break;
                    }
                }
                player.armor = "Empty";
                player.aDefense = 0;
            } else {
                cout << "You have no armor on body.\n";
            }
        } else if (choice == "w" || choice == "W") {
            if (player.weapon.name != "") {
                //Add player's old weapon in backpack & Update weapon's cost into item's
                for (int i = 0; i < maxWeaponNum; i++) {
                    if (player.weapon.name == weapons[i].name) {
                        updateItems(player.weapon.name, 1, weapons[i].cost, 'A', items);
                        break;
                    }
                }
                player.weapon = {"Empty", 2, 0, 1};
            } else {
                cout << "You have no weapon on hand.\n";
            }
        } else {
            cout << "Press [number] to select items or [Q] to exit.\n"
                 << "Press [W] to take off weapon or [A] to take off armor.\n\n";
        }
        displayBackpack(items, false);
        cin >> choice;
    }
}

void generateChestItems(Item items[], Player &player) {
    string armor = "";
    int randNum = rand() % 100, armorNum = 1;
    if (randNum <= 3) {
        armor = "silver shield";
    } else if (randNum <= 10) {
        armor = "leather shield";
    } else if (randNum <= 25) {
        armor = "wood shield";
    } else if (randNum <= 75) {
        armor = "boat remains";
        armorNum = rand() % 5;
    }

    for (int i = 0; i < maxArmorNum; i++) {
        if (armor == armors[i].name) {
            updateItems(armor, armorNum, armors[i].cost, 'A', items);
            break;
        }
    }

    int coinNum;
    if (armor != "") {
        cout << armor << " x 1 GET!\n";
        coinNum = rand() % 8;
    } else {
        coinNum = rand() % 16;
    }
    player.coin += coinNum;
    if (coinNum > 0) {

        cout << coinNum << "G GET!\n";
    }
}
