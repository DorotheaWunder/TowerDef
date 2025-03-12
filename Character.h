#pragma once
#include "sprites.h"
#include "GameObject.h"
#include "Target.h"


enum CharacterType
{
    DARK_KNIGHT,
    DARK_CRUSADER,
    DARK_PALADIN,
    DARK_RIDER,
    PLAYER_PALADIN,
    PLAYER_KING
};

class Character : public ITarget
{
public:
    Sprite sprite;

    Character(const char* fileName, int x, int y, int width, int height, float scale, CharacterType type);
    ~Character();

    void Update();//---probably into game manager later
    void MoveTo(int gridPosX, int gridPosY);

    std::pair<int, int> GetGridPosition() const override
    {
        return gameObject.GetObjectPosition();
    }

    TargetType GetTargetType() const override
    {
        switch (type)
        {
        case PLAYER_PALADIN:
            return TargetType::PLAYER;
        case PLAYER_KING:
            return TargetType::KING;
        default:
            return TargetType::NONE;
        }
    }


private:
    GameObject gameObject;
    CharacterType type;
    void SetSourceRect();
};