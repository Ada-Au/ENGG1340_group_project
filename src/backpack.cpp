#include "backpack.h"
#include "env.h"
#include "things.h"
#include "player.h"
#include <iomanip>
#include <iostream>

using namespace std;

void sortItems(Item item[])
{
    string tempName;
    int tempNum;
    for (int i = 0; i < maxSpace - 1; i++){
        for (int j = 0; j < maxSpace - i - 1; j++){
            if (item[j].num <= 0){
                tempName = item[j].name;
                tempNum = item[j].num;
                item[j].name = item[j+1].name;
                item[j].num = item[j+1].num;
                item[j+1].name = tempName;
                item[j+1].num = tempNum;
            }
        }
    }
}

void displayBackpack(Item item[]){
    sortItems(item);
    for (int i = 0; i < maxSpace; i++){
        if (i == 0)
            cout << "Items\t\t\t\t\t\tNumber\n";
        if (item[i].name != "" && item[i].num > 0)
            cout << (i + 1) << "  " << item[i].name << setw(48 - item[i].name.length()) << setfill(' ') << item[i].num << '\n';
    }
    cout << "Press number to select items or q to exist\n";
}

int findItem(string name, Item item[]) {
    for (int i = 0; i < maxSpace; i++) {
        if (name == item[i].name)
            return i;
    }
    return -1;
}

//To-do:
// 1) input items after monster fighting / getting things on ground
// 2) update number of items
// 3) !!!sort by time(old to new)/ alphabetical order
void updateItems(string name, int number, char flag, Item item[])    // flag - A for adding, D for delet
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
    }else {
        item[findItem(name, item)].num += number;
        if (item[findItem(name, item)].num > maxNum)
            item[findItem(name, item)].num = maxNum;
    }
}

void openBackpack(Item item[], Player &player) {
    string flag;
    string old;
    int n;
    displayBackpack(item);
    cin >> flag;
    while (flag != "q") {
        for (int i = 0; i < maxSpace; i++) {
            if (flag == to_string(i+1)) {
                cout << item[i].name + " is selected\n";
                cout << "Amount to use: ";
                cin >> n;
                cout << '\n';
                while (n > item[i].num || n < 0) {
                    cout << "Exceeds amount, enter a valid number please: ";
                    cin >> n;
                    cout << '\n';
                }
                // for (int i = 0; i < maxHealNum; i++){
                //     if (heals[i].name == item[i].name){         // To-do: update state of player
                //         cout << "Amount to use: ";
                //         cin >> n;
                //         cout << '\n';
                //         while (n > item[i].num || n < 0) {
                //             cout << "Exceeds amount, enter a valid number please: ";
                //             cin >> n;
                //             cout << '\n';
                //         }
                //         break;                      
                //     }
                // }
                // for (int i = 0; i < maxArmorNum; i++){            // To do: also exchanges weapon and armor
                //     if (armors[i].name == item[i].name){
                //         n = 1;
                //         old = player.armor;
                //         player.armor = item[i].name;
                //         updateItems(old, 1, 'A', item);
                //         break;
                //     }                        
                // }             
                // for (int i = 0; i <maxWeaponNum; i++){
                //     if (weapons[i].name == item[i].name){
                //         n = 1;
                //         old = player.weapon;
                //         player.weapon = item[i].name;
                //         updateItems(old, 1, 'A', item);
                //         break;
                //     }                    
                //}
                updateItems(item[i].name, n, 'D', item);
                break;
            }
        }
        displayBackpack(item);
        cout << "player's weapon: " << player.weapon << "  player's armor: " << player.weapon << endl;
        cin >> flag;
    }
}

