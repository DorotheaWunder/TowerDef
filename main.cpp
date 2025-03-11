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
    int endX = Map::ROW, endY = Map::COL;


    // Terrain snow("../Assets/Textures/Tiles/spritesheetMulti.png", 100, 100, 256, 384, 0.3f, SNOW);
    Terrain grass("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  SWAMP);
    //
    Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  PLAYER_PALADIN);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);


        gameMap.Draw();

        if (!pathGenerated)
        {
            pathfinder.GenerateField(startX, startY, endX, endY);
            pathGenerated = true;
        }

        // snow.Draw();
        // grass.Draw();
        // hero.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
