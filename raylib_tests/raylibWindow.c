#include <raylib.h>
#include <string.h>
#include <stdio.h>

void calculateCenter(char * text, int windowWidth, int windowHeight, int fontSize, int * width, int * height);

int main(int argc, char const *argv[])
{
    char msg[100];

    snprintf(msg, sizeof(msg),"Hello! The first argument passed to argv[] was: %s\n", argv[1]);

    int width;
    int height;
    int windowW = 1000;
    int windowH = 400;
    int font = 20;

    int cW = 30;
    int cH = 30;
    int directionW = 1;
    int directionH = 1;

    calculateCenter(msg, windowW, windowH, font, &width, &height);

    InitWindow(windowW, windowH, "just testing...");
    SetTargetFPS(50);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKPURPLE);
        DrawText(msg, width, height, font, WHITE);
        DrawCircle(cW, cH, 15, BLACK);

        if (cW >= (windowW - 15))
        {
            directionW = -1;
        } else if (cW <= 15)
        {
            directionW = 1;
        }

        if (cH >= (windowH - 15))
        {
            directionH = -1;
        } else if (cH <= 15)
        {
            directionH = 1;
        }
     
        cW += 5*directionW;
        cH += 10*directionH;

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

void calculateCenter(char * text, int windowWidth, int windowHeight, int fontSize, int * width, int * height)
{
    int textSize = strcspn(text, "\0 \n");
    *width = (windowWidth - textSize*10) / 2;
    *height = (windowHeight - fontSize) / 2;
}