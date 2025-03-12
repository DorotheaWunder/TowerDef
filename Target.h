#pragma once
#include <utility>

enum class TargetType
{
    NONE,
    CASTLE,
    KING,
    PLAYER,
    ENEMY,
    RESOURCE
};

class ITarget
{
public:
    virtual ~ITarget() = default;
    virtual std::pair<int, int> GetGridPosition() const = 0;
    virtual TargetType GetTargetType() const = 0;
};

class Target
{
public:
    Target(int x, int y, TargetType type);
    std::pair<int,int> GetGridPosition() const;
    TargetType GetTargetType() const;
    void SetTarget(int x, int y, TargetType type);

private:
    std::pair<int, int> position;
    TargetType targetType;
};