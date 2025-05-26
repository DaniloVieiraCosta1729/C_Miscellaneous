#include <stdio.h>

// Se passamos o nome de uma função sem '(', então esse nome é entendido como o endereço da instrução 0 da função que está armazenada em .text. 

/*
|   stack   |
|   heap    |
|   .data   |
|   .text   |   <---- função está em .text
*/

int num()
{
    return 9;
}

// Exemplo de uso: uma função que escolhe qual função usar!

int soma(int x, int y);
int subtracao(int x, int y);
int multiplicacao(int x, int y);
int divisao(int x, int y);

int operacao(int x, int y, int (* code)(int, int))
{
    return code(x, y);
}

int main(int argc, char const *argv[])
{
    //printf("%p\n", num);

    int a = 2;
    int b = 3;

    printf("%d + %d = %d\n", a, b, operacao(a,b,soma));
    printf("%d - %d = %d\n", a, b, operacao(a,b,subtracao));
    printf("%d x %d = %d\n", a, b, operacao(a,b,multiplicacao));
    printf("%d / %d = %d\n", a, b, operacao(a,b,divisao));  
    
    return 0;
}

int soma(int x, int y)
{
    return x + y;
}

int subtracao(int x, int y)
{
    return x - y;
}

int multiplicacao(int x, int y)
{
    return x * y;
}

int divisao(int x, int y)
{
    return x / y;
}

