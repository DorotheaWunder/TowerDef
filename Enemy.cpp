#include "character.h"
#include "raylib.h"
#include "enemy.h"

Enemy::Enemy(const char* fileName, int x, int y, int width, int height, float scale, CharacterType type)
    : character(fileName, x, y, width, height, scale, type), targetX(x), targetY(y), speed(1.5f)
{ }

Enemy::~Enemy() { }
