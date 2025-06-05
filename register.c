int main(int argc, char const *argv[])
{
    register int num1 = 3; // uma registrador disponível vai receber 3 e vai ficar com ele na memória. Isso vai acelerar as operações, porque o processador não vai precisar buscar o 3 na RAM, pois ele já está no registrador.

    int a = num1 + 1;
    int b = num1 - 1;

    int c = a + b;

    return 0;
}

// lá na linha 19 do arquivo register.s é possível ver o registrador %ebx recebendo o 3.
