#include "npc.h"
#include <iomanip>
#include <iostream>

void printNpc(string talk, const string npc[npcSize]) {
    bool isTalk = talk.length() > 0;
    for (int i = 0; i < npcSize - 5; i++) {
        cout << npc[i] << endl;
    }
    if (isTalk) {
        string space(22 - talk.length() / 2, ' ');

        cout << setfill('*') << setw(50) << '\n';
        cout << '*' << setfill(' ') << setw(48) << '*' << '\n';
        cout << "* " << space << talk << space;
        if (talk.length() % 2 == 0) {
            cout << ' ';
        }
        cout << " *" << '\n';
        cout << '*' << setfill(' ') << setw(48) << '*' << '\n';
        cout << setfill('*') << setw(50) << '\n';
    } else {
        for (int i = npcSize - 5; i < npcSize; i++) {
            cout << npc[i] << endl;
        }
    }
}

void renderNpc(string npc, string talk) {
    if (npc == "Monster" || npc == "Monster (enchanted)")
        printNpc(talk, monster);
    else if (npc == "Charon")
        printNpc(talk, charon);
    else if (npc == "Grief") {
        printNpc(talk, grief);
    } else if (npc == "Anxiety") {
        printNpc(talk, anxiety);
    } else if (npc == "Diseases") {
        printNpc(talk, diseases);
    } else if (npc == "Old Age") {
        printNpc(talk, oldAge);
    } else if (npc == "Fear") {
        printNpc(talk, fear);
    } else if (npc == "Hunger") {
        printNpc(talk, hunger);
    } else if (npc == "Need") {
        printNpc(talk, need);
    } else if (npc == "Death") {
        printNpc(talk, death);
    } else if (npc == "Agony") {
        printNpc(talk, agony);
    } else if (npc == "Nightmare") {
        printNpc(talk, nightmare);
    } else if (npc == "Hades(calm)" || npc == "Hades(angry)") {
        cout << "yup, i've got no face:D" << endl;
    }
}
