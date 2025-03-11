#pragma once
#include "Terrain.h"
#include "raylib.h"

class Map
{
public:
    static const int ROW = 23;
    static const int COL = 11;

    Map();
    ~Map();

    void Initialize();
    void PlaceCastle();
    void Draw();


private:
    Terrain* grid[ROW][COL];

    //void PlaceCastle();
};






