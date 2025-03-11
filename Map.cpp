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
            grid[y][x] = new Terrain
                (
                    "../Assets/Textures/Tiles/spritesheetMulti.png",
                                x * TILE_WIDTH,
                                y * TILE_HEIGHT,
                                256,
                                384,
                                SCALE,
                                GRASS
                );
        }
    }
}


void Map::PlaceCastle()
{
    int middleX = COL / 2;
    int middleY = ROW / 2;

    delete grid[middleX][middleY];

    grid[middleY][middleX] = new Terrain
    (
        "../Assets/Textures/Tiles/spritesheetMulti.png",
                    middleX * TILE_WIDTH,
                    middleY * TILE_HEIGHT,
                    256,
                    384,
                    SCALE,
                    CASTLE
    );
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


