#include "backpack.h"
#include "env.h"
#include <iomanip>
#include <iostream>

using namespace std;

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
// 3) sort by time(old to new)
void updateItems(string name, int number, char flag, Item item[])    // flag - A for adding, D for delet
{
    if (number > maxNum)
        number = maxNum;

    if (flag == 'D')
        number = -number;

    if (findItem(name, item) == -1) {
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

    for (int i = 0; i < maxSpace; i++)
        if (item[i].name != "")
            cout << "Name: " << item[i].name << " Number: " << item[i].num << '\n';
}

void openBackpack(Item item[]) {
    string log = "";
    for (int i = 0; i < maxSpace; i++) {
        if (i == 0)
            cout << setw(map_width) << "\t\tItems\t\t\t\t\t\t\tNumber\t\t\t\n";
        if (item[i].name != "")
            cout << setw(map_width) << (i + 1) << "  " << item[i].name << "\t\t\t\t\t\t" << item[i].num << '\n';
    }

    string flag;
    int n;
    cout << "Press number to select items or q to exist\n";

    cin >> flag;
    while (flag != "q") {
        for (int i = 0; i < maxSpace; i++) {
            if (flag == to_string(i)) {
                log = item[i].name + "is selected\n";
                cout << log;
                scanf("Amount to use: %i", &n);
                while (n > item[i].num || n < 0) {
                    scanf("Exceeds amount, enter a valid number please: %i", &n);
                }
                updateItems(item[i].name, n, 'D', item);
                break;
            }
        }
        cin >> flag;
    }
}
