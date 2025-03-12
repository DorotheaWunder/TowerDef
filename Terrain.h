#include "raylib.h"
#include "sprites.h"
#include "Target.h"

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

class Terrain : public ITarget
{
public:
    TerrainType type;

    Terrain(const char* fileName, int x, int y, int width, int height, float scale,  TerrainType type);
    ~Terrain();

    void Draw();

    std::pair<int,int> GetGridPosition() const override
    {
        return
    {
        static_cast<int>(sprite.destRect.y / (256 * 0.3f)),
        static_cast<int>(sprite.destRect.x / (256 * 0.3f)),
        };
    }

    TargetType GetTargetType() const override
    {
        return type == CASTLE ? TargetType::CASTLE : TargetType::NONE;
    }


private:
    Sprite sprite;
    void SetSourceRect();
};

