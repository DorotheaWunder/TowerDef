#include "GameMap.h"
#include "Terrain.h"
#include "Tile.h"
#include <memory>

const float SCALE = 0.3f;
const int TILE_WIDTH = 256 * SCALE;
const int TILE_HEIGHT = 256 * SCALE;

GameMap::GameMap()
{
    CreateMap();
}

GameMap::~GameMap()
{ }

void GameMap::InitializeGrid()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x] = nullptr;
        }
    }
}

void GameMap::PlaceTerrain()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x] = std::make_unique<Tile>(x, y, GRASS);
        }
    }
}


void GameMap::PlaceCastle()
{
    int middleCol = COL / 2;
    int middleRow = ROW / 2;
    
    grid[middleRow][middleCol] = std::make_unique<Tile>(middleCol, middleRow, CASTLE);
}

void GameMap::CreateMap()
{
    InitializeGrid();
    PlaceTerrain();
    PlaceCastle();
}




void GameMap::DrawMap()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x]->terrain->sprite.Draw();
        }
    }
}


