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

    Target target();


    Terrain castleTarget("../Assets/Textures/Tiles/spritesheetMulti.png", 1400, 100, 256, 384, 0.3f, CASTLE);
    Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f, PLAYER_PALADIN);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        gameMap.Draw();

        // castleTarget.Draw();
        // hero.Draw();

//         if (!pathGenerated)
//         {
// //
//
//             pathfinder.GenerateField(startX, startY, targetPosition.first, targetPosition.second);
//             pathGenerated = true;
//         }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
