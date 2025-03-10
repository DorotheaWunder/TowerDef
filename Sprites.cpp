#include "sprites.h"
#include "raylib.h"

Sprite::Sprite(const char* fileName, int x, int y, int width, int height)
{
    texture = LoadTexture(fileName);
    sourceRect = {0,0,(float)texture.width, (float)texture.height};
    destRect = { (float)x, (float)y, (float)width, (float)height};
}

Sprite::~Sprite()
{
    UnloadTexture(texture);
}

void Sprite::Draw()
{
    DrawTexturePro(texture, sourceRect, destRect, {0,0}, 0.0f, WHITE);
}

