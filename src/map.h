#ifndef Map_h
#define Map_h
#endif

class Map
{
    public: 
    void Fill();                   // Creating Map

    public: 
    static int height;
    static int width;
    char** layout;         // The Walls on the map
};