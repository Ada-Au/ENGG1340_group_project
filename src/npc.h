#ifndef NPC_h
#define NPC_h

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
const Monster boss1 = {"grief", 300, 200};
const Monster boss2 = {"anxiety", 480, 300};
const Monster boss3 = {"diseases", 660, 345};
const Monster boss4 = {"oldAge", 845, 600};
const Monster boss5 = {"fear", 1020, 555};
const Monster boss6 = {"hunger", 1440, 650};
const Monster boss7 = {"need", 1630, 700};
const Monster boss8 = {"death", 1925, 740};
const Monster boss9 = {"agony", 2222, 777};
const Monster boss10 = {"nightmare", 2666, 800};
const Monster boss11[monsterSize] = {{"hades1", 3333, 999}, {"hades2", 6666, 999}};


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

// const string monster[npcSize] = {
//     "                                                   ",    // length ~50
//     "                                                   ",    // monster
//     "                                                   ",
//     "               +------.        .------+           ",
//     "               |       \\      /       |           ",
//     "               |        \\    /        |           ",
//     "               |    .    \\  /    .    |           ",
//     "               |    |\\    \\/    /|    |          ",
//     "               |    | \\        / |    |          ",
//     "               |    |  +------+  |    |          ",
//     "               |    |            |    |          ",
//     "               |    |            |    |          ",
//     "               +----+            +----+          ",
//     "                                                   ",
//     "                                                   ",
//     "                                                   ",
// };

const string charon[npcSize] = {
    "                      .---.                        ",    //length ~50
    "                     ,      `                      ",    //the boat guy & saleclerk
    "                    / _.-._  |                     ",
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
    " `--RRRRS  /                       .--- )          ",
    "     RRRRS|                        .____)          ",
};

const string grief[npcSize] = {
    "                         .---.                      ",    //level 1 boss
    "                       ,       `.                   ",    //freezing
    "                      /  .~^~.    }                 ",
    "                     /  /_) (_ \\  \\               ",
    "                    |  | : ^  :_ \\  \\             ",
    "                    | / v^U^U^V   \\  |             ",
    "                    | >  :    ;    \\_|             ",
    "                    --        --  |   |             ",
    "                  /    \\    /    /   \\            ",
    "                 |||||\\ \\  |||||     |            ",
    "                 vvvv   v  vvvv        |            ",
    "                    |    ;    :        |            ",
    "                    |         ;        |            ",
    "                    |    :             |            ",
    "                    |         :        |            ",
    "                    |    ;             |            ",

};

const string anxiety[npcSize] = {
    "                           ( ___  )                ",      //level 2 boss
    "           (`               /  @ {_/7_             ",      //burning
    "         .)   (             |__n( __  \\           ",
    "        (       )            nnn/   ) /            ",
    "          ~^ ~ .        ._          ||  )          ",
    "                       v~\\ \\      /    ) `       ",
    "                        (((( ) \\ /  .(   )        ",
    "                    )           /   )      )       ",
    "                  .(  .        /     ^~`.^  .      ",
    "                 )    (        \\   |_.            ",
    "                )       )       + .-+  }           ",
    "                 (_. ^~           / /  | |         ",
    "                            /  |_/   \\            ",
    "                           /      /||\\\\          ",
    "                          //V\\    \\|//           ",
    "                                                   ",

};

const string diseases[npcSize] = {
    "                           _____________           ",      //level 3 boss
    "                          /  _______ (             ",      //posioning
    "                         | |\\      (              ",
    "                __      /  | \\    (               ",
    "              (    )__ /   |  \\_{_________        ",
    "          * __/  __        | /  _______(_          ",
    "          \\_= @(    )      |/  \\    (    \\      ",
    "            VV /                \\ (     .'        ",
    "            ^~\" --                    _/          ",
    "                  7/ \\ _(    _/   \\  \\          ",
    "                 //  (((___(((   _ /  /            ",
    "              ////||         __ /  /               ",
    "              V V V        /  o  /                 ",
    "                           V~V~`/                  ",
    "                           ^~^*;                   ",
    "                               .                   ",

};

