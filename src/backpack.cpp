#include "backpack.h"
#include "player.h"
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

// Generate drops after defeating monsters and update player's backpack
void generateDrops(vector<Item> &items, Player &player) {
    string heal = "", weapon = "";
    int healsNum, weaponsNum = 0;
    srand(time(NULL));
    int randNum = rand() % 100;    // random number to determine generation of items
    if (randNum <= 3) {            // 3% to generate the best healing and weapon
        heal = "decent healing";
        weapon = "hammer";
        healsNum = rand() % 2;
    } else if (randNum <= 10) {    // 7% to generate average healing and great sword/wand
        heal = "average healing";
        if ((rand() % 1000) % 15 == 0) {
            weapon = "great sword";
        } else {
            weapon = "wand";
        }
        healsNum = rand() % 3;
    } else if (randNum <= 30) {    // 20% to generate poor healing and long sword
        heal = "poor healing";
        weapon = "long sword";
        healsNum = rand() % 6;
    } else if (randNum <= 50) {    // 30 % to generate bread and spear
        heal = "bread";
        weapon = "spear";
        healsNum = rand() % 3 + 1;
    } else if (randNum <= 90) {    // 40% to generate poor healing, monster meat and sword
        int temp = rand() % 4 + 1;
        cout << "poor healing x " << temp << " GET!\n";
        cout << heals[2].cost;
        updateItems("poor healing", temp, heals[2].cost, 'A', items);
        heal = "monster meat";
        weapon = "sword";
        healsNum = rand() % 7;
    }
    if (rand() % 5 == 1) {
        weaponsNum = 1;
    }

    // Update player's backpack
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
    int coinNum;    // number of coin after defeating monster (0 - 7)
    coinNum = rand() % 7;

    if (healsNum != 0 && heal != "")
        cout << heal << " x " << healsNum << " GET!\n";
    if (weaponsNum != 0 && weapon != "") {
        cout << weapon << " x " << weaponsNum << " GET!\n";
        coinNum = rand() % 4;
    }

    player.coin += coinNum;
    if (coinNum > 0) {
        cout << coinNum << " G GET!\n";
    }
}

// If number of item is less than or equal to 0,
// Erase that item so that it'll not be shown in displayBackpack().
void sortItems(vector<Item> &items) {
    Item temp;
    for (int i = 0; i < items.size(); i++) {
        if (items[i].num <= 0) {
            items.erase(items.begin() + i);
        }
    }
}

// Display player's backpack item
// Input: isShop: boolean for checking player opens backpack in map/shop
//                is to determine whether to display items' costs and operator
void displayBackpack(vector<Item> &items, bool isShop) {
    sortItems(items);
    cout << "Items\t\t\t\t\t\tNumber";
    if (isShop) {
        cout << "\t\tCost" << endl;
    } else {
        cout << endl;
    }
    for (int i = 0; i < items.size(); i++) {
        cout << (i + 1) << "  " << items[i].name << setw(48 - items[i].name.length() - to_string(i + 1).length()) << setfill(' ') << items[i].num;
        if (isShop) {
            cout << "\t\t" << items[i].cost << " G" << endl;
        } else {
            cout << endl;
        }
    }
    if (!isShop) {
        cout << "Press [number] to select items or [Q] to exit.\n"
             << "Press [W] to take off weapon or [A] to take off armor.\n\n";
    }
}

// Update player's state if plater use healing
// Input: string object: name of the selected items
//        int num: amount of used items
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

// find items in backpack
// if selected item already in backpack, return its index in backpack
// else return -1
int findItem(string name, vector<Item> &items) {
    for (int i = 0; i < items.size(); i++) {
        if (name == items[i].name)
            return i;
    }
    return -1;
}

// 1) input items after monster fighting / getting chest
// 2) update number of items
// 3) sort by time(old to new)
// Input: char flag: A for adding, D for delete
void updateItems(string name, int number, int cost, char flag, vector<Item> &items) {
    if (number > maxStack)    // set up max number of one item
        number = maxStack;

    if (flag == 'D')
        number = -number;

    int pos = findItem(name, items);
    if (number != 0) {
        // Build item if item is not in backpack
        if (pos == -1) {
            items.push_back({name, number, cost});
            // Update item's number if item already exists in backpack
        } else {
            items[pos].num += number;
            // limit number of player's item to 99
            if (items[pos].num > maxStack) {
                items[pos].num = maxStack;
                cout << "You cannot have more than 99 " << items[pos].name << '.';
            }
        }
    }
}

