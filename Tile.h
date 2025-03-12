#pragma once
#include <memory>
#include "GameObject.h"
#include "Terrain.h"


class Tile
{
public:
    Tile(int x, int y, TerrainType terrain, bool isWalkable = true);

    std::unique_ptr<Terrain> terrain;
    bool isWalkable;
    std::unique_ptr<GameObject> content;

    bool CheckWalkable() const;
    bool CheckContent() const;
    void PlaceContent(std::unique_ptr<GameObject> newContent);
    void RemoveContent();
};