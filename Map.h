#pragma once
#include "Terrain.h"
#include "raylib.h"


//----------------------------> maybe also have a tile class?
class Map
{
public:
    // static const int ROW = 23;
    // static const int COL = 11;

    static const int ROW = 10;
    static const int COL = 23;



    Map();
    ~Map();

    void CreateMap();
    void Draw();

private:
    Terrain* grid[ROW][COL];

    void PlaceTerrain();
    void PlaceCastle();
    void InitializeGrid();

};






