#include <raylib.h>

void Dbutton(char * text, int font, int x, int y);

int main(int argc, char const *argv[])
{
    InitWindow(900, 500, "Janela com botão");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(CLITERAL(Color){40,50,100,1});

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}

void Dbutton(char * text, int font, int x, int y)
{
    
    BeginDrawing();

    EndDrawing();
}