const string oldAge[npcSize] = {
    "                        ____                        ",     //level 4 boss
    "                      .  __  `                      ",     //healing effect is half
    "                     /   __   \\                    ",
    "                    / (#)   () \\                   ",
    "        .-----.     |     7    |                    ",
    "       /       \\    ` ^....;^./                    ",
    "       \\       / .$-+ `^....^;/+-$.                ",
    "         `----` /    \\      /     \\               ",
    "           \\/  /       \\.-./       \\             ",
    "           || /         |  +|     .--.              ",
    "           ||/ XXXXXXXXX `-^   XX/ '_`\\     ____   ",
    "           ||               .--.  \\ \\ `. *  / .-.)",
    "         ( ===.            ( .  `.)  \\    / /   *  ",
    "         ( ]--.              * \\   ___  `-' /      ",
    "         ( ---'                /  (___)   _'        ",
    "         ( ---'               /                     ",

};
const string fear[npcSize] = {
    "                       .-.                         ",      //level 5 boss
    "                      /   \\                       ",      //hit rate drops / max.mp drops
    "                     | .-. |         ^             ",
    "                     | `-' |        |o|            ",
    "       / \\            \\   /          v           ",
    "      |O  |            `-'                         ",
    "       \\ /                    /\\                 ",
    "                 .-.         |O |                  ",
    "                /.-.\\         \\/                 ",
    "               | `-' |               _             ",
    "               |     |              /  \\          ",
    "                \\   /              |  O |         ",
    "     / \\         `-'                \\_ /         ",
    "    |  O|                                          ",
    "     \\ /                                          ",

};
const string hunger[npcSize] = {
    "             .---..__/\\    /\\  .---.              ",     //level 6 boss
    "            (,` \\       `./  -' .'` .)             ",     //hunger
    "                {                \\                 ",
    "               /    `~V-v~vvvV`   \\                ",
    "             .{       ^^.__.^      }                ",
    "     .4.4-4~'   `      `-----'      '~--4-4.4.      ",
    "   /          .___.-----.___.                  \\   ",
    "  /             \\V~vvVv~vV/       ___.          \\ ",
    " /               \\^~n^nn^/       'YYY            \\",
    "                         ;         .----.           ",
    "       `..----.-' \\               /^V ~vV          ",
    "         `Vv~V`^`(       :       /     (            ",
    "          ;)      )              \\~/YYY;           ",
    "          \\YY^~^_/                     .           ",
    "          .                       :                 ",
    "          ;                                         ",
};
const string need[npcSize] = {
    "                     /|                            ",      //level 7 boss
    "                  _./ |/|----------._              ",      //hp/mp is drained
    "                ./     _/             `.           ",
    "               /   @  /     .---.       \\         ",
    "  o   __..__  {  _/-----'--(  O  ) -`.   )         ",
    "    .' .'   ` `' L    P    |`---'      %%          ",
    "   /  /           - _ |    |      o                ",
    "   |  `.___./        ||    |                       ",
    "    `._  __.       ./=|____|\\    __   O  ___      ",
    "       `'||  o    | +         |  | (    / _(       ",
    "         ||      (   (     Y  |  `.\\ V)| \\'      ",
    "    O    ||       \\      /|  |     `''_ /         ",
    "         ||        |    / |  |                     ",
    "         ||        |   /\\ |  |             O      ",
    "         ||       /   |  \\   |      o             ",
    "         ||      /    |   \\  |                    ",

};
const string death[npcSize] = {
    "                  .----.           .               ",      //level 8 boss
    "                 /   .--`.        //               ",      //
    "                /   (:::(       lllll              ",
    "               {     ):::)      //  llll.          ",
    "               /    (:::/\\     //     ^lll.       ",
    "              )      `:'  \\   //         ^lll.    ",
    "             /             \\ //            ^lll   ",
    "            /      ________.---.             ^ll   ",
    "            \\            / ===.                V  ",
    "             \\          / ----'                   ",
    "             |\\         |----'                    ",
    "             | \\        |(   |                    ",
    "             |  \\       | )  |                    ",
    "             )   \\      |/   |                    ",
    "            /     \\     |    |                    ",
    "           /       \\    |    |                    ",
};
const string agony[npcSize] = {
    "                            |                       ",     //level 9 boss
    "                           .-''--.   `.             ",     //bleeding
    "                          /       `   \\            ",
    "      /                   |.   .-. |   |            ",
    "     |\\                   }:) (::| {.-``           ",
    "     | \\                  |:|_|::| |               ",
    "     \\  \\             __) `-----'-'}_             ",
    "      \\  \\ +-+ __   '      __-.-='   (_.          ",
    "       \\  `  .|   \\      (____/-.       ______    ",
    "         `.  ||\\   |              \\    /  ----.\\ ",
    "          | ` | | .'        ___     \\  | |     ||  ",
    "           +-+\\| |          | |      `.| |     ||  ",
    "            \\____'      ____| |____    | |     ||  ",
    "                       '--==+ +==--'   | |     ||   ",
    "                            / \\        | |     ||  ",
    "                           |   |       | |     ||   ",
    
};
const string nightmare[npcSize] = {
    "           ---.  .  -  -  .   .---                 ",      //boss 10
    "          __.) )             ( (.__                ",
    "        (   .--                --.  )              ",
    "        \\  '-----.       .-----'  /               ",
    "        ' '.(_(_( '------' )_)_).' '               ",
    "       '          '.     .'         '              ",
    "       '           |)   (|          '             ",
    "      '             \\ ^ /            '    ",
    "      '              '.'             '     ",
    "       '          ---------          '     ",
    "       '        /           \\        '     ",
    "        '       |           |      '   ",
    "         '       \\         /     '    ",
    "           '      \\       /     '     ",
    "             '                '       ",
    "                 '  -  -  '               ",
};
#endif