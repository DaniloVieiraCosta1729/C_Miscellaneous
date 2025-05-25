#include <stdio.h>

void changeValue_withoutPointer(int nb);

void changeValue_forReal(int * nb);

int main(int argc, char const *argv[])
{
    int nb = 42;

    changeValue_withoutPointer(nb);

    printf("%d\n", nb);

    changeValue_forReal(&nb);

    printf("%d\n", nb);

    return 0;
}

void changeValue_withoutPointer(int nb) // em um espaço de memória separado de main(); Ela copia o valor de nb de main para uma nova variavel.
{
    nb = 1000;
}

void changeValue_forReal(int * nb) // as operações são feitas sobre a variável real em main();
{
    *nb = 1000; // um ponteiro costuma ter 8 bytes de espaço (maior que a nossa variável)
}
