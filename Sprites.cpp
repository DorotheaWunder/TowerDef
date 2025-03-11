#include "sprites.h"
#include "raylib.h"
#include "ResourceManager.h"
#include <iostream>

Sprite::Sprite(const char* fileName, int x, int y, int width, int height, float scale)
    : texturePath(fileName)
{
    texture = TextureManager::GetInstance().GetTexture(texturePath);

    if (texture.id == 0)
    {
        std::cerr << "Failed to load texture: " << fileName << std::endl;
    }

    sourceRect = {0,0,(float)texture.width, (float)texture.height};
    destRect =
        {
            (float)x,
            (float)y,
            (float)width * scale,
            (float)height * scale
        };
}

Sprite::~Sprite()
{
    TextureManager::GetInstance().UnloadTexture(texturePath);
}

void Sprite::Draw()
{
    DrawTexturePro(texture, sourceRect, destRect, {0,0}, 0.0f, WHITE);
}

