#include "env.h"
#include "backpack.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
// #else
// #include "../lib/conio/conio.h"

#define KEY_ESC 27

using namespace std;

int findItem(string Name, items item[maxSpace])
{
    for (int i = 0; i < maxSpace; i++){
        if (Name == item[i].name)
            return i;
    }
    return -1;
}

//To-do:
// 1) input items after monster fighting / getting things on ground
// 2) update number of items
// 3) sort by time(old to new)
void updateItems(string Name, int N, char flag) // flag - A for adding, D for delet
{
    if (N > maxNum)
        N =  maxNum;

    if (flag = 'D')
        N = -N;

    if (findItem(Name, item) == -1){
        for (int i = 0; i < maxSpace; i++){
            if (item[i].name == ""){
                item[i].name = Name;
                item[i].num += N;
                break;                 
            }
        }    
    }
    else{
        item[findItem(Name, item)].num += N;
        if (item[findItem(Name, item)].num > maxNum)
            item[findItem(Name, item)].num = maxNum;
    }        
    
    for (int i = 0; i < maxSpace; i++)
        if (item[i].name != "")
            cout << "Name: " << item[i].name << " Number: " << item[i].num << '\n';
}

void backpack( items item[] )
{
    string log = "";
    for (int i = 0; i < maxSpace; i++){
        if (i == 0)
            cout << setw(map_width) << "\t\tItems\t\t\t\t\t\t\tNumber\t\t\t\n";
        if (item[i].name != "")
            cout << setw(map_width) << ( i + 1 ) << "  " << item[i].name << "\t\t\t\t\t\t" << item[i].num << '\n';
    }
    
    string flag;
    int n;
    cout << "Press number to select items or q to exist\n";
    
    cin >> flag;
    while (flag != "q"){
        for (int i = 0; i < maxSpace; i++){
            if (flag == to_string(i)){
                log = item[i].name + "is selected\n";
                cout << log;
                scanf("Amount to use: %i", &n);
                while(n > item[i].num || n < 0){
                    scanf("Exceeds amount, enter a valid number please: %i", &n);
                }
                updateItems(item[i].name, n, 'D');
                break;
            }
        }
        cin >> flag;
    }   
    
}
