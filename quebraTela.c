#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    HDC hdc = GetDC(NULL); // DC da tela inteira
    int screenX = GetSystemMetrics(SM_CXSCREEN);
    int screenY = GetSystemMetrics(SM_CYSCREEN);
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 500; i++) {
        int w = rand() % 200;
        int h = rand() % 200;
        int x = rand() % (screenX - w);
        int y = rand() % (screenY - h);
        int dx = rand() % (screenX - w);
        int dy = rand() % (screenY - h);

        // Copia uma parte da tela para outro lugar
        BitBlt(hdc, dx, dy, w, h, hdc, x, y, SRCCOPY);

        Sleep(30);
    }

    ReleaseDC(NULL, hdc);

    printf("x: %d \ny: %d\n", screenX, screenY);
    return 0;
}
