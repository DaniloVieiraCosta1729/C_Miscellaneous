#include <stdio.h>
#include <windows.h>

#define condicao (min < 0 || s < 0 || min > 59 || s > 59 || (min == 0 && s == 0))

int main(int argc, char const *argv[])
{
    int min, s, sTotal;
    printf("Por favor, informe os minutos e segundos, nessa ordem: ");
    scanf("%d %d", &min, &s);

    //tratamento
    while (condicao)
    {
        printf("\nA entrada é invalida. Tente novamente: ");
        scanf("%d %d", &min, &s);
    }
    
    sTotal = 60 * min + s;

    do
    {
        system("cls");
        printf("%d min %d s\n", min, s);
        Sleep(1000);
        sTotal--;
        min = sTotal / 60;
        s = sTotal % 60;
    } while (sTotal >= 0);

    printf("Imagine o Gollum falando: Acabou o Tempo.");
    for (size_t i = 0; i < 5; i++)
    {
        Beep(600, 200);
        Sleep(200);
    }

    Beep(800, 1000);

    return 0;
}
