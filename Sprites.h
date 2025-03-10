#include "raylib.h"

#pragma once

class Sprite
{
public:
    Sprite(const char* fileName, int x, int y, int width, int height);
    ~Sprite();

    void Draw();
    void Unload();

private:
    Texture2D texture;
    Rectangle sourceRect;
    Rectangle destRect;
};



