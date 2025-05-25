#include <stdlib.h>
#include <stdio.h>

// malloc() nos dá um espaço de memória na heap. O tipo de ponteiro que usamos para acessar o espaço alocado por ela não importa, ela nos fornece um ponteiro void e nós escolhemos qual será o tipo do ponteiro.



// situação interessante sobre stack e sobre como os endereços são usados
void declaraVariavel()
{
    int numero;

    numero = 32;
}

/*
int * declaraRetornaVariavel()
{
    int numero = 10000;
    return &numero;
}
*/

int * declaraRetornaVariavel()
{
    int * numero;

    numero = (int *)malloc(sizeof(*numero));

    * numero = 42;

    return numero;
}

int main(int argc, char const *argv[])
{
    int * p;

    p = declaraRetornaVariavel(); // essa função é chamada, declara 'int numero', retorna o endereço de 'numero' que é guardado em p.

    printf("*p = %d\n", *p);

    declaraVariavel(); // a stack já liberou o espaço que havia sido usado para declaraRetornaVariavel() e printf(). Então essa função declaraVariavel() vai usar esse espaço, independentemente de estarmos ou não guardando o endereço de alguns desses bytes em variáveis da main frame.

    printf("*p = %d\n", *p);

    free(p);

    return 0;
}
