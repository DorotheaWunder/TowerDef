#include "raylib.h"
#include "sprites.h"

#pragma once

enum TerrainType
{
    SNOW,
    MOUNTAINS,
    CASTLE,
    FOREST,
    SWAMP,
    GRASS,
    WATER
};

class Terrain
{
public:
    TerrainType type;

    Terrain(const char* fileName, int x, int y, int width, int height, float scale,  TerrainType type);
    ~Terrain();

    void Draw();

private:
    Sprite sprite;
    void SetSourceRect();
};

