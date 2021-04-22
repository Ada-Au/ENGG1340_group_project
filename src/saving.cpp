#include "saving.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// TODO warn player if file already exist: give choice: cover or new name for file
// TODO encrytion?
// TODO fileName cannot be Q or q

void saveGame(Player player, Item items[]) {
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

    for (int i = 0; i < maxSpace; i++) {
        // TODO again 50 times....
        if (items[i].name != "" && items[i].num > 0) {
            saveFile << items[i].name << ' ' << items[i].num << ' ' << items[i].cost << ' ';
        }
    }

    saveFile.close();
}

void getSavedGame(Player &player, string fileName, Item items[]) {
    ifstream file;
    file.open(fileName + ".txt");
    while (file.fail()) {
        cout << "File not exist. Please input again or press Q to starting screen: ";
        cin >> fileName;
        if (fileName == "Q" || fileName == "q") {
            return;
        } else {
            file.open(fileName + ".txt");
        }
    }

    file >> player.mp >> player.hp >> player.energy >> player.exp >> player.maxExp >> player.maxMp >> player.maxEnergy >> player.damage >> player.defense >> player.maxHp;
    file >> player.level >> player.gameLevel >> player.coin;
    getline(file, player.weapon.name);
    getline(file, player.armor);
    file >> player.weapon.damage >> player.weapon.mp >> player.weapon.energy >> player.aDefense;

    int buffNum;
    string tempBuff;
    file >> buffNum;
    for (int i = 0; i < buffNum; i++) {
        file >> tempBuff;
        addBuff(false, tempBuff, player);
    }
    file >> buffNum;
    for (int i = 0; i < buffNum; i++) {
        file >> tempBuff;
        addBuff(true, tempBuff, player);
    }

    getline(file, player.name);
    file >> player.role >> player.gender >> player.race >> player.isFirst;

   
    file.close();
}
