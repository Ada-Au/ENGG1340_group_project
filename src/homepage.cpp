#include <windows.h>
#include <iostream>
#include <string>
//#include "../lib/conio/conio.h" 
#include <conio.h>

#include "homepage.h"
#include "env.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

using namespace std;

Homepage homepage;

int main()
{
    int selected = 0;
    int choices = 3;
    bool selecting = true;
    bool updated = false;

    //To-do: Press any key to continue
    //       add reminder: plz play this game with full screen
    for(int i = 0; i < 10; i++)
        cout << homepage.homepage[i] << "\n";

    cout << "START\n" << "LOAD\n" << "HELP\n";

    char c;

    while(selecting)
    {
        switch(c = getch())
        {   
            default: break;
            case KEY_UP:
                if (selected > 0){
                    selected--;
                    updated = true;
                }
                break;
            case KEY_DOWN:
                if (selected < choices - 1){
                    selected++;
                    updated = true;
                }
                break;
            case KEY_ENTER:
                selecting = false;
                break;
        }
        if (updated){
            if (selected == 0)
                cout << "Selected START\n";

            else if (selected == 1)
                cout << "Selected LOAD\n";

            else if (selected == 2)
                cout << "Selected HELP\n";
            updated = false; 
        }
    }
    return 0;
}
