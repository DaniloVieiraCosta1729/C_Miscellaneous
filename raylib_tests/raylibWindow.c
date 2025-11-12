#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define W 0
#define S 2
#define D 4
#define A 8

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
    int mousex;
    int mousey;
    float d;

    Vector2 alpha = {30.0, 30.0};
    Vector2 alphaVersor = {1.0, 1.0};
    Vector2 eVersor;

    calculateCenter(msg, windowW, windowH, font, &width, &height);

    InitWindow(windowW, windowH, "just testing...");
    SetTargetFPS(50);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        windowH = GetScreenHeight();
        windowW = GetScreenWidth();
        calculateCenter(msg, windowW, windowH, font, &width, &height);

        ClearBackground(DARKPURPLE);
        
        Vector2 mousePosicao = GetMousePosition();
        mousex = mousePosicao.x;
        mousey = mousePosicao.y;

        DrawCircle(mousex, mousey, 30, YELLOW);

        DrawCircle(alpha.x, alpha.y, 15, BLACK);

        if (alpha.x >= (windowW - 15))
        {
            alphaVersor.x = -1;
        } else if (alpha.x <= 15)
        {
            alphaVersor.x = 1;
        }

        if (alpha.y >= (windowH - 15))
        {
            alphaVersor.y = -1;
        } else if (alpha.y <= 15)
        {
            alphaVersor.y = 1;
        }

        d = sqrt((double)((mousex - alpha.x)*(mousex - alpha.x) + (mousey - alpha.y)*(mousey - alpha.y))); 
        
        if (d < 45)
        {
            eVersor.x = (alpha.x - mousex) / d;
            eVersor.y = (alpha.y - mousey) / d;

            alphaVersor.x = alphaVersor.x * eVersor.x;
            alphaVersor.y = alphaVersor.y * eVersor.y;         
        }
     
        alpha.x += 10*alphaVersor.x;
        alpha.y += 10*alphaVersor.y;

        int tecla;

        if (IsKeyReleased(KEY_A))
        {
            alphaVersor.x = -1;
            tecla = A;
        }
        if (IsKeyReleased(KEY_W))
        {
            alphaVersor.y = -1;
            tecla = W;
        }
        if (IsKeyReleased(KEY_S))
        {
            alphaVersor.y = 1;
            tecla = S;
        }
        if (IsKeyReleased(KEY_D))
        {
            alphaVersor.x = 1;
            tecla = D;
        }

        switch (tecla)
        {
        case A:
            DrawText("Tecla A", width, height, font, WHITE);
            break;

        case S:
            DrawText("Tecla S", width, height, font, WHITE);
            break;

        case W:
            DrawText("Tecla W", width, height, font, WHITE);
            break;

        case D:
            DrawText("Tecla D", width, height, font, WHITE);
            break;
        
        default:
            break;
        }
        
        

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

void calculateCenter(char * text, int windowWidth, int windowHeight, int fontSize, int * width, int * height)
{
    int textSize = strcspn(text, "\0 \n");
    *width = (windowWidth - textSize) / 2;
    *height = (windowHeight - fontSize) / 2;
}