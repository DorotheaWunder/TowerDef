#pragma once
#include "Terrain.h"
#include "raylib.h"

class Map
{
public:
    static const int ROW = 5;
    static const int COL = 5;

    Map();
    ~Map();

    void Initialize();
    void Draw();


private:
    Terrain* grid[ROW][COL];
};






