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
                item[j].num = 0;
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
    int n, index;
    displayBackpack(item);
    cin >> flag;
    while (flag != "q") {
        for (index = 0; index < maxSpace; index++){
            if (flag == to_string(index+1)) {
                cout << item[index].name + " is selected\n";
                break;
            }
        }
        for (int i = 0; i < maxHealNum; i++){               //To-do: update player's state
            if (item[index].name == heals[i].name){
                cout << "Amount to use: ";
                cin >> n;
                cout << '\n';
                while (n > item[i].num || n < 0) {
                    cout << "Exceeds amount, enter a valid number please: ";
                    cin >> n;
                    cout << '\n';
                }
                break;
            }
        }
        for (int i = 0; i < maxArmorNum; i++){             //Error: player's armor not update
            if (item[index].name == armors[i].name){
                n = 1;
                if (player.armor != ""){
                    old = player.armor;
                    updateItems(old, 1, 'A', item);                    
                }
                player.armor = item[index].name;
                break;
            }
        }
        for (int i = 0; i < maxWeaponNum; i++){           //Error: player's weapon not update
            if (item[index].name == weapons[i].name){
                n = 1;
                if (player.weapon != ""){
                    old = player.weapon;
                    updateItems(old, 1, 'A', item);
                }
                player.weapon = item[index].name;
                break;
            }
        }
        updateItems(item[index].name, n, 'D', item);
        displayBackpack(item);
        cout << "player's weapon: " << player.weapon << "  player's armor: " << player.weapon << endl;
        cin >> flag;
    }
}

