#include "shop.h"
#include "npc.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

ShopItem shopItems[20] = {};

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0)
            return false;
    }
    return true;
}

void generateShopItems(Player player, ShopItem shopItems[]) {
    srand(player.gameLevel);
    int healNum, weaponNum, armorNum;
    int index = 0;
    while (index < 12) {
        //items that only sold in shop
        if (rand() % 100 >= 90) {    
            if (rand() % 7 == 0) {
                shopItems[index] = {"vorpan", "(+10 ATK, -10 Energy/atk)",  1, 3819};
            } else if (rand () % 7 == 1) {
                shopItems[index] = {"soul sword","(+20 ATK, -8 Energy/atk, -8 MP/atk)", 1, 6666};
            } else if (rand() % 7 == 2) {
                shopItems[index] = {"twin daggers","(+14 Atk, -12 Energy/atk)", 1, 4242};
            } else if (rand() % 7 == 3) {
                shopItems[index] = {"war spear", "(+12 Atk, -7 Energy/atk)", 1, 3647};
            } else if (rand() % 7 == 4) {
                shopItems[index] = {"blood katana", "(+18 Atk, -20 Energy/atk)", 1, 4536};
            } else if (rand() % 7 == 5){
                shopItems[index] = {"toothpick", "(+15 Atk, -25 Energy/atk)", 1,  3840};
            } else if (rand() % 7 == 6) {
                shopItems[index] = {"diamond sword", "(Best weapon you can have!)", 1,  9999999};
            }
            index++;    
        } else if (rand() % 100 >= 75) {
            if (rand() % 2 == 0) {
                shopItems[index] = {"diamond shield", "(Best armor you can have!)" ,1, 999999};
            } else {
                shopItems[index] = {"golden shield", "(+20 DFS)", 1, 1980};
            }
            index++;    
        } else if (rand() % 100 >= 50) {    //generate healings that only sold in shop
            if (rand() % 2 == 0) {
                shopItems[index] = {"high healing","(+100 HP)", (1 + rand() % 3), 420};
            } else {
                shopItems[index] = {"medium healing", "(+75 HP)", (1 + rand() % 4), 288};
            }
            index++;     
        }
        //generate healings
        if (rand() % 100 <= 90) {
            shopItems[index] = {"monster meat", "(Are you sure to eat that?)", (1 + rand() % 20), 12};
            index++;
        } 
        if (rand() % 100 <= 50) {
            shopItems[index] = {"bread", "(You're \"toast\".)", (1 + rand() % 10), 30};
            index++;
        }  
        if (rand() % 100 >= 25) {
            shopItems[index] = {"poor healing", "(+10 HP)", (1 + rand() % 20), 65};
            index++;
        }  
        if (rand() % 100 >= 50) {
            shopItems[index] = {"average healing", "(+20 HP)", (1 + rand() % 15), 90};
            index++;
        }  
        if (rand() % 100 >= 75) {
            shopItems[index] = {"decent healing", "(+50 HP)", (1 + rand() % 10), 145};
            index++;
        } 
        //generate armors
        if (rand() % 50 <= 45) {
            shopItems[index] = {"boat remains", "(...)", (1 + rand()%50), 15};
            index++;
        }
        if (rand() % 50 <= 30) {
            shopItems[index] = {"wood shield", "(+5 DFS)", 1, 150};
            index++;
        } else if (rand() % 50 <= 25) {
            shopItems[index] = {"leather shield", "(+10 DFS)", 1, 550};
            index++;
        } else if (rand() % 50 <= 10) {
            shopItems[index] = {"silver shield", "(+15 DFS)", 1, 900};
            index++;
        }
        //generate weapons
        if (rand() % 25 >= 22) {
            shopItems[index] = {"hammer", "(+10 ATK, -30 Energy/atk)", 1, 592};
            index ++;
        } else if (rand() % 25 >= 20) {
            shopItems[index] = {"great sword", "(+8 ATK, -15 Energy/atk)", 1, 290};
            index ++;
        } else if (rand() % 25 >= 12) {
            shopItems[index] = {"long sword", "(+4.5 ATK, -5 Energy/atk)", 1, 204};
            index ++;
        }
        if (rand() % 25 <= 20) {
            shopItems[index] = {"sword", "(+2 ATK, -0.5 Energy/atk)", 1, 169};
            index ++;
        } else if (rand() % 25 <= 12) {
            shopItems[index] = {"wand", "(+8 ATK, -15 MP/atk)", 1, 474};
            index ++;
        } else {
            shopItems[index] = {"spear", "(+6 ATK, -10 Energy/atk)", 1, 200};
            index ++;
        }        
    }
}

void displayShopItems (ShopItem shopItems[]) {
    cout << "Items\t\t\t\tDescription\t\t\t\tNumber\t\tPrice" << endl;
    for (int i = 0; i < 12; i++) {
        cout << (i + 1) << "  " << shopItems[i].name 
             << setw(30 - shopItems[i].name.length()- to_string(i + 1).length() + shopItems[i].desc.length())
             << shopItems[i].desc << setw(44 - shopItems[i].desc.length() ) << shopItems[i].amount << "\t\t" << shopItems[i].price << " G"<< endl;
    }
}

void shopScreen(Player player, Item items[]) {
    char key;
    renderNpc("charon", "Welcome, have a look.");
    cout << "ACTION (please input number 1-4)" << endl
         << "1 - Sell                    2 - Buy " << endl
         << "3 - Talk                    4 - Exit" << endl;
    cin >> key;
    while (key != '4'){
        string choice;  // string for two digit nums
        int pos;
        int amount;
        switch(key) {
        case '1':
            renderNpc("charon", "What do you wanna sell?");
            displayBackpack(items, true);
            cout << "You have " << player.coin << " G.";
            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl;
            while (!isNumber(choice)) {     // To-do: check whether choice is a number with items pos
                cout << "No such item, please select again: ";
                cin >> choice;
            }
            for (pos = 0; pos < maxSpace; pos++) {
                if (choice == to_string(pos + 1)) {
                    cout << "Amount to sell: ";
                    cin >> amount;
                    while (amount > items[pos].num || amount < 0 ) { //To-do: repeat if amount is char/ string
                        cout << "Exceeds amount, please enter a valid number: ";
                        cin >> amount ;
                    } 
                    updateItems(items[pos].name, amount, items[pos].cost, 'D', items); 
                    player.coin += items[pos].cost * amount;
                    cout << "You gain " << items[pos].cost * amount << " G.\n\n";         
                    break;
                }
            } 
            break;
        case '2':
            cout << "generating..." << endl;
            generateShopItems(player, shopItems);
            cout << "shop" << endl;
            displayShopItems(shopItems);
            renderNpc("charon", "What do you wanna buy?");
            cout << "Enter your choice: ";
            cin >> choice;
            break;
        case '3':
            break;
        default:
            renderNpc("charon", "What do you say?");
            cout << "Enter again: ";
            cin >> key;
            break;
        } 
        renderNpc("charon", "Do you else have things to do?");
        cout << "ACTION (please input number 1-4)" << endl
         << "1 - Sell                    2 - Buy " << endl
         << "3 - Talk                    4 - Exit" << endl;       
        cin >> key;
    }

}