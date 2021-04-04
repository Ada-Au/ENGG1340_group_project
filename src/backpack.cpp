#include "backpack.h"
#include "env.h"
#include "things.h"
#include "player.h"
#include <iomanip>
#include <iostream>

using namespace std;

Item item[maxSpace] = {"", 0};

void displayBackpack(){
    for (int i = 0; i < maxSpace; i++) {
        if (i == 0)
            cout << "Items\t\t\t\t\t\tNumber\n";
        if (item[i].name != "")
            cout << (i + 1) << "  " << item[i].name << setw(48 - item[i].name.length()) << item[i].num << '\n';
    }
    cout << "Press number to select items or q to exist\n";
}

int findItem(string name) {
    for (int i = 0; i < maxSpace; i++) {
        if (name == item[i].name)
            return i;
    }
    return -1;
}

//To-do:
// 1) input items after monster fighting / getting things on ground
// 2) update number of items
// 3) sort by time(old to new)
void updateItems(string name, int number, char flag)    // flag - A for adding, D for delet
{
    if (number > maxNum)
        number = maxNum;

    if (flag == 'D')
        number = -number;

    if (findItem(name) == -1) {
        for (int i = 0; i < maxSpace; i++) {
            if (item[i].name == "") {
                item[i].name = name;
                item[i].num += number;
                break;
            }
        }
    } else {
        item[findItem(name)].num += number;
        if (item[findItem(name)].num > maxNum)
            item[findItem(name)].num = maxNum;
    }

    // for (int i = 0; i < maxSpace; i++)
    //     if (item[i].name != "")
    //         cout << "Name: " << item[i].name << " Number: " << item[i].num << '\n';
}

void openBackpack() {
    string flag;
    int n;
    displayBackpack();
    cin >> flag;
    while (flag != "q") {
        for (int i = 0; i < maxSpace; i++) {
            if (flag == to_string(i+1)) {
                cout << item[i].name + "is selected\n";
                for (int i = 0; i < healNum; i++){
                    if (heals[i].name == item[i].name){         // To-do: update state of player
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
                for (int i = 0; i < armorNum; i++)              // To do: also exchanges weapon and armor
                    if (armors[i].name == item[i].name){
                        n = 1;
                        break;
                    }
                        
                for (int i = 0; i < weaponNum; i++)
                    if (weapons[i].name == item[i].name){
                        n = 1;
                        break;
                    }
                updateItems(item[i].name, n, 'D');
                break;
            }
        }
        displayBackpack();
        cin >> flag;
    }
}

