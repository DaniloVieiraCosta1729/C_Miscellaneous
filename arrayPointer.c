#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // array
    int inteiros[10]; //cria um array com 10 inteiros na main stack frame, na ram. Basicamente, são 10 * 4 bytes consecutivos na stack.

    inteiros[0] = 1;
    inteiros[1] = 2;
    inteiros[2] = 3;

    printf("Valor de \"inteiros\"=%p\nValor de \"&inteiros[0]\"=%p", inteiros, &inteiros[0]); // inteiros contém o endereço do primeiro elemento do array inteiros.

    // array falso
    int * ptr = alloca(sizeof(int) * 10); // alloca() é uma macro que, diferentemente de malloc() que aloca espaço na heap, aloca espaço na stack frame onde é chamada. A memória alocada por ela é liberada sozinha quando a stack frame onde ela está for desempilhada. 

    *ptr = 1;
    *(ptr + 1) = 2;
    *(ptr + 2) = 3;

    // vamos printar os valores
    for (int i = 0; i < 10; i++)
    {
        printf("\narray[%d] = %d ------ ponteiro + alloca em %d = %d\n", i, inteiros[i], i, *(ptr + i));
    }


    printf("Comparando tamanhos:\n");
    printf("Tamanho array = %zu\nTamanho de ptr = %zu", sizeof(inteiros), sizeof(ptr));

    // Aritimética de ponteiros com o identificador do array e com o ponteiro para o endereço do array. 

    printf("\n&inteiros = %p --------- inteiros = %p\n", &inteiros, inteiros);
    printf("&inteiros + 1 = %p --------- inteiros + 1 = %p\n", &inteiros + 1, inteiros + 1);
    printf("&inteiros + 2 = %p --------- inteiros + 2 = %p\n", &inteiros + 2, inteiros + 2);

    // com o experimento acima, foi possível ver que &inteiros é um ponteiro do tipo (array de int), mas inteiros é (decai para) um ponteiro do tipo int e, portanto, têm tamanhos diferentes, o que impacta na aritmética de ponteiros sobre eles.
    // o mesmo vale para &ptr e ptr. O ponteiro ptr é para inteiros e &ptr, para ponteiros, então a aritmética com cada um será diferente.
    
    return 0;
}
