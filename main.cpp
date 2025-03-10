#include <iostream>
#include "raylib.h"
#include "sprites.h"
#include "Terrain.h"
#include "Character.h"

int main()
{
    InitWindow(1200, 800, "Tower Defence");
    SetTargetFPS(60);



    Terrain snow("../Assets/Textures/Tiles/spritesheetMulti.png", 100, 100, 256, 384, SNOW);
    Terrain grass("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, GRASS);

    Character hero("../Assets/Textures/Tiles/spritesheetMulti.png", 400, 100, 256, 384, PLAYER_PALADIN);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);



        snow.Draw();
        grass.Draw();
        hero.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
