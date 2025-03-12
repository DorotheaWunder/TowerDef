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

class Target : public  ITarget
{
public:
    Target(int x = 0, int y = 0, TargetType type = TargetType::NONE);

    std::pair<int,int> GetGridPosition() const override;
    TargetType GetTargetType() const override;

    void SetTarget(int x, int y, TargetType type);

private:
    std::pair<int, int> position;
    TargetType targetType;
};