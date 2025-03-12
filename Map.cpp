#include "Map.h"
#include "Terrain.h"
#include "Tile.h"

const float SCALE = 0.3f;
const int TILE_WIDTH = 256 * SCALE;
const int TILE_HEIGHT = 256 * SCALE;

Map::Map()
{
    CreateMap();
}

Map::~Map()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            delete grid[y][x];
        }
    }
}

void Map::InitializeGrid()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x] = nullptr;
        }
    }
}

void Map::PlaceTerrain()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x] = new Tile(x, y, GRASS);
        }
    }
}


void Map::PlaceCastle()
{
    int middleX = COL / 2;
    int middleY = ROW / 2;

    delete grid[middleX][middleY];
    grid[middleY][middleX] = new Tile(middleX, middleY, CASTLE);
}

void Map::CreateMap()
{
    InitializeGrid();
    PlaceTerrain();
    PlaceCastle();
}




void Map::Draw()
{
    for (int y = 0; y < ROW; y++)
    {
        for (int x = 0; x < COL; x++)
        {
            grid[y][x]->Draw();
        }
    }
}


