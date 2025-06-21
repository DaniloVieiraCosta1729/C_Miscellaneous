#include <stdio.h>
#include <stdlib.h>
#include "../resources/arith.h"
void calc(char c, int x, int y);

int main(int argc, char const *argv[])
{
    // vamos mostrar uma mensagem que informa como usar o programa no caso do usuário digitar uma quantidade errada de entradas.
    if (argc != 4)
    {
        printf("Way to use: %s <op> <num> <num>\n <op> in {a, s, m, d}\n", argv[0]);
    }

    char operation = argv[1][0];
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    
    calc(operation, x, y);

    return 0;
}
