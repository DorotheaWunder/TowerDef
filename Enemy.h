#pragma once
#include "character.h"

class Enemy
{
public:
    Enemy(const char* fileName, int x, int y, int width, int height, float scale, CharacterType type);
    ~Enemy();

    float speed;

private:
    Character character;

    int targetX;
    int targetY;
};