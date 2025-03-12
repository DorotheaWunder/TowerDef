#include <iostream>
#include "raylib.h"
#include "Terrain.h"
#include "Map.h"
#include "Character.h"
#include "pathfinding.h"

int main()
{
    InitWindow(1800, 900, "Tower Defence");
    SetTargetFPS(60);

    Map gameMap;

    bool pathGenerated = false;
    Pathfinding pathfinder(Map::ROW - 1 , Map::COL -1);

    int startX = 0, startY = 0;

    Target castleTarget(Map::COL/2, Map::ROW/2, TargetType::CASTLE);

    Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 0, 0, 256, 384, 0.3f, PLAYER_PALADIN);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        gameMap.DrawMap();
        hero.sprite.Draw();

        if (!pathGenerated)
        {
            auto path = pathfinder.GenerateField(startX, startY, castleTarget);

            for (const auto& point : path)
            {
                DrawRectangle(
                point.second * 256,
                point.first * 256,
                256, 256,
                Color{255, 0, 0, 100}
                );
            }

            pathGenerated = true;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
