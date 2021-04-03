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

    // Press UP DOWN to choose
    // cout << "_START_\n" << "_LOAD_\n" << "_QUIT_\n\n";

    // char c;
    // while(selecting)
    // {
    //     switch(c = getch())
    //     {   
    //         case KEY_UP:
    //             if (selected > 0){
    //                 selected--;
    //                 updated = true;
    //             }
    //             break;
    //         case KEY_DOWN:
    //             if (selected < choices - 1){
    //                 selected++;
    //                 updated = true;
    //             }
    //             break;
    //         case KEY_ENTER:
    //             selecting = false;
    //             break;
            
    //         default:
    //             break;
    //     }
    //     if (updated){
    //         if (selected <= 0)
    //             log = "Selected START";

    //         else if (selected == 1)
    //             log = "Selected LOAD";

    //         else if (selected >= 2)
    //             log = "Selected HELP";
            
    //         cout << log << "\t<Press Enter to Continue...>\n";
    //         updated = false;
    //     }
    // }

    //Press 1, 2, 3 to continue
    cout << "[1]  START\t" << "[2]  LOAD\t" << "[3]  QUIT\n";

    char c;
    while (selecting){

        switch (c = getch())
        {   
            default:
                break;
            case '1':
                log = "Selected START";
                updated = true;
                break;
            case '2':
                log = "Selected LOAD";
                updated = true;
                break;      
            case '3':
                log = "Selected QUIT";
                updated = true;
                break; 
            case KEY_ENTER:
                selecting = false;
                break;                         
        }
        
        if (updated){
            cout << log << "\t<Press Enter to Continue...>\n";
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
