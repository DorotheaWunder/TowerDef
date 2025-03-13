#include <iostream>
#include "raylib.h"
#include "Terrain.h"
#include "GameMap.h"
#include "Character.h"
#include "pathfinding.h"

int main()
{
    InitWindow(1800, 900, "Tower Defence");
    SetTargetFPS(60);

    GameMap gameMap;

    bool pathGenerated = false;
    Pathfinding pathfinder(GameMap::ROW - 1 , GameMap::COL -1, &gameMap);

    int startX = 0, startY = 0;

    Target castleTarget(GameMap::COL/2, GameMap::ROW/2, TargetType::CASTLE);

    Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 0, 0, 256, 384, 0.3f, PLAYER_PALADIN);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        gameMap.DrawMap();
        hero.sprite.Draw();

        auto path = pathfinder.GenerateField(startX, startY, castleTarget);

        for (const auto& point : path)
        {
            //pathfinder.ChangeTileColor(point.first, point.second, BLUE); // Mark path
        }

        pathGenerated = true;

        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
