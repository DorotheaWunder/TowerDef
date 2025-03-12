#pragma once
#include <utility>

class GameObject
{
public:
    GameObject(int x, int y);

    std::pair<int, int> GetObjectPosition() const;
    void SetObjectPosition(int x, int y);

protected:
    std::pair<int, int> position;
};