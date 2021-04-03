#ifndef ENV_H
#define ENV_H
#include <string>

const int map_height = 30;
const int map_width = 60;
const int map_maxTunnels = 1200;
const int maxLength = 10;

const int max_debuff = 12, max_buff = 2;    // these 2 + 8 is the min map size
const std::string allDebuffs[max_debuff] = {"Burning", "Freezing", "Blind",
                                            "Poison", "Hunger", "Bleeding", "Fear", "Nervous", "Wet", "Cursed",
                                            "Paralyzed", "Hallucination"};

const std::string allBuffs[max_buff] = {"Full", "Anger"};

const int max_role = 12;
const int max_race = 4;
const int max_gender = 2;
const std::string roleList[max_role] = {"Archeologist", "Barbarian",
                                        "Caveman/Cavewoman", "Healer", "Knight", "Monk", "Priest/Priestess",
                                        "Rogue", "Ranger", "Samurai", "Tourist", "Wizard"};

const std::string raceList[max_race] = {"human", "drawf", "elf", "orc"};
const std::string genderList[max_gender] = {"male", "female"};

const int maxNum = 99;
const int maxSpace = 50;

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red (Monster) */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan (NPC)*/
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black (Wall)*/
#define BOLDRED "\033[1m\033[31m"     /* Bold Red (fire)*/
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow (chest)*/
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#endif