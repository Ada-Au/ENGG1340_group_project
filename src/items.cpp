#include <iostream>
#include <string>
#include <vector>
#include "env.h"
#include "items.h"

using namespace std;

int findItem(string Name, items item[maxSpace])
{
    for (int i = 0; i < maxSpace; i++){
        if (Name == item[i].name)
            return i;
    }
    return -1;
}

//To-do:
// 1) input items after monster fighting / getting things on ground
// 2) update number of items
// 3) sort by time(new to old)
void updateItems(string Name, int N, char flag) // flag - A for adding, D for delet
{
    if (N > maxNum)
        N =  maxNum;

    if (flag = 'D')
        N = -N;

    if (findItem(Name, item) == -1){
        for (int i = 0; i < maxSpace; i++){
            if (item[i].name == ""){
                item[i].name = Name;
                item[i].num += N;
                break;                 
            }
        }    
    }
    else{
        item[findItem(Name, item)].num += N;
        if (item[findItem(Name, item)].num > maxNum)
            item[findItem(Name, item)].num = maxNum;
    }        
    
    for (int i = 0; i < maxSpace; i++)
        if (item[i].name != "")
            cout << "Name: " << item[i].name << " Num: " << item[i].num << '\n';
}