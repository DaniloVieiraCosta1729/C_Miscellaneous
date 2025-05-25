#include <stdio.h>

//pointer to a float
int main(int argc, char const *argv[])
{
    int nb, *ptr;

    nb = 42;
    ptr = &nb;

    printf("%d %0.60f \n", *ptr, *(float *)ptr); // estamos dizendo para o compilador mostrar o valor do tipo float (com 60 casas decimais) dentro do endereço de memória guardado em ptr.
    // (float *) apenas converte ptr de int * para float *.

    return 0;
}
