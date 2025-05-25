#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vetor[10];
    int * ptr;

    vetor[0] = 2;
    vetor[1] = 4;
    ptr = vetor;

    printf("Tamanho vetor %zu\n", sizeof(vetor));
    printf("*ptr = %d\n", *ptr);
    printf("*(vetor + 1) = %d\n", *(vetor + 1));
    printf("vetor[1] = %d\n", vetor[1]);
    printf("*(\"vetor\" + 1) = %c\n", *("vetor" + 1));

    /*
    Esse decaimento de um array para um ponteiro é uma forma eficiente de usar a memória, pois isso evita o "overhead" que aconteceria na passagem (por valor) de um array para uma função. Esse decaimento permite que apenas o endereço para o primeiro elemento do array seja passado, ao invés de passarmos o array inteiro para que ele seja copiado para a stack frame da função que está recebendo-o. 
    */

    return 0;
}
