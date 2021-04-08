#include "backpack.h"
#include "player.h"
#include "things.h"
#include <iomanip>
#include <iostream>

using namespace std;

void sortItems(Item item[]) {
    string tempName;
    int tempNum;
    for (int i = 0; i < maxSpace - 1; i++) {
        for (int j = 0; j < maxSpace - i - 1; j++) {
            if (item[j].num <= 0) {
                item[j].num = 0;
                tempName = item[j].name;
                tempNum = item[j].num;
                item[j].name = item[j + 1].name;
                item[j].num = item[j + 1].num;
                item[j + 1].name = tempName;
                item[j + 1].num = tempNum;
            }
        }
    }
}

void displayBackpack(Item item[]) {    //Also display player's state if possible
    sortItems(item);
    for (int i = 0; i < maxSpace; i++) {
        if (i == 0)
            cout << "Items\t\t\t\t\t\tNumber\n";
        if (item[i].name != "" && item[i].num > 0)
            cout << (i + 1) << "  " << item[i].name << setw(48 - item[i].name.length()) << setfill(' ') << item[i].num << '\n';
    }
    cout << "Press [number] to select items or [Q] to exist.\n"
         << "Press [W] to take off weapon or [A] to take off armor.\n\n";
}

int findItem(string name, Item item[]) {
    for (int i = 0; i < maxSpace; i++) {
        if (name == item[i].name)
            return i;
    }
    return -1;
}

void exchangeArmor(Player &player) {
    if (player.armor == "") {
        player.defense = 0;
    } else {
        for (int i = 0; i < maxArmorNum; i++) {
            if (player.armor == armors[i].name) {
                player.defense = armors[i].defenseValue;
                break;
            }
        }
    }
}

void exchangeWeapon(Player &player, string old) {
    if (player.weapon == "") {
        player.weaponEnergy = 1;
        player.damage = 1 + player.level;
    }
    float oldDamage = 1;
    if (old != player.weapon) {
        for (int i = 0; i < maxWeaponNum; i++) {
            if (old == weapons[i].name) {
                oldDamage = weapons[i].damage;
                break;
            }
        }
        for (int i = 0; i < maxWeaponNum; i++) {
            if (player.weapon == weapons[i].name) {
                player.damage /= oldDamage;
                player.damage *= weapons[i].damage;
                player.weaponEnergy = weapons[i].energyLose;
                player.weaponMp = weapons[i].mpLose;
                break;
            }
        }
    }
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
void updateItems(string name, int number, char flag, Item item[])    // flag - A for adding, D for delete
{
    if (number > maxNum)
        number = maxNum;

    if (flag == 'D')
        number = -number;

    if (findItem(name, item) == -1 && number != 0) {
        for (int i = 0; i < maxSpace; i++) {
            if (item[i].name == "") {
                item[i].name = name;
                item[i].num += number;
                break;
            }
        }
    } else {
        item[findItem(name, item)].num += number;
        if (item[findItem(name, item)].num > maxNum)
            item[findItem(name, item)].num = maxNum;
    }
}

void openBackpack(Item item[], Player &player) {
    string flag;
    string old;
    int n, index;
    displayBackpack(item);
    cin >> flag;
    while (flag != "q") {
        for (index = 0; index < maxSpace; index++) {    //Find index
            if (flag == to_string(index + 1))
                break;
        }
        if (flag == to_string(index + 1)) {
            for (int i = 0; i < maxHealNum; i++) {
                if (item[index].name == heals[i].name) {
                    cout << item[index].name + " is selected.\n";
                    cout << "Amount to use: ";
                    cin >> n;
                    while (n > item[index].num || n < 0) {
                        cout << "Exceeds amount, enter a valid number please: ";
                        cin >> n;
                    }
                    cout << "\n\n";
                    updateState(player, item[index].name, n);
                    break;
                }
            }
            for (int i = 0; i < maxArmorNum; i++) {
                if (item[index].name == armors[i].name) {
                    cout << item[index].name + " is equipped.\n\n";
                    n = 1;
                    if (player.armor != "") {
                        old = player.armor;
                        updateItems(old, 1, 'A', item);
                    }
                    player.armor = item[index].name;
                    exchangeArmor(player);
                    break;
                }
            }
            for (int i = 0; i < maxWeaponNum; i++) {
                if (item[index].name == weapons[i].name) {
                    cout << item[index].name + " is equipped.\n\n";
                    n = 1;
                    if (player.weapon != "") {
                        old = player.weapon;
                        updateItems(old, 1, 'A', item);
                    }
                    player.weapon = item[index].name;
                    exchangeWeapon(player, old);
                    break;
                }
            }
            updateItems(item[index].name, n, 'D', item);
        } else if (flag == "a" || flag == "A") {
            if (player.armor != "") {
                updateItems(player.armor, 1, 'A', item);
            } else {
                cout << "You have no armor on body.\n"
                     << "Press [number] to select or [Q] to quit.  ";
                cin >> flag;
            }
            player.armor = "";
            exchangeArmor(player);
        } else if (flag == "w" || flag == "W") {
            if (player.weapon != "") {
                updateItems(player.weapon, 1, 'A', item);
            } else {
                cout << "You have no weapon on hand.\n"
                     << "Press [number] to select or [Q] to quit.  ";
                cin >> flag;
            }
            player.weapon = "";
            exchangeWeapon(player, player.weapon);
        } else {
            cout << "Press [number] to select items or [Q] to exist.\n"
                 << "Press [W] to take off weapon or [A] to take off armor.\n\n";
            cin >> flag;
        }
        displayBackpack(item);
        cin >> flag;
    }
}
