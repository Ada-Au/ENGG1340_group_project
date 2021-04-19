#include "shop.h"
#include "npc.h"
#include <iomanip>
#include <iostream>
#include <time.h>
#include <thread>
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

bool isWithinBackpack(Item items[], string choice) {
    int sizeOfBackpack;
    for (sizeOfBackpack = 0; sizeOfBackpack < maxSpace; sizeOfBackpack++ ) 
        if (items[sizeOfBackpack].name == "" || items[sizeOfBackpack].num <= 0 ) 
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
    int healNum, weaponNum, armorNum;
    while (shopItems.size() < 12) {    // To-do: make sure shopItems.size = 12
        //items that only sold in shop
        if (rand() % 100 >= 90) {
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
        } else if (rand() % 100 >= 75) {
            if (rand() % 2 == 0) {
                shopItems.push_back({"diamond shield", "(Best armor you can have!)", 1, 999999, 999});
            } else {
                shopItems.push_back({"golden shield", "(+20 DFS)", 1, 1980, 72});
            }
        } else if (rand() % 100 >= 50) {
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

void shopScreen(Player player, Item items[]) {
    char key;
    renderNpc("Charon", "Welcome, have a look.");
    std::cout << "ACTION (please input number 1-4)" << endl
         << "1 - Sell                    2 - Buy " << endl
         << "3 - Talk                    4 - Exit" << endl;
    std::cin >> key;
    while (key != '4') {
        string choice;    // string for two digit nums
        int pos;
        int amount;
        switch (key) {
        case '1':
            renderNpc("Charon", "Sell somehing?");
            displayBackpack(items, true);
            std::cout << "You have " << player.coin << " G." << endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            // std::cout << endl;
            while (!isNumber(choice) || !isWithinBackpack(items, choice)) {    
                // Todo bug: sell can choose things not in bp
                std::cout << "No such item, please select again: ";
                std::cin >> choice;
            } 
            for (pos = 0; pos < maxSpace; pos++) {
                if (choice == to_string(pos + 1)) {
                    std::cout << "Amount to sell: ";
                    std::cin >> amount;
                    while (amount > items[pos].num || amount < 0) {    //To-do: repeat if amount is char/ string
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
            while (shopItems.size() < 12)
                generateShopItems(player, shopItems);
            displayShopItems(shopItems);
            std::cout << "You have " << player.coin << " G." << endl;
            renderNpc("Charon", "What do you wanna buy?");    // Todo sell not working
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            while (!isNumber(choice) || !isWithinShop(shopItems, choice)) {    // To-do: check whether choice is a number with items pos
                std::cout << "No such item, please select again: ";
                std::cin >> choice;
            }
            for (pos = 0; pos < shopItems.size(); pos++) {
                if (choice == to_string(pos + 1)) {
                    if (player.coin < shopItems[pos].price) {
                        renderNpc("Charon", "That's not enough money.");
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        renderNpc("Charon", "You can't even buy one!!");
                        break;
                    }                    
                    std::cout << "Amount to buy: ";
                    std::cin >> amount;
                    while (amount > shopItems[pos].amount || amount < 0) {    //To-do: repeat if amount is char/ string
                        std::cout << "Exceeds amount, please enter a valid number: ";
                        std::cin >> amount;
                    }

                    if (amount == 0) {
                        renderNpc("Charon", "Just looking?");
                        break;
                    }
                    for (int i = 0; i < maxSpace; i++) {
                        if ((items[i].num + amount) > maxStack)
                            renderNpc("Charon", "You're carrying too much.");
                        while (items[i].num + amount > maxStack) {
                            std::cout << "Amount to buy: ";
                            std::cin >> amount;
                        }
                    }
                    if (player.coin >= (shopItems[pos].price * amount)) {
                        updateItems(shopItems[pos].name, amount, shopItems[pos].cost, 'A', items);
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
            break;
        }
        renderNpc("Charon", "Do you else have things to do?");
        std::cout << "ACTION (please input number 1-4)" << endl
             << "1 - Sell                    2 - Buy " << endl
             << "3 - Talk                    4 - Exit" << endl;
        std::cin >> key;
    }
}