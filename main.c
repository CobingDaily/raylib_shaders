#include "raylib.h"
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define FPS 60

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib Application");

    Image image = LoadImage("resources/komaru.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    Shader shader = LoadShader(0, "resources/shake.fs");

    int tickLoc = GetShaderLocation(shader, "tick");
    int tick = 0;

    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        SetShaderValue(shader, tickLoc, &tick, SHADER_UNIFORM_INT);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginShaderMode(shader);
                DrawTexture(texture, 0, 0, WHITE);
            EndShaderMode();

        EndDrawing();

        tick = (tick + 1) % FPS;
    }

    UnloadShader(shader);
    UnloadTexture(texture);

    CloseWindow();

    return 0;
}
