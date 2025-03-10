#include "terrain.h"
#include "raylib.h"

Terrain::Terrain(const char* fileName, int x, int y, int width, int height, TerrainType type)
    : sprite(fileName, x, y, width, height), type(type)
{
    SetSourceRect();
}

Terrain::~Terrain() { }

void Terrain::SetSourceRect()
{
    Rectangle rects[] =
    {
        Rectangle{0, 0, 256, 384},
        Rectangle{256, 0, 256, 384},
        Rectangle{512, 0, 256, 384},
        Rectangle{768, 0, 256, 384},
        Rectangle{1024, 0, 256, 384},
        Rectangle{1280, 0, 256, 384},
        Rectangle{1536, 0, 256, 384},

    };

    sprite.sourceRect = rects[type];

    // sprite.sourceRect = Rectangle
    // {
    //     static_cast<float>(sprite.WIDTH * type),
    //     0.0f,
    //     static_cast<float>(sprite.WIDTH),
    //     static_cast<float>(sprite.HEIGHT)
    // };
}

void Terrain::Draw()
{
    sprite.Draw();
}

