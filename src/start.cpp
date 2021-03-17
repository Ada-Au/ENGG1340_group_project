//#include "player.h"
#include "start.h"
#include <stdio.h>
#include <iostream>

using namespace std;

PrintID printID;
Player player;

int main()
{
    cout << "YOU DIED. Welome to the Underworld!\n"
         << "Do you remember your name?\t";

    cin >> player.name;
    cout << endl;

    player.randomRole(player.role);
    player.randomGender(player.gender);

    cout << "Here is your indentity information\n";
    printID.PrintInform();

    char key = ' ';
    cin >> key;

    while(key == 'n')
    {
        printID.PrintChoice();

        char flag = ' ';
        cin >> flag;
        while (flag != 'y'){

            if (flag == '1'){          //input player's role
                printID.PrintRole();
                cin >> flag;
                printID.DealInput(flag, max_role);
            }

            else if (flag == '2'){          //input player's race
                printID.PrintRace();
                cin >> flag;
                printID.DealInput(flag, max_race);
            }

            else if (flag == '3'){          //input player's gender
                printID.PrintGender();
                cin >> flag;
                printID.DealInput(flag, max_gender);
            }
        }

        printID.PrintInform();
        cin >> key;
        break;
    }
    

    return 0;
}
