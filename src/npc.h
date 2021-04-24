#ifndef NPC_h
#define NPC_h

#include <string>
using namespace std;

void renderNpc(string, string);
const int npcSize = 16;
const int monsterSize = 2;

struct Monster {
    string name;
    float hp, damage, rate, exp;
};

const Monster boss1 = {"Grief", 105, 11, 75, 15};
const Monster boss2 = {"Anxiety", 159, 23, 75, 20};
const Monster boss3 = {"Diseases", 213, 32, 75, 25};
const Monster boss4 = {"Old Age", 274, 41, 75, 30};
const Monster boss5 = {"Fear", 339, 48, 75, 35};
const Monster boss6 = {"Hunger", 419, 57, 75, 40};
const Monster boss7 = {"Need", 495, 66, 75, 45};
const Monster boss8 = {"Death", 575, 76, 75, 50};
const Monster boss9 = {"Agony", 683, 86, 75, 55};
const Monster boss10 = {"Nightmare", 790, 109, 75, 60};
const Monster boss11[2] = {{"Hades(calm)", 895, 121, 75, 65}, {"Hades(angry)", 1238, 181, 100, 70}};

const Monster monsters[monsterSize] = {{"Monster", 10, 2, 60, 2}, {"Monster (enchanted)", 15, 3, 65, 4}};

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

const string Charon[npcSize] = {
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
    "                           ( ___  )                ",    //level 2 boss
    "           (`               /  @ {_/7_             ",    //burning
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
    "                           _____________           ",    //level 3 boss
    "                          /  _______ (             ",    //posioning
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
    "                        ____                        ",    //level 4 boss
    "                      .  __  `                      ",    //healing effect is half
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
    "                       .-.                         ",    //level 5 boss
    "                      /   \\                       ",    //hit rate drops / max.mp drops
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
    "             .---..__/\\    /\\  .---.              ",    //level 6 boss
    "            (,` \\       `./  -' .'` .)             ",    //hunger
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
    "                     /|                            ",    //level 7 boss
    "                  _./ |/|----------._              ",    //hp/mp is drained
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
    "                  .----.           .               ",    //level 8 boss
    "                 /   .--`.        //               ",    //
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
    "                            |                       ",    //level 9 boss
    "                           .-''--.   `.             ",    //bleeding
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
    "           ---.  .  -  -  .   .---                 ",    //boss 10
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

const string hades[npcSize] = {
    "                              , s#b.@##b.,# ,",
    "                       , @#b ^7#\",#Gsb 3##Q",
    "                     '@MWG#Q#ib,#@G'' @Q#Q@##,",
    "                       77###           ####bl#Q@",
    "                      @Nsmc    #p;Q   #@##@##75N#",
    "         b           .@###s#  ss#@S8G#b@@####@@Q##N",
    ",       8Q           ]####G8^@#M#X##b  3#@##W77%WWWW",
    "\"7##    :@b          '@###W#blf@     @@Q#\" ,##\"\"^\"\"\"",
    "  @b@m@#\"jb          \"@####5Nm@b@#s#$;## ;#   ;#m#mm",
    "  \'\%##b@M             @## b@##Qs#;###b  %  ,%b` ,ss,",
    "      ~^            ,*WC\%#W@##@###Q#^ ,3 ./  ;W^",
    "       @           @ ,      77@#b^`\"N @b N ;#\"    \'",
    "       $           @#    \'\"\"\"@b \"   \"      @Q    ,s#",
    "                  ,#W\"b   ,\%T@psso   \"   p  @p   # \%",
    "       'p       ,     ,     ,@Q,,,    p  b %p3W###b",
    "       :p  ,####b     \"@,Q##`    \"7####@ \" ;,##mm#@#",

};
#endif