// choose items in backpack to use/sell
void openBackpack(vector<Item> &items, Player &player) {
    string choice;    // string for two digit nums
    displayBackpack(items, false);
    cin >> choice;
    while (choice != "q") {
        int pos;
        for (pos = 0; pos < maxSpace; pos++) {    // Find item's position in backpack
            if (choice == to_string(pos + 1))
                break;
        }
        if (choice == to_string(pos + 1)) {    // Select item in backpack
            // Find item if it's healing
            for (int i = 0; i < maxHealNum; i++) {
                if (items[pos].name == heals[i].name) {
                    // tell player his/her selection and the function of selected healing
                    cout << items[pos].name + " is selected.\t" + heals[i].desc << endl;
                    // require player to input how many he/she will use
                    cout << "Amount to use: ";
                    int amount;
                    cin >> amount;
                    // restrict player's input is valid (i.e. player's input < amount of items in backpack && player's input > 0)
                    while (amount > items[pos].num || amount < 0) {
                        cout << "Exceeds amount, please enter a valid number: ";
                        cin >> amount;
                    }
                    cout << "\n\n";
                    // Delete used items in backpack
                    updateItems(items[pos].name, amount, heals[i].cost, 'D', items);
                    // update player's state
                    updateState(player, items[pos].name, amount);
                    break;
                }
            }
            // Find item if it's armor
            for (int i = 0; i < maxArmorNum; i++) {
                if (items[pos].name == armors[i].name) {
                    // tell player his/her selection and the function of selected armor
                    cout << items[pos].name + " is equipped.\t" + armors[i].desc + "\n\n";
                    // Add player's old armor in backpack if player is wearing armor
                    if (player.armor != "") {
                        for (int j = 0; j < maxArmorNum; j++) {
                            if (player.armor == armors[j].name) {
                                updateItems(player.armor, 1, armors[j].cost, 'A', items);
                                break;
                            }
                        }
                    }
                    // wear new armor
                    player.armor = items[pos].name;
                    // Update player's armor defense
                    for (int i = 0; i < maxArmorNum; i++) {
                        if (player.armor == armors[i].name) {
                            player.aDefense = armors[i].defense;
                            break;
                        }
                    }
                    // Delete player's new armor in backpack
                    updateItems(player.armor, 1, armors[i].cost, 'D', items);
                    break;
                }
            }
            // Find item if it's weapon
            for (int i = 0; i < maxWeaponNum; i++) {
                // tell player his/her selection and the function of selected weapon
                if (items[pos].name == weapons[i].name) {
                    cout << items[pos].name + " is equipped.\t" + weapons[i].desc + "\n\n";
                    // Add player's old weapon in backpack if player is equipping weapon
                    if (player.weapon.name != "") {
                        for (int j = 0; j < maxWeaponNum; j++) {
                            if (player.weapon.name == weapons[i].name) {
                                updateItems(player.weapon.name, 1, weapons[i].cost, 'A', items);
                                break;
                            }
                        }
                    }
                    // wear new weapon
                    player.weapon.name = items[pos].name;
                    // Update player's weapon damage, energy loss of weapon and mp loss of weapon
                    for (int i = 0; i < maxWeaponNum; i++) {
                        if (player.weapon.name == weapons[i].name) {
                            player.weapon.damage = weapons[i].damage;
                            player.weapon.energy = weapons[i].energyLose;
                            player.weapon.mp = weapons[i].mpLose;
                            break;
                        }
                    }
                    // Delete player's new armor in backpack
                    updateItems(player.weapon.name, 1, weapons[i].cost, 'D', items);
                    break;
                }
            }
            // Disequip player's armor
        } else if (choice == "a" || choice == "A") {
            // Add player's old armor in backpack if player is disequipping armor
            if (player.armor != "Empty") {
                for (int i = 0; i < maxArmorNum; i++) {
                    if (player.armor == armors[i].name) {
                        updateItems(player.armor, 1, armors[i].cost, 'A', items);
                        break;
                    }
                }
                // empty player's armor & set player's armor defense to 0
                player.armor = "Empty";
                player.aDefense = 0;
                // Else if player doesn't have armor on hand
            } else {
                cout << "You have no armor on body.\n";
            }
            // Disequip player's weapon
        } else if (choice == "w" || choice == "W") {
            // Add player's old weapon in backpack if player is disequipping weapon
            if (player.weapon.name != "Empty") {
                for (int i = 0; i < maxWeaponNum; i++) {
                    if (player.weapon.name == weapons[i].name) {
                        updateItems(player.weapon.name, 1, weapons[i].cost, 'A', items);
                        break;
                    }
                }
                // empty player's weapon
                player.weapon = {"Empty", 2, 0, 1};
                // Else if player doesn't have weapon on hand
            } else {
                cout << "You have no weapon on hand.\n";
            }
            // if player's input is out of options, print valid options again
        } else {
            cout << "Press [number] to select items or [Q] to exit.\n"
                 << "Press [W] to take off weapon or [A] to take off armor.\n\n";
        }
        displayBackpack(items, false);
        cin >> choice;
    }
}

// Generate item in chest and update player's backpack
// Chest only generates armors and coins
void generateChestItems(vector<Item> &items, Player &player) {
    string armor = "";
    int randNum = rand() % 100, armorNum = 1;
    if (randNum <= 3) {    // 3 % to generate silver shield
        armor = "silver shield";
    } else if (randNum <= 10) {    // 7 % to generate leather shield
        armor = "leather shield";
    } else if (randNum <= 25) {    // 15 % to generate wood shield
        armor = "wood shield";
    } else if (randNum <= 75) {    // 50 % to generate boat remains
        armor = "boat remains";
        armorNum = rand() % 5;
    }
    // Search armor and update backpack
    for (int i = 0; i < maxArmorNum; i++) {
        if (armor == armors[i].name) {
            updateItems(armor, armorNum, armors[i].cost, 'A', items);
            break;
        }
    }

    int coinNum;
    // Announce player getting armor only if armor is generated
    if (armor != "") {
        cout << armor << " x 1 GET!\n";
        coinNum = rand() % 8;
    } else {
        coinNum = (1 + rand() % 16);
    }
    player.coin += coinNum;
    cout << coinNum << " G GET!\n";
}
