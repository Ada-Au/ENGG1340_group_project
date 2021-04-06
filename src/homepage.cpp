#include <iostream>
#include <string>
#if defined _WIN32 || defined _WIN64
#include <conio.h>
#else
#include "../lib/conio/conio.h"
#endif

#include "homepage.h"
#include "env.h"

#define KEY_ENTER '\r'

using namespace std;

Homepage homepage;

void home()
{
    int selected = 0;
    int choices = 3;
    bool selecting = true;
    bool updated = false;
    string log = "";

    //To-do: Press any key to continue
    //       add reminder: plz play this game with full screen
    for(int i = 0; i < 10; i++)
        cout << homepage.homepage[i] << "\n";

    //Press 1, 2, 3 to continue
    cout << "[1]  START\t" << "[2]  LOAD\t" << "[3]  QUIT\n";

    char c;
    while (selecting){

        switch (c = getch())
        {   
            default:
                break;
            case '1':
                log = "\nSelected START";  //start a new game
                updated = true;
                break;
            case '2':
                log = "\nSelected LOAD";  // input files
                updated = true;
                break;      
            case '3':
                log = "\nSelected QUIT";
                updated = true;
                break; 
            case KEY_ENTER:
                selecting = false;
                break;                         
        }
        
        if (updated){
            cout << log << "\t<Press Enter to Continue...>";
            c = getch();
            if (c == KEY_ENTER){
                selecting = false;
                break;                
            }
            else
                updated = false;             
        }
    }
}
