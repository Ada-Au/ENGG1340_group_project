#include "shop.h"
#include "npc.h"
#include <iomanip>
#include <iostream>
#include <thread>
#include <time.h>
#include <vector>

using namespace std;

vector<ShopItem> shopItems;    // vector to store shop items, which is only needed in shop.cpp

// check whether player's input is number
bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0)
            return false;
    }
    return true;
}

// check whether player's choice is inside backpack
bool isWithinBackpack(vector<Item> &items, string choice) {
    for (int i = 0; i < items.size(); i++) {
        if (choice == to_string(i + 1))
            return true;
    }
    return false;
}

// check whether player's choice is inside shop
bool isWithinShop(vector<ShopItem> shopItems, string choice) {
    // As choice is printed out as the index of shop items + 1
    for (int i = 0; i < shopItems.size(); i++)
        // if choice matches index of shop items + 1
        if (choice == to_string(i + 1))
            return true;
    return false;
}

// avoid redundancy of generation of shop items
void sortShopItems(vector<ShopItem> &shopItems) {
    for (int i = 0; i < shopItems.size() - 1; i++)    // selection sorting
        for (int j = i + 1; j < shopItems.size(); j++)
            if (shopItems[i].name == shopItems[j].name)    // if shop items are same
                shopItems.erase(shopItems.begin() + j);    // erase redundant shop item
}

// generate shop items
void generateShopItems(Player player, vector<ShopItem> &shopItems) {
    srand(player.gameLevel + time(NULL));
    // shop items will be generated until there are 12 items in vector<ShopItem> shopItems
    while (shopItems.size() < 12) {
        // generate one item that only sold in shop
        // (10 - player.level)% for generation of one weapon
        // (10 - player.level)% as player can have larger chance to get better items
        if (rand() % 100 > 90 - player.level) {
            // each weapon got same percent to be generated
            if (rand() % 7 == 0) {
                shopItems.push_back({"vorpan", "(+10 ATK, -10 Energy/atk)", 1, 202, 3819});
            } else if (rand() % 7 == 1) {
                shopItems.push_back({"soul sword", "(+20 ATK, -8 Energy/atk, -8 MP/atk)", 1, 166, 6666});
            } else if (rand() % 7 == 2) {
                shopItems.push_back({"twin daggers", "(+14 Atk, -12 Energy/atk)", 1, 110, 4242});
            } else if (rand() % 7 == 3) {
                shopItems.push_back({"war spear", "(+12 Atk, -7 Energy/atk)", 1, 97, 3647});
            } else if (rand() % 7 == 4) {
                shopItems.push_back({"blood katana", "(+18 Atk, -20 Energy/atk)", 1, 105, 4536});
            } else if (rand() % 7 == 5) {
                shopItems.push_back({"toothpick", "(+15 Atk, -25 Energy/atk)", 1, 100, 3840});
            } else if (rand() % 7 == 6) {
                shopItems.push_back({"diamond sword", "(Best weapon you can have!)", 1, 4999, 99999});
            }
            // (25 - player.level)% for the generation of one armor
        } else if (rand() % 100 > 75 - player.level) {
            if (rand() % 2 == 0) {
                shopItems.push_back({"diamond shield", "(Best armor you can have!)", 1, 2999, 9999});
            } else {
                shopItems.push_back({"golden shield", "(+20 DFS)", 1, 180, 1980});
            }
            // (25 - player.level)% for the generation of one healing
        } else if (rand() % 100 > 50 - player.level) {
            if (rand() % 2 == 0) {
                shopItems.push_back({"high healing", "(+100 HP)", (1 + rand() % 3), 125, 420});
            } else {
                shopItems.push_back({"medium healing", "(+75 HP)", (1 + rand() % 4), 90, 288});
            }
        }
        //generate healings
        if (rand() % 100 <= 90) {    // 90 % to generate monster meat
            shopItems.push_back({"monster meat", "(Are you sure to eat that?)", (1 + rand() % 20), 5, 12});
        }
        if (rand() % 100 <= 50) {    // 50 % to generate bread
            shopItems.push_back({"bread", "(You're \"toast\".)", (1 + rand() % 10), 12, 30});
        }
        if (rand() % 100 >= 25) {    // 75 % to genrate poor healing
            shopItems.push_back({"poor healing", "(+10 HP)", (1 + rand() % 20), 25, 65});
        }
        if (rand() % 100 >= 50) {    // 50 % to generate average healing
            shopItems.push_back({"average healing", "(+20 HP)", (1 + rand() % 15), 37, 90});
        }
        if (rand() % 100 >= 75) {    // 25 % to generate decent healing
            shopItems.push_back({"decent healing", "(+50 HP)", (1 + rand() % 10), 60, 145});
        }
        //generate armors
        if (rand() % 50 <= 45) {    // 90 % to generate boat remains
            shopItems.push_back({"boat remains", "(...)", (1 + rand() % 50), 2, 15});
        }
        // only generate one type of shield
        if (rand() % 50 <= 10) {    //  20 % to generate silver shield
            shopItems.push_back({"silver shield", "(+15 DFS)", 1, 150, 900});
        } else if (rand() % 50 <= 25) {    // 30 % to generate leather shield
            shopItems.push_back({"leather shield", "(+10 DFS)", 1, 100, 550});
        } else {    // 50 % to generate wood shield
            shopItems.push_back({"wood shield", "(+5 DFS)", 1, 25, 150});
        }
        //generate weapon: hammer, great sword, long sword
        if (rand() % 25 >= 22) {    // 12 % to generate hammer
            shopItems.push_back({"hammer", "(+10 ATK, -30 Energy/atk)", 1, 92, 592});
        } else if (rand() % 25 >= 20) {    // 28 % to generate great sword
            shopItems.push_back({"great sword", "(+8 ATK, -15 Energy/atk)", 1, 45, 290});
        } else if (rand() % 25 >= 12) {    // 24 % to generate long sword
            shopItems.push_back({"long sword", "(+4.5 ATK, -5 Energy/atk)", 1, 37, 204});
        }
        // generate weapon: sword, wand, spear
        if (rand() % 25 >= 15) {    // 40 % to generate sword
            shopItems.push_back({"sword", "(+2 ATK, -0.5 Energy/atk)", 1, 12, 169});
        } else if (rand() % 25 >= 10) {    // 20 %  to generate wand
            shopItems.push_back({"wand", "(+8 ATK, -15 MP/atk)", 1, 100, 474});
        } else {    // 20 % to generate spear
            shopItems.push_back({"spear", "(+6 ATK, -10 Energy/atk)", 1, 30, 200});
        }
    }
    // erase redundant items
    sortShopItems(shopItems);
}

