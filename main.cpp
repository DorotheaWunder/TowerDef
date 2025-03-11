#include <iostream>
#include "raylib.h"
#include "Terrain.h"
#include "Map.h"
#include "Character.h"

int main()
{
    InitWindow(1800, 900, "Tower Defence");
    SetTargetFPS(60);

    Map gameMap;

    // Terrain snow("../Assets/Textures/Tiles/spritesheetMulti.png", 100, 100, 256, 384, 0.3f, SNOW);
    // Terrain grass("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  CASTLE);
    //
    // Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  PLAYER_KING);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        gameMap.Draw();

        // snow.Draw();
        // grass.Draw();
        // hero.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
