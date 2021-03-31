#ifndef NPC_h
#define NPC_h

#include "player.h"
#include <iomanip>
#include <iostream>
using namespace std;

void renderNpc(string, string);
const int npcSize = 16;
const string charon[npcSize] = {
    "                      .---.                        ",    // length ~50
    "                     ,      `                      ",    // the boat guy
    "                    / _.-._  1                     ",
    "                   / /:::::\\  \\                  ",
    "                   > |:::::|  |                    ",
    "                   } |:::::|  {    ____            ",
    "                  .  `-;;--:   L./       \\        ",
    "                .+              |`*)  *)( |        ",
    "                |               |   ^    /         ",
    "               /                 `.....^           ",
    "              |                     |||            ",
    " SSSS        /                      |||            ",
    "SGGGGGS     /                       |||`           ",
    "SGGG.RRS   /                       .=== }          ",
    " `--RRRRS  /                       .--- )         ",
    "     RRRRS|                        .____)          ",
};

const string grief[npcSize] = {
    "                         .---.                         ",    // level1 boss
    "                       ,       `.                      ",
    "                      /  .~^~.   }                     ",
    "                     /  /_) (_ \\  \\                  ",
    "                    |  | : ^  :_ \\  \\                ",
    "                    | / v^U^U^V   \\  |                ",
    "                    | >  :    ;    \\_|                ",
    "                    |    ;    :       |                ",
    "                    |         ;       |                ",
    "                    |    :            |                ",
    "                    |         :       |                ",
    "                    |    ;           /                 ",
    "                    --        --      \\               ",
    "                  /    \\    /    /     \\            ",
    "                 |||||\\ \\  |||||        \\         ",
    "                 vvvv   v  vvvv          \\            ",
};

#endif