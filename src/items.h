#ifndef Item_h
#define Item_h
#include <iostream>

using namespace std;

struct items{
    string name = "";
    int num = 0;
};
items item[maxSpace];

void updateItems(string Name, int N, char flag);

#endif;