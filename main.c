#include "raylib.h"

#define WIDTH 800
#define HEIGHT 600

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib Application");
    SetTargetFPS(60);

    Image image = LoadImage("resources/komaru.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    Shader shader = LoadShader(0, "resources/h_reflect.fs");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginShaderMode(shader);
                DrawTexture(texture, 0, 0, WHITE);
            EndShaderMode();

        EndDrawing();

    }

    UnloadShader(shader);
    UnloadTexture(texture);

    CloseWindow();

    return 0;
}
