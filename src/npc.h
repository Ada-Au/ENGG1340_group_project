#ifndef NPC_h
#define NPC_h

#include "player.h"
#include <string>
using namespace std;

void renderNpc(string, string);
const int npcSize = 16;
const int monsterSize = 2;
struct Monster {
    string name;
    float hp, mp;
};

const Monster monsters[monsterSize] = {{"a", 10, 20}, {"b", 30, 40}};
const Monster boss1 = {"grief", 200, 200};
const Monster boss2 = {"anxiety", 350, 300};
const Monster boss3 = {"diseases", 400, 345};
const Monster boss4 = {"oldAge", 450, 600};
const Monster boss5 = {"fear", 500, 555};
const Monster boss6 = {"hunger", 550, 650};
const Monster boss7 = {"need", 600, 200};
const Monster boss8 = {"death", 666, 444};
const Monster boss9 = {"agony", 750, 450};
const Monster boss9 = {"insomnia", 700, 999};
const Monster boss10 = {"hades", 1000, 666};


const string monster[npcSize] = {
    "                                                   ",    // length ~50
    "                                                   ",    // monster
    "                                                   ",
    "             MMMMM               MMMMM             ",
    "             MMMMMMM           MMMMMMM             ",
    "             MMMMMMMMM       MMMMMMMMM             ",
    "             MMMMMMMMMMM   MMMMMMMMMMM             ",
    "             MMMMM  MMMMMMMMMMM  MMMMM             ",
    "             MMMMM     MMMMM     MMMMM             ",
    "             MMMMM       M       MMMMM             ",
    "             MMMMM               MMMMM             ",
    "             MMMMM               MMMMM             ",
    "             MMMMM               MMMMM             ",
    "                                                   ",
    "                                                   ",
    "                                                   ",
};

const string charon[npcSize] = {
    "                      .---.                        ",    // length ~50
    "                     ,      `                      ",    // the boat guy
    "                    / _.-._  l                     ",
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
    "                       ,       `.                      ",    // freezing
    "                      /  .~^~.    }                     ",
    "                     /  /_) (_ \\  \\                  ",
    "                    |  | : ^  :_ \\  \\                ",
    "                    | / v^U^U^V   \\  |                ",
    "                    | >  :    ;    \\_|                ",
    "                    --        --  |   |               ",
    "                  /    \\    /    /   \\              ",
    "                 |||||\\ \\  |||||     |             ",
    "                 vvvv   v  vvvv        |              ",
    "                    |    ;    :        |               ",
    "                    |         ;        |               ",
    "                    |    :             |              ",
    "                    |         :        |               ",
    "                    |    ;             |               ",

};

const string anxiety[npcSize] = {
    "                           ( ___  )                    ",
    "           (`               /  @ {_/7_                 ",
    "         .)   (             |__n( __  \\               ",
    "        (       )            nnn/   ) /                ",
    "          ~^ ~ .        ._          ||  )              ",
    "                       v~\\ \\      /    ) `             ",
    "                        (((( ) \\ /  .(   )            ",
    "                    )           /   )      )           ",
    "                  .(  .        /     ^~`.^  .           ",
    "                 )    (        \\   |_.                 ",
    "                )       )       + .-+  }                 ",
    "                 (_. ^~           / /  | |                ",
    "                            /  |_/   \\               ",
    "                           /      /||\\\\               ",
    "                          //V\\    \\|//               ",

};

const string diseases[npcSize] = {
    "                           _____________             ",
    "                          /          (               ",
    "                         |         (                ",
    "                __      /         (                 ",
    "              (    )__ /      __{_________            ",
    "          * __/  __          /        (_             ",
    "          \\_= @(    )       /       (    \\           ",
    "            VV /                  (      )         ",
    "            ^~\" --                    _/          ",
    "                  7/ \\ _(    _/   \\  \\            ",
    "                 //  (((___(((   _ /  /           ",
    "              ////||         __ /  /              ",
    "              V V V        /  *  /                 ",
    "                           V~V~`/                 ",
    "                           ^~^*                  ",
};

const string oldAge[npcSize] = {
    "                        ____                     ",
    "                      .  __  `                   ",
    "                     /   __   \\                 ",
    "                    / (#)   () \\                 ",
    "        .-----.     |     7    |                 ",
    "       /       \\    ` ^....;^./                  ",
    "       \\       / .--+ `^....^;/+--.               ",
    "         `----` /    \\      /     \\             ",
    "           \\/  /       \\.-./       \\            ",
    "           || /         |  +|     .--.           ",
    "           ||/ XXXXXXXXX `-^   XX/ '_`\\     ____  ",
    "           ||               .--.  \\ \\ `. *  / .-.)      ",
    "         ( ===.            ( .  `.)  \\    / /   *      ",
    "         ( ]--.              * \\   ___  `-' /       ",
    "         ( ---'                /  (   )   _'       ",


};
const string fear[npcSize] = {
    "                       .-.                        ",
    "                      /   \\                      ",
    "                     | .-. |         ^            ",
    "                     | `-' |        |o|           ",
    "       / \\            \\   /          v            ",
    "      |O  |            `-'                         ",
    "       \\ /                    /\\                  ",
    "                 .-.         |O |                  ",
    "                /.-.\\         \\/                   ",
    "               | `-' |               _            ",
    "               |     |              /  \\          ",
    "                \\   /              |  O |          ",
    "     / \\         `-'                \\_ /          ",
    "    |  O|                                         ",
    "     \\ /                                          ",

};
const string hunger[npcSize] = {
    "                                 "
};
const string need[npcSize] = {};
const string death[npcSize] = {};
const string agony[npcSize] = {};
const string insomnia[npcSize] = {};

#endif