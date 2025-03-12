#include "character.h"
#include "raylib.h"

Character::Character(const char* fileName, int x, int y, int width, int height, float scale, CharacterType type)
    : gameObject(x,y), sprite(fileName, x, y, width, height, scale), type(type)
{
    SetSourceRect();
}

Character::~Character() { }

void Character::SetSourceRect()
{
    Rectangle rects[] =
    {
        Rectangle{0, 384, 256, 384},
        Rectangle{256, 384, 256, 384},
        Rectangle{512, 384, 256, 384},
        Rectangle{768, 384, 256, 384},
        Rectangle{1024, 384, 256, 384},
        Rectangle{1280, 384, 256, 384},
        Rectangle{1536, 384, 256, 384},

    };

    sprite.sourceRect = rects[type];
}

void Character::Update()
{
    auto position = gameObject.GetObjectPosition();
    const float SCALE = 0.3f;
    const int TILE_WIDTH = 256 * SCALE;
    const int TILE_HEIGHT = 256 * SCALE;

    sprite.destRect.x = position.second * TILE_WIDTH;
    sprite.destRect.y = position.first * TILE_HEIGHT;
}

void Character::MoveTo(int gridPosX, int gridPosY)
{
    gameObject.SetObjectPosition(gridPosX, gridPosY);
    Update();
}