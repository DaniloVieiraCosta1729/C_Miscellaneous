#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    char *pc;

    c = 'a';
    pc = &c;

    printf("%p \n%p \n%p \n%p\n", pc, pc + 1, pc + 2, pc + 3);
    // a cada incremento de 1 em pc, o endereço mostrado é do byte em uma posição acima.
    // pc está em 0000002a241ffc77;   pc + 1 está em 0000002a241ffc78;

    //Se usarmos int ao invés de char, pc + 1 vai estar 4 bytes após pc, pois um int tem 4 bytes. 
    // pinter + n = endereço + n * sizeof(type)

    printf("%p \n%p \n%p \n%p \n", pc, (short *)pc + 1, (int *)pc + 2, (long *)pc + 3);

    return 0;
}
