#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0b1111;
    int b = 0b1010;

    printf("1111 & 1010 = %d\n", a & b);

    printf("1111 | 1010 = %d\n", a | b);

    printf("1111 << 3 = %d\n", a << 3);

    printf("1010 >> 2 = %d\n", b >> 2);

    printf("1010 ^ 1111 = %d\n", b ^ a);

    printf("~1010 = %d\n~1111 = %d\n", ~b, ~a);

    printf("~1010 & 1010 = %d\n~1111 & 1111 = %d\n", ~b & b, ~a & a);

    printf("~1010 | 1010 = %d\n~1111 | 1111 = %d\n", ~b | b, ~a | a);

    // Vamos pensar em umas forma de trocar os valores de duas variáveis sem usar uma variável temporaria.
    
    

    return 0;
}
