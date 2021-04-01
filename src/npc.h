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
    "                      /  .~^~.    }                     ",
    "                     /  /_) (_ \\  \\                  ",
    "                    |  | : ^  :_ \\  \\                ",
    "                    | / v^U^U^V   \\  |                ",
    "                    | >  :    ;    \\_|                ",
    "                    --        --  |   |               ",
    "                  /    \\    /    /   \\              ",
    "                 |||||\\ \\  |||||     |            ",
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

const string oldAge[npcSize] = {};
const string fear[npcSize] = {};
const string hunger[npcSize] = {};
const string need[npcSize] = {};
const string death[npcSize] = {};
const string agony[npcSize] = {};
const string sleep[npcSize] = {};


#endif