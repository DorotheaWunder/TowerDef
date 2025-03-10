#pragma once
#include "sprites.h"



enum CharacterType
{
    DARK_KNIGHT,
    DARK_CRUSADER,
    DARK_PALADIN,
    DARK_RIDER,
    PLAYER_PALADIN,
    PLAYER_KING
};

class Character
{
public:
    Sprite sprite;

    Character(const char* fileName, int x, int y, int width, int height, float scale, CharacterType type);
    ~Character();

    void Draw();

private:
    CharacterType type;
    void SetSourceRect();
};