// display shop items
void displayShopItems(vector<ShopItem> shopItems) {
    cout << "Items\t\t\t\tDescription\t\t\t\tNumber\t\tPrice" << endl;
    for (int i = 0; i < shopItems.size(); i++) {
        cout << (i + 1) << "  " << shopItems[i].name << setfill(' ')
             << setw(30 - shopItems[i].name.length() - to_string(i + 1).length() + shopItems[i].desc.length())
             << shopItems[i].desc << setw(44 - shopItems[i].desc.length()) << shopItems[i].amount << "\t\t" << shopItems[i].price << " G" << endl;
    }
}

// read player's input again if player enters invalid input in talk screen
// Input: string str: Charon's log
//        bool isTalking: determine whether talk screen ends
//        int c: switch string choice to int in order to prevent errors (e.g. unallocated space of char array/ not enough space for storing char )
//        bool isFirst: check whether player first meet Charon in shop
void talkAgain(string str, bool &isTalking, int &c, bool isFirst) {
    string choice = " ";    // player's choice
    // restrict player's choice within '1', '2', '3', '4' and '5'
    while ((choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5') || choice[1] != '\0') {
        renderNpc("Charon", str);
        cout << "1 - Say Hello";
        if (!isFirst) {
            cout << " (again)";
        }
        cout << "\n"
             << "2 - What to do here?\n"
             << "3 - Why are you here?\n"
             << "4 - Life advice(?)\n"
             << "5 - (Nothing to ask)\n";
        cout << "Enter choice: ";
        cin >> choice;
    }
    switch (choice[0]) {
    case '1':
        c = 1;
        break;
    case '2':
        c = 2;
        break;
    case '3':
        c = 3;
        break;
    case '4':
        c = 4;
        break;
    case '5':
        c = 5;
        isTalking = false;
        break;
    }
}

// deal player's input in shop screen
// if player doesn't enter valid option, system requires player to enter again
void tryAgainInShop(string &key) {
    key = "";
    while (key[0] != '1' && key[0] != '2' && key[0] != '3' && key[0] != '4' || key[1] != '\0') {
        renderNpc("Charon", "Welcome, have a look.");
        cout << "ACTION (please input number 1-4)" << endl
             << "1 - Sell                    2 - Buy " << endl
             << "3 - Talk                    4 - Exit" << endl;
        cin >> key;
        cout << endl;
    }
}

// display shop screen and deal with player's input in choosing actions
void shopScreen(Player &player, vector<Item> &items) {
    shopItems.clear();      // clear vector<shopItems> shopItems for each time opening shop
    string key = "";        // string for player's choice in action
    bool bought = false;    // determine whether player buys items
    tryAgainInShop(key);
    // while player doesn't choose quit
    while (key != "4") {
        string choice;    // string for two digit nums that players has to select items
        int pos;          // int for postion of items in backpack/shop
        int amount;       // int for amount that player buys or sells
        switch (key[0]) {
        case '1':    // sell
            renderNpc("Charon", "Sell something?");
            displayBackpack(items, true);
            cout << "You have " << player.coin << " G." << endl;
            cout << "Press [number] to sell or [Q] to quit.\n"
                 << "Enter your choice: ";
            cin >> choice;
            if (choice == "q" || choice == "Q") {    // 'q'/'Q' to quit current screen
                renderNpc("Charon", "Just looking? :-(");
                break;
            }
            // restrict player only enter integer index of items within backpack
            while (!isNumber(choice) || !isWithinBackpack(items, choice)) {
                cout << "No such item, please select again: ";
                cin >> choice;
                if (choice == "q" || choice == "Q") {
                    renderNpc("Charon", "Just looking? :-(");
                    break;
                }
            }
            for (pos = 0; pos < items.size(); pos++) {
                // find player's choice in backpack
                if (choice == to_string(pos + 1)) {
                    cout << "Amount to sell: ";
                    cin >> amount;
                    // restrict player's input within the amount of item he/she has
                    while (amount > items[pos].num || amount < 0) {
                        cout << "Exceeds amount, please enter a valid number: ";
                        cin >> amount;
                    }
                    updateItems(items[pos].name, amount, items[pos].cost, 'D', items);
                    player.coin += items[pos].cost * amount;    // update player's coin number
                    cout << "You gain " << items[pos].cost * amount << " G.\n\n";
                    break;
                }
            }
            break;
        case '2':    //buy
            // generate vector needs time, so a line to notice player to wait
            if (shopItems.empty())
                cout << "searching for shop items... " << endl;
            // create shop items until the amount of shop items reaches 12
            while (shopItems.size() < 12)
                generateShopItems(player, shopItems);
            displayShopItems(shopItems);
            cout << "You have " << player.coin << " G." << endl;
            renderNpc("Charon", "What do you wanna buy?");
            cout << "Press [number] to buy or [Q] to quit.\n"
                 << "Enter your choice: ";
            cin >> choice;
            if (choice == "q" || choice == "Q") {
                renderNpc("Charon", "Just looking? :(");
                break;
            }
            // restrict player only enter integer index of items within shop
            while (!isNumber(choice) || !isWithinShop(shopItems, choice)) {
                cout << "No such item, please select again: ";
                cin >> choice;
                if (choice == "q" || choice == "Q") {
                    renderNpc("Charon", "Just looking? :-(");
                    break;
                }
            }
            for (pos = 0; pos < shopItems.size(); pos++) {
                // find player's choice in shop
                if (choice == to_string(pos + 1)) {
                    // if player's coin number is less than price of that choice
                    if (player.coin < shopItems[pos].price) {
                        renderNpc("Charon", "That's not enough money.");
                        renderNpc("Charon", "YOU CAN'T EVEN BUY ONE!!");
                        break;
                    }
                    cout << "Amount to buy: ";
                    cin >> amount;
                    // if amount exceeds amount of shop items, require player to input a valid number again
                    while (amount > shopItems[pos].amount || amount < 0) {
                        renderNpc("Charon", "I have not that much.");
                        cout << "Amount to buy: ";
                        cin >> amount;
                    }

                    // check amount of player's selected item
                    for (int i = 0; i < items.size(); i++) {
                        if (items[i].name == shopItems[pos].name) {
                            // if total amount of selected item is larger than 99
                            if ((items[i].num + amount) > maxStack)
                                renderNpc("Charon", "You're carrying too much.");
                            // demand player to enter valide number (i.e. total amount of player's selected item <= 99)
                            while (items[i].num + amount > maxStack) {
                                cout << "(Remaining space for " << items[i].name << " = " << (99 - items[i].num) << ')' << endl;
                                cout << "Amount to buy: ";
                                cin >> amount;
                            }
                            break;
                        }
                    }
                    if (amount == 0) {
                        renderNpc("Charon", "Just looking? :(");
                        break;
                    }
                    // check whether player gets enough money to buy items
                    // if yes, update player's status
                    // else, Charon tell player he/she doesn't have enough money
                    if (player.coin >= (shopItems[pos].price * amount)) {
                        updateItems(shopItems[pos].name, amount, shopItems[pos].cost, 'A', items);
                        bought = true;
                        shopItems[pos].amount -= amount;
                        player.coin -= shopItems[pos].price * amount;
                        cout << "You spend " << shopItems[pos].price * amount << " G.\n\n";
                        renderNpc("Charon", "Thanks for purchase. :D");
                    } else {
                        renderNpc("Charon", "That's not enough money.");
                        break;
                    }
                }
            }
            break;
        case '3':    //talk
            // player talk before buying and first meeting Charon
            if (player.isFirst && !bought) {
                cin.ignore();
                renderNpc("Charon", "Why do I need to talk to someone");
                cout << "<Press Enter to Continue>";
                cin.ignore(1024, '\n');
                renderNpc("Charon", "that even haven't bought anything.");
                cout << "<Press Enter to Continue>";
                cin.ignore(1024, '\n');
                break;
            } else {
                int c;                    // int for player's choice of actions
                bool isTalking = true;    // bool for determine whether player closes talking
                while (isTalking) {
                    srand(time(NULL));    // seed random for generating Charon's log
                    talkAgain("Don't waste much time.", isTalking, c, player.isFirst);
                    switch (c) {
                    case 1:    //say hello
                        if (player.isFirst) {
                            string logs[3] = {"Hmmm", "What?", "..."};
                            renderNpc("Charon", logs[rand() % 3]);
                            cin.ignore(1024, '\n');
                            cout << endl;
                            break;
                        } else {
                            string logs[3] = {"Hello", "Hi", "What's up? Bro."};
                            renderNpc("Charon", logs[rand() % 3]);
                            break;
                        }
                        break;
                    case 2:    // what can I do?
                        cin.ignore();
                        renderNpc("Charon", "You want to know what to do here?");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "Normally, you should be suffering");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "from the afterlife torturement.");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "But seems like you are lucky enough");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "to stand here still.");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "Earn money and GIVE them to ME :D");
                        break;
                    case 3:    // What are you doing?
                        cin.ignore();
                        renderNpc("Charon", "Huh?");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "You are asking me?");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "Can't you see what am I doing??");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "EARNING MONEY (from you)");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "Money is never enough.");
                        break;
                    case 4:    // Life(?)
                        cin.ignore();
                        renderNpc("Charon", "Earn Money.");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "Save as much as you can.");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "It might save your life as well.");
                        cout << "<Press Enter to Continue>";
                        cin.ignore(1024, '\n');
                        cout << endl;
                        renderNpc("Charon", "although you had been dead ;)");
                        break;
                    case 5:    // (Nothing to ask)
                        break;
                    }
                }
            }
            break;
        }
        // deal with player's choice in action
        tryAgainInShop(key);
    }
    renderNpc("Charon", "Bye now, little buddy.");
    player.isFirst = false;
}