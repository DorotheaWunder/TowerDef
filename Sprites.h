#pragma once
#include "raylib.h"
#include <string>

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
    std::string texturePath;
    Texture2D texture;
};



