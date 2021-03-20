#ifndef NPC_h
#define NPC_h

#include <iostream>

using namespace std;

const int max_size = 20;

class NPC {
  public:
    string Charon[max_size] = {
        "                      .---.                        ",    // length ~50
        "                     ,      `                      ",
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

    string Grief[max_size] = {
        "                         .---.                         ",
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
};
#endif