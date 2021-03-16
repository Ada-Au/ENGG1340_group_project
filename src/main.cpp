#include "map.h"
#include <iostream>

void WaitKey(char& key) 
{
    std::cin>>key;
}

int main()
{   
    char key=' ';
    bool quit=false;
    Map map;

    map.Fill();
    for (int h = 0; h < 20; h++)
    {
        for (int w = 0; w < 20; w++)
        {
            std::cout <<  map.layout[h][w];
        }
        std::cout << std::endl;
    }
    return 0;
}