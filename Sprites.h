#pragma once
#include "raylib.h"

class Sprite
{
public:

    static const int WIDTH = 256;
    static const int HEIGHT = 384;

    Sprite(const char* fileName, int x, int y, int width, int height, float scale);
    ~Sprite();

    void Draw();

    Rectangle sourceRect;
    Rectangle destRect;

private:
    Texture2D texture;
};



