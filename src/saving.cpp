#include "saving.h"
#include "env.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// TODO warn player if file already exist: give choice: cover or new name for file
// TODO encrytion?
// TODO fileName cannot be Q or q

void saveGame(Player player, vector<Item> &items) {
    ofstream saveFile;
    saveFile.open(player.name + ".txt");

    saveFile << player.mp << ' ' << player.hp << ' ' << player.energy << ' ' << player.exp << ' ' << player.maxExp << ' ' << player.maxMp << ' ' << player.maxEnergy << ' ' << player.damage << ' ' << player.defense << ' ' << player.maxHp << endl;
    saveFile << player.level << ' ' << player.gameLevel << ' ' << player.coin << endl;
    saveFile << player.weapon.name << endl;
    saveFile << player.armor << endl;
    saveFile << player.weapon.damage << ' ' << player.weapon.mp << ' ' << player.weapon.energy << ' ' << player.aDefense << endl;

    saveFile << player.debuffs.size() << ' ';
    for (int i = 0; i < player.debuffs.size(); i++) {
        saveFile << player.debuffs[i].name << ' ';
    }
    saveFile << endl;

    saveFile << player.buffs.size() << ' ';
    for (int i = 0; i < player.buffs.size(); i++) {
        saveFile << player.buffs[i].name << ' ';
    }
    saveFile << endl;

    saveFile << player.name << endl;
    saveFile << player.role << ' ' << player.gender << ' ' << player.race << ' ' << player.isFirst << endl;

    saveFile << items.size() << endl;
    for (int i = 0; i < items.size(); i++) {
        saveFile << items[i].name << endl;
        saveFile << items[i].num << ' ' << items[i].cost << endl;
    }

    saveFile.close();
}

void getSavedGame(Player &player, vector<Item> &items) {
    string fileName;
    cout << "Please input the file name you want to continue: ";
    cin >> fileName;
    ifstream file;
    file.open(fileName + ".txt");
    while (file.fail()) {
        cout << "File not exist. Please input again or press [Q] to starting screen: ";
        cin >> fileName;
        if (fileName == "Q" || fileName == "q") {
            return;
        } else {
            file.open(fileName + ".txt");
        }
    }

    string tempName;
    file >> player.mp >> player.hp >> player.energy >> player.exp >> player.maxExp >> player.maxMp >> player.maxEnergy >> player.damage >> player.defense >> player.maxHp;
    file >> player.level >> player.gameLevel >> player.coin;

    file.ignore();
    getline(file, tempName);
    player.weapon.name = tempName;
    getline(file, tempName);
    player.armor = tempName;

    file >> player.weapon.damage >> player.weapon.mp >> player.weapon.energy >> player.aDefense;

    int lineNum;
    file >> lineNum;
    for (int i = 0; i < lineNum; i++) {
        file >> tempName;
        addBuff(false, tempName, player);
    }
    file >> lineNum;
    for (int i = 0; i < lineNum; i++) {
        file >> tempName;
        addBuff(true, tempName, player);
    }

    file.ignore();
    file.ignore();
    getline(file, player.name);
    file >> player.role >> player.gender >> player.race >> player.isFirst;

    file >> lineNum;
    int tempNum, tempCost;
    for (int i = 0; i < lineNum; i++) {
        file.ignore();
        getline(file, tempName);
        file >> tempNum >> tempCost;
        cout << "i name: " << tempName << ' ' << tempNum << ' ' << tempCost << endl;
        updateItems(tempName, tempNum, tempCost, 'A', items);
    }

    file.close();
}
