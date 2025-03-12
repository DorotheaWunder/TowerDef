#include "tile.h"
#include "Terrain.h"

Tile::Tile(int x, int y, TerrainType terrainType, bool isWalkable)
    : isWalkable(isWalkable), content(nullptr)
{
    const float SCALE = 0.3f;
    const int TILE_WIDTH = 256 * SCALE;
    const int TILE_HEIGHT = 256 * SCALE;

    terrain = std::make_unique<Terrain>(
        "../Assets/Textures/Tiles/spritesheetMulti.png",
        x * TILE_WIDTH,
        y * TILE_HEIGHT,
        256,
        384, // 256,
        SCALE,
        terrainType);
}

bool Tile::CheckWalkable() const
{
    return isWalkable;
}

bool Tile::CheckContent() const
{
    return  content != nullptr;
}

void Tile::PlaceContent(std::unique_ptr<GameObject> newContent)
{
    content = std::move(newContent);
}

void Tile::RemoveContent()
{
    content.reset();
}