#include <iostream>
#include "raylib.h"
#include "sprites.h"

int main()
{
    InitWindow(1200, 800, "Tower Defence");

    Sprite test("assets/textures/tiles/Tileset.png", 100,100, 256, 256);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);



        test.Draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}