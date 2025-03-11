#include "Map.h"
#include "Terrain.h"
#include "raylib.h"
#include <iostream>

const float SCALE = 0.3f;
const int TILE_WIDTH = 256 * SCALE;
const int TILE_HEIGHT = 256 * SCALE;
//const int TILE_HEIGHT = 384 * SCALE;

Map::Map()
{
    Initialize();
}

Map::~Map()
{
    for (int y = 0; y < COL; y++)
    {
        for (int x = 0; x < ROW; x++)
        {
            delete grid[x][y];
        }
    }
}

void Map::Initialize()
{
    for (int y = 0; y < COL; y++)
    {
        for (int x = 0; x < ROW; x++)
        {
            grid[x][y] = new Terrain
            ("../Assets/Textures/Tiles/spritesheetMulti.png",
            x * TILE_WIDTH,
            y * TILE_HEIGHT,
            256,
            384,
            SCALE,
            GRASS);


            if (grid[x][y] == nullptr)
            {
                std::cerr << "Failed to allocate memory for terrain at (" << x << ", " << y << ")" << std::endl;
            }
        }
    }
}

void Map::Draw()
{
    for (int y = 0; y < COL; y++)
    {
        for (int x = 0; x < ROW; x++)
        {
            grid[x][y]->Draw();
        }
    }
}


