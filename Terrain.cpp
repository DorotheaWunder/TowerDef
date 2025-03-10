#include "terrain.h"
#include "sprites.h"
#include "raylib.h"
#include <iostream>

Terrain::Terrain(const char* fileName, int x, int y, int width, int height, float scale, TerrainType type)
    : sprite(fileName, x, y, width, height, scale), type(type)
{
    SetSourceRect();
}

Terrain::~Terrain() { }

void Terrain::SetSourceRect()
{
    std::cout << "Setting source rect for terrain type: " << type << std::endl;

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
}

void Terrain::Draw()
{
    sprite.Draw();
}

