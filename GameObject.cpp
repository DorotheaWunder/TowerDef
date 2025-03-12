#include "GameObject.h"

GameObject::GameObject(int x, int y)
    : position(x,y) {}

std::pair<int, int> GameObject::GetObjectPosition() const
{
    return position;
}

void GameObject::SetObjectPosition(int x, int y)
{
    position = {x, y};
}
