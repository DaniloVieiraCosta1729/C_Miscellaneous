#include <stdio.h>

int power(int x, int n)
{
    if (n == 1)
    {
        return x;
    }
    
    return x * power(x, n - 1);
}

int main(int argc, char const *argv[])
{
    int (* exp)(int, int) = power;
    
    printf("2 ^ 4 = %d\n", exp(2, 4));
    printf("3 ^ 3 = %d\n", (*exp)(3,3));

    return 0;
}
