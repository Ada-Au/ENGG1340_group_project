#ifndef Homepage_h
#define Homepage_h

#include "backpack.h"
#include "env.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

const string homepage[10] =
    {
        "WWW              WWW   HHH         HHH        AAAA     TTTTTTTTTTTTTTTTT             AAAA                   HHH         HHH   EEEEEEEEEEEEE   LLL           LLL          ",
        "WWW              WWW   HHH         HHH     AAA    AAA        TTTTT                AAA    AAA                HHH         HHH   EEE             LLL           LLL          ",
        "WWW              WWW   HHH         HHH    AAA      AAA       TTTTT               AAA      AAA               HHH         HHH   EEE             LLL           LLL          ",
        "WWW              WWW   HHHHHHHHHHHHHHH   AAA        AAA      TTTTT              AAA        AAA              HHHHHHHHHHHHHHH   EEEEEEEEEE      LLL           LLL          ",
        "WWW     WWW      WWW   HHHHHHHHHHHHHHH   AAAAAAAAAAAAAA      TTTTT              AAAAAAAAAAAAAA              HHHHHHHHHHHHHHH   EEEEEEEEEE      LLL           LLL          ",
        "WWW     WWW      WWW   HHH         HHH   AAA        AAA      TTTTT              AAA        AAA              HHH         HHH   EEE             LLL           LLL          ",
        " WWW WWW   WWW  WWW    HHH         HHH   AAA        AAA      TTTTT              AAA        AAA              HHH         HHH   EEE             LLL           LLL          ",
        "  WWWW        WWWW     HHH         HHH   AAA        AAA      TTTTT              AAA        AAA              HHH         HHH   EEEEEEEEEEEEE   LLLLLLLLLLLL  LLLLLLLLLLLL ",
};

void menu(bool &, Player &, vector<Item> &);

#endif