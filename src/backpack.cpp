#include <iostream>
#include <string>
//#include "../lib/conio/conio.h" 
#include <conio.h>
#include <iomanip>
#include "env.h"
#include "items.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

int main()
{
    int selected = 0;
    int choices = 3;
    bool selecting = true;
    bool updated = false;
    string log = "";
    // Press UP DOWN to choose

    for (int i = 0; i < maxSpace; i++){
        if (i == 0)
            cout <<  setw(map_width) << "\t\tItems\t\t\t\t\t\t\tNumber\t\t\t\n";
        if (item[i].name != "")
            cout << setw(map_width) << (i+1) << "  " << item[i].name << "\t\t\t\t\t\t" << item[i].num << '\n';
    }
    int ch, n;
    while (selecting){
            cin >> ch;
            for (int i = 0; i < maxSpace; i++){
                if (ch = i)
                    log = item[i].name + "is selected\n";
                    cout << log;
                    scanf("Amount to use: %i", &n);
                    updateItems(item[i].name, n, 'D');
            }
        }
    
}