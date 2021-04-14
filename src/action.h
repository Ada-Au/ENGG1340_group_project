#ifndef Action_h
#define Action_h

#include "fight.h"
#include "map.h"
#include "screen.h"
#include "npc.h"

void action(Screen, Map, Player, Item[maxSpace], bool &);
void tryAgain(string, bool &);
void ending();

#endif