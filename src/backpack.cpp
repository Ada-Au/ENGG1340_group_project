#include <iostream>
#include <string>
//#include "../lib/conio/conio.h" 
#include <conio.h>
#include <iomanip>
#include "env.h"
#include "items.h"

using namespace std;

#define KEY_ESC 27

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