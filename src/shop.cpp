#include "shop.h"
#include "npc.h"
#include <iomanip>
#include <iostream>
#include <thread>
#include <time.h>
#include <vector>

using namespace std;

vector<ShopItem> shopItems;

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0)
            return false;
    }
    return true;
}

void sortShopItems(vector<ShopItem> &shopItems) {
    for (int i = 0; i < shopItems.size() - 1; i++)
        for (int j = i + 1; j < shopItems.size(); j++)
            if (shopItems[i].name == shopItems[j].name)
                shopItems.erase(shopItems.begin() + j);
}

bool isWithinBackpack(vector<Item> &items, string choice) {
    int sizeOfBackpack;
    for (sizeOfBackpack = 0; sizeOfBackpack < maxSpace; sizeOfBackpack++)
        if (items[sizeOfBackpack].name == "" || items[sizeOfBackpack].num <= 0)
            break;
    for (int i = 0; i < sizeOfBackpack; i++) {
        if (choice == to_string(i + 1))
            return true;
    }
    return false;
}

bool isWithinShop(vector<ShopItem> shopItems, string choice) {
    for (int i = 0; i < shopItems.size(); i++)
        if (choice == to_string(i + 1))
            return true;
    return false;
}

void generateShopItems(Player player, vector<ShopItem> &shopItems) {
    srand(player.gameLevel + time(NULL));
    while (shopItems.size() < 12) {
        //items that only sold in shop
        if (rand() % 100 > 90 - player.level) {
            if (rand() % 7 == 0) {
                shopItems.push_back({"vorpan", "(+10 ATK, -10 Energy/atk)", 1, 3819, 45});
            } else if (rand() % 7 == 1) {
                shopItems.push_back({"soul sword", "(+20 ATK, -8 Energy/atk, -8 MP/atk)", 1, 6666, 66});
            } else if (rand() % 7 == 2) {
                shopItems.push_back({"twin daggers", "(+14 Atk, -12 Energy/atk)", 1, 4242, 44});
            } else if (rand() % 7 == 3) {
                shopItems.push_back({"war spear", "(+12 Atk, -7 Energy/atk)", 1, 3647, 39});
            } else if (rand() % 7 == 4) {
                shopItems.push_back({"blood katana", "(+18 Atk, -20 Energy/atk)", 1, 4536, 42});
            } else if (rand() % 7 == 5) {
                shopItems.push_back({"toothpick", "(+15 Atk, -25 Energy/atk)", 1, 3840, 40});
            } else if (rand() % 7 == 6) {
                shopItems.push_back({"diamond sword", "(Best weapon you can have!)", 1, 9999999, 1999});
            }
        } else if (rand() % 100 > 75 - player.level) {
            if (rand() % 2 == 0) {
                shopItems.push_back({"diamond shield", "(Best armor you can have!)", 1, 999999, 999});
            } else {
                shopItems.push_back({"golden shield", "(+20 DFS)", 1, 1980, 72});
            }
        } else if (rand() % 100 > 50 - player.level) {
            if (rand() % 2 == 0) {
                shopItems.push_back({"high healing", "(+100 HP)", (1 + rand() % 3), 420, 50});
            } else {
                shopItems.push_back({"medium healing", "(+75 HP)", (1 + rand() % 4), 288, 36});
            }
        }
        //generate healings
        if (rand() % 100 <= 90) {
            shopItems.push_back({"monster meat", "(Are you sure to eat that?)", (1 + rand() % 20), 12, 2});
        }
        if (rand() % 100 <= 50) {
            shopItems.push_back({"bread", "(You're \"toast\".)", (1 + rand() % 10), 30, 5});
        }
        if (rand() % 100 >= 25) {
            shopItems.push_back({"poor healing", "(+10 HP)", (1 + rand() % 20), 65, 10});
        }
        if (rand() % 100 >= 50) {
            shopItems.push_back({"average healing", "(+20 HP)", (1 + rand() % 15), 90, 15});
        }
        if (rand() % 100 >= 75) {
            shopItems.push_back({"decent healing", "(+50 HP)", (1 + rand() % 10), 145, 24});
        }
        //generate armors
        if (rand() % 50 <= 45) {
            shopItems.push_back({"boat remains", "(...)", (1 + rand() % 50), 15, 1});
        }
        if (rand() % 50 <= 30) {
            shopItems.push_back({"wood shield", "(+5 DFS)", 1, 150, 10});
        } else if (rand() % 50 <= 25) {
            shopItems.push_back({"leather shield", "(+10 DFS)", 1, 550, 40});
        } else if (rand() % 50 <= 10) {
            shopItems.push_back({"silver shield", "(+15 DFS)", 1, 900, 60});
        }
        //generate weapons
        if (rand() % 25 >= 22) {
            shopItems.push_back({"hammer", "(+10 ATK, -30 Energy/atk)", 1, 592, 37});
        } else if (rand() % 25 >= 20) {
            shopItems.push_back({"great sword", "(+8 ATK, -15 Energy/atk)", 1, 290, 18});
        } else if (rand() % 25 >= 12) {
            shopItems.push_back({"long sword", "(+4.5 ATK, -5 Energy/atk)", 1, 204, 15});
        }
        if (rand() % 25 <= 20) {
            shopItems.push_back({"sword", "(+2 ATK, -0.5 Energy/atk)", 1, 169, 5});
        } else if (rand() % 25 <= 12) {
            shopItems.push_back({"wand", "(+8 ATK, -15 MP/atk)", 1, 474, 30});
        } else {
            shopItems.push_back({"spear", "(+6 ATK, -10 Energy/atk)", 1, 200, 12});
        }
    }
    sortShopItems(shopItems);
}

