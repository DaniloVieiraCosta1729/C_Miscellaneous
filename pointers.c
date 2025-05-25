#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y = 45;
    int *ponteiro = &y;

    printf("%p %d \n", ponteiro, *ponteiro);

    *ponteiro = 14;

    printf("%p %d %p %p\n", ponteiro, *ponteiro, &y, &ponteiro);
    printf("%p", y);

    int *p; // define um ponteiro do tipo inteiro
    p = (int*) malloc(sizeof(int)); // 4 bytes; diz que o ponteiro p recebe o endereço de 32 bits de memória que foi alocado para receber um ponteiro para um inteiro.
    printf("\nNo momento, isso o ponteiro esta apontando para isso: %d", *p);
    *p = 42; // atribui o valor 42 no espaço de memória que tem endereço igual ao valor de p.

    printf("\nValor no ponteiro p: %p \nValor que esta salvo no endereco %p : %d \nEndereco do ponteiro p: %p", p, p, *p, &p);

    free(p);

    p = NULL;

    return 0;
}