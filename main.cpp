#include <iostream>
#include "raylib.h"
#include "Terrain.h"
#include "Map.h"
#include "Character.h"

int main()
{
    InitWindow(1200, 800, "Tower Defence");
    SetTargetFPS(60);

    Map gameMap;

    // Terrain snow("../Assets/Textures/Tiles/spritesheetMulti.png", 100, 100, 256, 384, 0.3f, SNOW);
    // Terrain grass("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  GRASS);
    //
    // Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, 0.3f,  PLAYER_PALADIN);

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