void displayShopItems(vector<ShopItem> shopItems) {
    std::cout << "Items\t\t\t\tDescription\t\t\t\tNumber\t\tPrice" << endl;
    for (int i = 0; i < shopItems.size(); i++) {
        std::cout << (i + 1) << "  " << shopItems[i].name << setfill(' ')
                  << setw(30 - shopItems[i].name.length() - to_string(i + 1).length() + shopItems[i].desc.length())
                  << shopItems[i].desc << setw(44 - shopItems[i].desc.length()) << shopItems[i].amount << "\t\t" << shopItems[i].price << " G" << endl;
    }
}

void talkAgain(string str, bool &isTalking, int &c, bool isFirst) {
    string choice = " ";
    while ((choice[0] != '1' && choice[0] != '2' && choice[0] != '3' && choice[0] != '4' && choice[0] != '5') || choice[1] != '\0') {
        renderNpc("Charon", str);
        std::cout << "1 - Say Hello";
        if (!isFirst) {
            cout << " (again)";
        }
        std::cout << "\n"
                  << "2 - What to do here?\n"
                  << "3 - Why are you here?\n"
                  << "4 - Life advice(?)\n"
                  << "5 - (Nothing to ask)\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
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

void tryAgainInShop(string &key) {
    key = "";
    while (key[0] != '1' && key[0] != '2' && key[0] != '3' && key[0] != '4' || key[1] != '\0') {
        renderNpc("Charon", "Welcome, have a look.");
        std::cout << "ACTION (please input number 1-4)" << endl
                  << "1 - Sell                    2 - Buy " << endl
                  << "3 - Talk                    4 - Exit" << endl;
        std::cin >> key;
        std::cout << endl;
    }
}

void shopScreen(Player &player, vector<Item> &items) {
    shopItems.clear();
    string key = "";
    bool bought = false;
    tryAgainInShop(key);
    while (key != "4") {
        string choice;    // string for two digit nums
        int pos;
        int amount;
        switch (key[0]) {
        case '1':
            renderNpc("Charon", "Sell something?");
            displayBackpack(items, true);
            std::cout << "You have " << player.coin << " G." << endl;
            std::cout << "Press [number] to sell or [Q] to quit.\n"
                      << "Enter your choice: ";
            std::cin >> choice;
            if (choice == "q" || choice == "Q") {
                renderNpc("Charon", "Just looking? :(");
                break;
            }
            while (!isNumber(choice) || !isWithinBackpack(items, choice)) {
                std::cout << "No such item, please select again: ";
                std::cin >> choice;
                if (choice == "q" || choice == "Q") {
                    renderNpc("Charon", "Just looking? :(");
                    cout << "test\n";
                    break;
                }
            }
            for (pos = 0; pos < maxSpace; pos++) {
                if (choice == to_string(pos + 1)) {
                    std::cout << "Amount to sell: ";
                    std::cin >> amount;
                    while (amount > items[pos].num || amount < 0) {
                        std::cout << "Exceeds amount, please enter a valid number: ";
                        std::cin >> amount;
                    }
                    updateItems(items[pos].name, amount, items[pos].cost, 'D', items);
                    player.coin += items[pos].cost * amount;
                    std::cout << "You gain " << items[pos].cost * amount << " G.\n\n";
                    break;
                }
            }
            break;
        case '2':
            if (shopItems.empty())
                cout << "searching for shop items... " << endl;
            while (shopItems.size() < 12)
                generateShopItems(player, shopItems);
            displayShopItems(shopItems);
            std::cout << "You have " << player.coin << " G." << endl;
            renderNpc("Charon", "What do you wanna buy?");
            std::cout << "Press [number] to buy or [Q] to quit.\n"
                      << "Enter your choice: ";
            std::cin >> choice;
            if (choice == "q" || choice == "Q") {
                renderNpc("Charon", "Just looking? :(");
                break;
            }
            while (!isNumber(choice) || !isWithinShop(shopItems, choice)) {
                std::cout << "No such item, please select again: ";
                std::cin >> choice;
                if (choice == "q" || choice == "Q") {
                    renderNpc("Charon", "Just looking? :(");
                    break;
                }
            }
            for (pos = 0; pos < shopItems.size(); pos++) {
                if (choice == to_string(pos + 1)) {
                    if (player.coin < shopItems[pos].price) {
                        renderNpc("Charon", "That's not enough money.");
                        renderNpc("Charon", "YOU CAN'T EVEN BUY ONE!!");
                        break;
                    }
                    std::cout << "Amount to buy: ";
                    std::cin >> amount;
                    while (amount > shopItems[pos].amount || amount < 0) {
                        renderNpc("Charon", "I have not that much.");
                        std::cout << "Amount to buy: ";
                        std::cin >> amount;
                    }
                    for (int i = 0; i < maxSpace; i++) {
                        if (items[i].name == shopItems[pos].name) {
                            if ((items[i].num + amount) > maxStack)
                                renderNpc("Charon", "You're carrying too much.");
                            while (items[i].num + amount > maxStack) {
                                std::cout << "(Remaining space for " << items[i].name << " = " << (99 - items[i].num) << ')' << endl;
                                std::cout << "Amount to buy: ";
                                std::cin >> amount;
                            }
                            break;
                        }
                    }
                    if (amount == 0) {
                        renderNpc("Charon", "Just looking? :(");
                        break;
                    }
                    if (player.coin >= (shopItems[pos].price * amount)) {
                        updateItems(shopItems[pos].name, amount, shopItems[pos].cost, 'A', items);
                        bought = true;
                        shopItems[pos].amount -= amount;
                        player.coin -= shopItems[pos].price * amount;
                        std::cout << "You spend " << shopItems[pos].price * amount << " G.\n\n";
                        renderNpc("Charon", "Thanks for purchase. :D");
                    } else {
                        renderNpc("Charon", "That's not enough money.");
                        break;
                    }
                }
            }
            break;
        case '3':
            if (player.isFirst && !bought) {    //talk before buying
                renderNpc("Charon", "Why do I need to talk to someone");
                renderNpc("Charon", "that even haven't bought anything.");
                break;
            } else {
                int c;
                bool isTalking = true;
                while (isTalking) {
                    srand(time(NULL));
                    talkAgain("Don't waste much time.", isTalking, c, player.isFirst);
                    switch (c) {
                    case 1:
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
                    case 2:
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
                    case 3:
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
                    case 4:
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
                    case 5:
                        break;
                    }
                }
            }
            break;
        }
        tryAgainInShop(key);
    }
    renderNpc("Charon", "Bye now, little buddy.");
    player.isFirst = false;
}