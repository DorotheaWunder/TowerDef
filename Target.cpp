#include "target.h"

Target::Target(int x, int y, TargetType type)
        : position{x, y}, targetType(type) {}

std::pair<int, int> Target::GetGridPosition() const {return position; }

TargetType Target::GetTargetType() const { return targetType; }

void Target::SetTarget(int x, int y, TargetType type)
{
        position = {x, y};
        targetType = type;
}