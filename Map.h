#pragma once
#include "Tile.h"
#include "raylib.h"

class Map
{
public:
    static const int ROW = 10;
    static const int COL = 23;

    Map();
    ~Map();

    void CreateMap();
    void DrawMap();

private:
    Tile* grid[ROW][COL];

    void PlaceTerrain();
    void PlaceCastle();
    void InitializeGrid();
};






