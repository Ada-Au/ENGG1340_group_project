#include "npc.h"

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
    if (npc == "charon")
        printNpc(talk, charon);
    else if (npc == "grief") {
        printNpc(talk, grief);
    }
}
