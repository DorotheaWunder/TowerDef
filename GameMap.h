#pragma once
#include "Tile.h"
#include <memory>

class GameMap
{
public:
    static const int ROW = 10;
    static const int COL = 23;
    std::unique_ptr<Tile> grid[ROW][COL];

    GameMap();
    ~GameMap();

    void CreateMap();
    void DrawMap();

private:
    void PlaceTerrain();
    void PlaceCastle();
    void InitializeGrid();
};






