#include "raylib.h"

#define WIDTH 1200
#define HEIGHT 800

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib Application");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
