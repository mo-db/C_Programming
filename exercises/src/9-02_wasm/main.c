//#include <raylib.h>
#include "raylib-5.0_macos/include/raylib.h"

int main()
{
    InitWindow(800, 600, "Hello, from WASM!");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}