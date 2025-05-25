#include <stdio.h>

void swap(int * x, int * b) // depois vale a pena ver aquela implementação sem uma variável temporaria.
{
    int temp;
    temp = *x;
    *x = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;

    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("Swap(a,b)\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
